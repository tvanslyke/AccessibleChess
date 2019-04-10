	
all: stockfish debug

# PYTHONLIB=$(shell python3 -c 'from distutils import sysconfig; print(sysconfig.get_config_var("BLDLIBRARY"))')
# PYTHONLIBPATH=$(shell python3 -c 'from distutils import sysconfig; print(sysconfig.get_config_var("LIBDEST"))')
# PYTHONINCLUDE=$(shell python3 -c 'from distutils import sysconfig; print(sysconfig.get_config_var("INCLUDEPY"))')

PROJECTPATH = $(shell pwd)
VOICE_ASSISTANT_PATH = $(PROJECTPATH)/speech
CXX=clang++
CXX_LINK=clang++

QMAKE=qmake QMAKE_CXX=$(CXX) QMAKE_LINK=$(CXX_LINK)

release:
	cd cutechess/build && cmake  -DCMAKE_BUILD_TYPE=Release ../
	cd cutechess/build && $(MAKE)
	cp cutechess/build/cutechess cutechess/
	# cd cutechess/gui && $(QMAKE)
	# cd cutechess/lib && $(QMAKE) DEFINES+="VOICE_ASSISTANT_PATH=\"$(VOICE_ASSISTANT_PATH)\""
	# cd cutechess && $(MAKE)

debug:
	cd cutechess/build && cmake -DCMAKE_BUILD_TYPE=Debug ../
	cd cutechess/build && $(MAKE)
	cp cutechess/build/cutechess cutechess/
	# cd cutechess && $(QMAKE) CONFIG+=debug
	# cd cutechess/gui && $(QMAKE) CONFIG+=debug
	# cd cutechess/lib && $(QMAKE) CONFIG+=debug DEFINES+="VOICE_ASSISTANT_PATH=\"$(VOICE_ASSISTANT_PATH)\""
	# cd cutechess && $(MAKE)

stockfish:
	cd stockfish && $(MAKE) build ARCH=$(ARCH)

clean-cutechess:
	cd cutechess && $(MAKE) clean
	
clean-stockfish:
	cd stockfish && $(MAKE) clean
	
clean: clean-stockfish clean-cutechess
	
