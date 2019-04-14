import sys
import pyttsx3

def init_tts():
    engine = pyttsx3.init()
    return engine

def speak(phrase):
    engine.say(phrase)
    engine.runAndWait()

engine = init_tts()
speak(str(sys.argv[1]))
