import threading
import sys
import speech
import os
import snowboydecoder

from functools import partial

def main(comm):
	def show_messages():
		queue = comm.messages
		while True:
			if queue.message_count() > 0:
				print("New message: '{}'".format(queue.pop_message()))

	thrd = threading.Thread(target=show_messages)
	thrd.start()
	snowboy_umdl = os.path.join(os.path.split(os.path.realpath(__file__))[0], "resources/Gambit.pmdl")
	detector = snowboydecoder.HotwordDetector(snowboy_umdl, sensitivity=0.5, audio_gain=1)
	while True:
		try:
			detector.start(partial(speech.main, detector, comm))
		except speech.RestartSnowboy:
			continue
