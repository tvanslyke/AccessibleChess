edit:
	cd stockfish && $(MAKE)
	cd cutechess && qmake
	cd cutechess && make

clean:
	cd stockfish && $(MAKE) clean
	cd cutechess/gui && $(MAKE) clean
