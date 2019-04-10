from __future__ import division
import dialogflow_v2 as dialogflow
import pyaudio
import re
import snowboydecoder
import sys

from functools import partial
from google.cloud import speech
from google.cloud.speech import enums
from google.cloud.speech import types
from six.moves import queue

import pyttsx3

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
    pyttsx3.say(s)
    pyttsx3.runAndWait()


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

            session = session_client.session_path('softwareengineering-236414', 1)
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

            intent = query_result.intent.display_name

            if chesscomm is None:
                # should only get here when 'speech.py' is invoked directly
                print("'chesscomm' is None: skipping")
                return

            if intent == 'Save Game':
                try:
                    chesscomm.save_game()
                except RuntimeError:
                    vocalize("Couldn't save game.  No game is currently being played.")
                else:
                    vocalize("Game saved.");
            elif intent == 'Move':
                try:
                    assert False, "'Move' intent not yet implemented."
                    chesscomm.make_move() # need a string like "a2 a4" or "a2a4"
                except ValueError as e:
                    if "No active game" in e.args[0]:
                        vocalize("Couldn't make move.  No game is currently being played.")
                    else:
                        vocalize("Requested move is illegal.")
                else:
                    vocalize("Move made.");
            elif intent == 'Resign':
                try:
                    chesscomm.resign_game()
                except RuntimeError:
                    vocalize("Couldn't resign game.  No game is currently being played.")
                else:
                    vocalize("Resigned game.");
            elif intent == 'New Game':
                try:
                    chesscomm.new_game()
                except RuntimeError:
                    vocalize("Couldn't start new game.  A game is currently being played.")
                else:
                    vocalize("New game started.");

def main(detector, chesscomm):
    pyttsx3.init()
    detector.terminate()
    print("hotword detected")
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
        listen_print_loop(responses, chesscomm)

if __name__ == '__main__':
    detector = snowboydecoder.HotwordDetector("resources/snowboy.umdl", sensitivity=0.5, audio_gain=1)
    detector.start(partial(main, detector, None))
