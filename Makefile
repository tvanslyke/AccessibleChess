edit:
	cd stockfish && $(MAKE) build ARCH=$(ARCH)
	cd cutechess && qmake
	cd cutechess/gui && qmake
	cd cutechess/lib && qmake
	cd cutechess && $(MAKE)

clean:
	cd stockfish && $(MAKE) clean
	cd cutechess/gui && $(MAKE) clean
