import snowboydecoder

def detected_callback():
    print "hotword detected"
    # TODO: record the user and send to dialogflow


detector = snowboydecoder.HotwordDetector("resources/snowboy.umdl", sensitivity=0.5, audio_gain=1)
detector.start(detected_callback)
