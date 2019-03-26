edit:
	cd stockfish && $(MAKE)
	cd cutechess && qmake
	cd cutechess/gui && qmake
	cd cutechess/lib && qmake
	cd cutechess && make

clean:
	cd stockfish && $(MAKE) clean
	cd cutechess/gui && $(MAKE) clean
