from __future__ import division
import dialogflow_v2 as dialogflow
import pyaudio
import re
import snowboydecoder
import sys
import uuid
import json
import os

class RestartSnowboy(Exception):
    pass

try:
    import pyttsx3
except ImportError:
    print("Couldn't import pyttsx3.  Install with 'python3 -m pip install pyttsx3 --user'.", file=sys.stderr)
    exit(-1)

from functools import partial
from google.cloud import speech
from google.cloud.speech import enums
from google.cloud.speech import types
from google.protobuf.json_format import MessageToJson
from six.moves import queue
from subprocess import call
import chess

ignore_audio = False

session_id = uuid.uuid4()

# Audio recording parameters
RATE = 16000
CHUNK = int(RATE / 10)  # 100ms

class DialogflowClient(object):
    """Opens a recording stream as a generator yielding the audio chunks."""
    def __init__(self, rate, chunk):
        self._rate = rate
        self._chunk = chunk

        # Create a thread-safe buffer of audio data
        self._buff = queue.Queue()
        self.closed = True

    def __enter__(self):
        self._audio_interface = pyaudio.PyAudio()
        self._audio_stream = self._audio_interface.open(
            format=pyaudio.paInt16,
            # The API currently only supports 1-channel (mono) audio
            # https://goo.gl/z757pE
            channels=1, rate=self._rate,
            input=True, frames_per_buffer=self._chunk,
            # Run the audio stream asynchronously to fill the buffer object.
            # This is necessary so that the input device's buffer doesn't
            # overflow while the calling thread makes network requests, etc.
            stream_callback=self._fill_buffer,
        )

        self.closed = False

        return self

    def __exit__(self, type, value, traceback):
        self._audio_stream.stop_stream()
        self._audio_stream.close()
        self.closed = True
        # Signal the generator to terminate so that the client's
        # streaming_recognize method will not block the process termination.
        self._buff.put(None)
        self._audio_interface.terminate()

    def _fill_buffer(self, in_data, frame_count, time_info, status_flags):
        """Continuously collect data from the audio stream, into the buffer."""
        if ignore_audio:
            return None, pyaudio.paContinue
        self._buff.put(in_data)
        return None, pyaudio.paContinue

    def generator(self):
        while not self.closed:
            # Use a blocking get() to ensure there's at least one chunk of
            # data, and stop iteration if the chunk is None, indicating the
            # end of the audio stream.
            chunk = self._buff.get()
            if chunk is None:
                return
            data = [chunk]

            # Now consume whatever other data's still buffered.
            while True:
                try:
                    chunk = self._buff.get(block=False)
                    if chunk is None:
                        return
                    data.append(chunk)
                except queue.Empty:
                    break

            yield b''.join(data)

def vocalize(s):
    global ignore_audio
    ignore_audio = True
    path = os.path.join(os.path.dirname(os.path.realpath(__file__)), "echo.py")
    try:
        print("Vocalizing: {}".format(repr(s)))
        call(["python3", path, s])
    finally:
        ignore_audio = False


def listen_print_loop(responses, chesscomm):
    """Iterates through server responses and prints them.

    The responses passed is a generator that will block until a response
    is provided by the server.

    Each response may contain multiple results, and each result may contain
    multiple alternatives; for details, see https://goo.gl/tjCPAU.  Here we
    print only the transcription for the top alternative of the top result.

    In this case, responses are provided for interim results as well. If the
    response is an interim one, print a line feed at the end of it, to allow
    the next result to overwrite it, until the response is a final one. For the
    final one, print a newline to preserve the finalized transcription.
    """
    num_chars_printed = 0
    for response in responses:
        if not response.results:
            continue

        # The `results` list is consecutive. For streaming, we only care about
        # the first result being considered, since once it's `is_final`, it
        # moves on to considering the next utterance.
        result = response.results[0]
        if not result.alternatives:
            continue

        # Display the transcription of the top alternative.
        transcript = result.alternatives[0].transcript

        # Display interim results, but with a carriage return at the end of the
        # line, so subsequent lines will overwrite them.
        #
        # If the previous result was longer than this one, we need to print
        # some extra spaces to overwrite the previous result
        overwrite_chars = ' ' * (num_chars_printed - len(transcript))

        if not result.is_final:
            sys.stdout.write(transcript + overwrite_chars + '\r')
            sys.stdout.flush()

            num_chars_printed = len(transcript)

        else:
            print(transcript + overwrite_chars)
            session_client = dialogflow.SessionsClient()

            session = session_client.session_path('softwareengineering-236414', session_id)
            print('Session path: {}\n'.format(session))

            text_input = dialogflow.types.TextInput(
                text=transcript + overwrite_chars, language_code='en')
            query_input = dialogflow.types.QueryInput(text=text_input)
            response = session_client.detect_intent(
                session=session, query_input=query_input)

            print('=' * 20)
            print('Query text: {}'.format(response.query_result.query_text))
            print('Detected intent: {} (confidence: {})\n'.format(
                response.query_result.intent.display_name,
                response.query_result.intent_detection_confidence))
            print('Fulfillment text: {}\n'.format(
                response.query_result.fulfillment_text))
            print('Responses: {}\n'.format(
                response.query_result.parameters))

            intent = response.query_result.intent.display_name
            msg = intent_dispatch(chesscomm, response, intent)
            if msg is not None:
                return msg

def intent_dispatch(chesscomm, response, intent):
    if chesscomm is None:
        # should only get here when 'speech.py' is invoked directly
        print("'chesscomm' is None: skipping")
        return
    elif intent == 'Save Game':
        try:
            chesscomm.save_game()
        except RuntimeError:
            return "Couldn't save game.  No game is currently being played."
        else:
            return "Game saved."
    elif intent == 'Load Game':
        if not chesscomm.is_creating_new_game():
            return "Cannot load game until a new game dialog is started."
        try:
            chesscomm.load_saved_game()
        except RuntimeError as e:
            print(e)
            return "Unable to load game."
        else:
            return "Game loaded."
    elif intent == 'Move':
        # don't catch exceptions from these two lines, if this fails we need to fix our code
        params = response.query_result.parameters

        movestr = " ".join([params["Column1"].lower(), params["Row1"].lower(), params["Column2"].lower(), params["Row2"].lower()])
        try:
            chesscomm.make_move(movestr)
        except ValueError as e:
            if "No active game" in e.args[0]:
                return "Couldn't make move.  No game is currently being played."
            else:
                return "Requested move is illegal."
        else:
            return "Move made."
    elif intent == 'Resign':
        try:
            chesscomm.resign_game()
        except RuntimeError:
            return "Couldn't resign game.  No game is currently being played."
        else:
            return "Resigned game."
    elif intent == 'New Game':
        if chesscomm.is_creating_new_game():
            return "Already creating new game.  Say accept new game or done creating new game to begin."
        try:
            chesscomm.new_game()
        except RuntimeError:
            return "Couldn't start new game.  A game is currently being played."
        else:
            return "What settings would you like?"
    elif intent == 'New Game Settings':
        params = response.query_result.parameters
        if not chesscomm.is_creating_new_game():
            return "Cannot change player settings after the game has started."
        try:
            chesscomm.set_player_type(params["ChessSide"], params["PlayerType"])
        except ValueError:
            vocalize("Something went wrong while changing player settings.  Try again?")
        else:
            return "Okay, set {} player to {}.".format(params["ChessSide"], params["PlayerType"])
    elif intent == 'Finish New Game':
        params = response.query_result.parameters
        action = params["AcceptOrCancel"]
        if action.lower() in {"accept", "done", "start", "finish"}:
            try:
                chesscomm.start_new_game()
            except ValueError:
                return "Can't start new game without choosing game settings."
            else:
                return "Okay, starting new game now."
        elif action.lower() in {"reject", "cancel"}:
            try:
                chesscomm.cancel_new_game()
            except ValueError:
                return "Can't cancel new game.  No new game is currently being created."
            else:
                return "Okay, the new game is cancelled."
        else:
            assert False
    elif intent == 'Query Attackers':
        if not chesscomm.active_game():
            return "No game is currently being played."
        fen = chesscomm.board_fen()
        params = response.query_result.parameters
        pos = params["Space"]
        attackers = chess.query_attackers(fen, pos)
        return ".  ".join(
            ("{} at {}".format(chess.name(piece), chess.indices_to_position(row, col)) for ((row, col), piece) in attackers)
        ) + "."
    elif intent == 'Query Material':
        if not chesscomm.active_game():
            return "No game is currently being played."
        fen = chess.DecodedFen(chesscomm.board_fen())
        material = chess.query_material(fen.board)
        black_points = 0
        white_points = 0
        white_pieces = ""
        black_pieces = ""
        for (piece, count) in material.items():
            if piece.lower() == piece and count:
                black_points += chess.material_values[piece] * count
                black_pieces += ", {} {}{}".format(count, chess.name(piece, include_color=False), "s" if count > 1 else "")
            elif count:
                white_points += chess.material_values[piece] * count
                white_pieces += ", {} {}{}".format(count, chess.name(piece, include_color=False), "s" if count > 1 else "")
        white_pieces = "no pieces" if not white_pieces else white_pieces
        black_pieces = "no pieces" if not black_pieces else black_pieces
        return "White has captured {} for a total of {} points and black has captured {} for a total of {} points.".format(
            black_pieces,
            black_points,
            white_pieces,
            white_points,
        )
    elif intent == 'Query Position':
        if not chesscomm.active_game():
            return "No game is currently being played."
        fen = chess.DecodedFen(chesscomm.board_fen())
        params = response.query_result.parameters
        pos = params["Space"]
        piece = chess.query_position(fen.board, pos)
        if not piece:
            return "Position {} is empty.".format(pos)
        else:
            return "{} {} occupies position {}.".format(
                "A" if piece not in "KkQq" else "The",
                chess.name(piece),
                pos
            )
    elif intent == "Default Fallback Intent":
        vocalize(response.query_result.fulfillment_text)
    return None

def main(detector, chesscomm):
    if detector is not None:
        detector.terminate()
    print("hotword detected")
    vocalize("I'm listening!")
    # See http://g.co/cloud/speech/docs/languages
    # for a list of supported languages.
    language_code = 'en-US'  # a BCP-47 language tag
    client = speech.SpeechClient()

    config = types.RecognitionConfig(
        encoding=enums.RecognitionConfig.AudioEncoding.LINEAR16,
        sample_rate_hertz=RATE,
        language_code=language_code)
    streaming_config = types.StreamingRecognitionConfig(
        config=config,
        interim_results=True)
    with DialogflowClient(RATE, CHUNK) as stream:
        audio_generator = stream.generator()
        requests = (types.StreamingRecognizeRequest(audio_content=content)
                    for content in audio_generator)
        responses = client.streaming_recognize(streaming_config, requests)
        # Now, put the transcription responses to use.
        speech_response = listen_print_loop(responses, chesscomm)
        vocalize(speech_response)
        raise RestartSnowboy()

if __name__ == '__main__':
    detector = snowboydecoder.HotwordDetector("resources/Gambit.pmdl", sensitivity=0.5, audio_gain=1)
    detector.start(partial(main, detector, None))
