	
all: stockfish debug

# PYTHONLIB=$(shell python3 -c 'from distutils import sysconfig; print(sysconfig.get_config_var("BLDLIBRARY"))')
# PYTHONLIBPATH=$(shell python3 -c 'from distutils import sysconfig; print(sysconfig.get_config_var("LIBDEST"))')
# PYTHONINCLUDE=$(shell python3 -c 'from distutils import sysconfig; print(sysconfig.get_config_var("INCLUDEPY"))')

PROJECTPATH = $(shell pwd)
VOICE_ASSISTANT_PATH = $(PROJECTPATH)/speech

release:
	cd cutechess && qmake
	cd cutechess/gui && qmake
	cd cutechess/lib && qmake DEFINES+="VOICE_ASSISTANT_PATH=\"$(VOICE_ASSISTANT_PATH)\""
	cd cutechess && $(MAKE)

debug:
	cd cutechess && qmake CONFIG+=debug
	cd cutechess/gui && qmake CONFIG+=debug
	cd cutechess/lib && qmake CONFIG+=debug DEFINES+="VOICE_ASSISTANT_PATH=\"$(VOICE_ASSISTANT_PATH)\""
	cd cutechess && $(MAKE)

stockfish:
	cd stockfish && $(MAKE) build ARCH=$(ARCH)

clean-cutechess:
	cd cutechess && $(MAKE) clean
	
clean-stockfish:
	cd stockfish && $(MAKE) clean
	
clean: clean-stockfish clean-cutechess
	
