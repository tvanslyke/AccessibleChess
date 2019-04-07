DEPENDPATH += $$PWD
HEADERS += $$PWD/voiceassistant.h \
	$$PWD/PyComm.h \
	$$PWD/MessageQueue.h \
	$$PWD/pyapi.h
SOURCES += $$PWD/voiceassistant.cpp \
	$$PWD/PyComm.cpp \
	$$PWD/MessageQueue.cpp

QT += widgets

INCLUDEPATH += $$PWD/../../../gui/src
