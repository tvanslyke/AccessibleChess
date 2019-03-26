edit:
	cd stockfish && $(MAKE) build ARCH=$(ARCH)
	cd cutechess/gui && $(MAKE)

clean:
	cd stockfish && $(MAKE) clean
	cd cutechess/gui && $(MAKE) clean
