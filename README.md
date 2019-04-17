# AccessibleChess
Required Libraries:
* Python3
* cmake
* Qt
* Google Cloud SDK command line tools

Required Python Libraries:
* dialogflow
* Snowboy
* Pyaudio
* Pyttsx3
* Pyobjc

To get dialogflow and google speech to text working please request an
authentication json file from thornton.da@husky.neu.edu

To authenticate with dialogflow and google cloud
`gcloud auth activate-service-account --key-file <path-to-json-file>`

To build:
`make`

To run:
`./cutechess/cutechess`

# Commands
To start a new game you just say “New Game” or “Create Game.”  You can select which side you want to be on by saying “Set White to Human” or “Set White to CPU”. Once you are done you just say “ Done creating new game” or if you wish to cancel the creation of a new game you can say “ Cancel New Game”. Alternatively you can load a previously saved game by saying “Load Game”.

Once you are in a game you have several voice command options. To move a piece you say “move” and then say the square the piece is currently and then the square you wish to move the piece to. For example “Move C1 C2” or “Move A1 A2”. You can also query to voice assistant on the current status of the board. You can query what pieces are currently attacking a specific square on the board by saying “ Attackers for position A2” or just “Attackers A2”. You can query how many pieces have been captured by each side by asking “What is the taken material for each side?” And finally you can query what piece is on a specific square by asking “ What is the piece at A4?”.

At any point during the game you can save the current game or forfeit the game. To save the game you say “Save Game” and to forfeit the game you say “Forfeit Game”.


# Embedded Python Interpreter
The embedded Python interpreter runs on its own thread in the cutechess app.  When the interpreter is created, it adds the `speech/` directory to the module lookup path and then imports a module called `accessible_chess`.  From there, it looks for a `main()` function in the `accessible_chess` module and invokes it with a `PyComm` object as the only argument.  The `PyComm` object sends and receives signals from the cutechess app.  To send signals to the cutechess app, member functions such as `.make_move("a2 a4")` or `.resign_game()` are provide (see `help(pycomm_object)` for a list of all provided member functions).

Signals from cutechess can be accessed by through PyComm's `.messages` member.  This is a simple thread-safe queue of strings sent from the cutechess that exposes only two methods, `.message_count()` and `.pop_message()`.  These strings contain information about events that occur in cutechess.  For example, when a new default game is started, cutechess will add the string `'game_started: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1'`.  The `game_started: ` portion of the string tells you what kind of event occurred; in this case the message is telling us that a new game was started.  Everything after the color `: ` in the string is the "payload".  Its contents will depend on what kind of message was sent.  In this case it's a [FEN string](https://en.wikipedia.org/wiki/Forsyth%E2%80%93Edwards_Notation) encoding the initial position of the game.  Other messages will have different payload formats, or may have no payload at all.  For example, a message is added to the queue every time a move is made (by either player) in the current game.  This message will start with `"move_made: "` and then the payload will be the encoding of the move in [long algebraic notation](https://en.wikipedia.org/wiki/Algebraic_notation_\(chess\)#Long_algebraic_notation) (e.g. `"a2a4"`).

An example script in the `speech/` directory uses the PyComm object to make a simple text-based command line to control cutechess games.  If you run cutechess from a terminal, it should jump right into the command prompt.

All of the above can be changed as needed.  PyComm doesn't provide everything yet, but it can do enough to allow basic control of a cutechess game.

Note that Python3 C API was used for all of this; the CPython C API is a lot easier to work with in Python3 than in Python2.  If its really a problem, I can rewrite it for Python2 but I'd prefer not to if Python3 doesn't pose any real problems.

## Building Cutechess with the Embedded Python Interpreter
All of the QT `.pri` and `.pro` files should automatically find the necessary Python libraries on your system.  You'll need the `distutils` python package for it to work (it should be installed by default I think?).  You'll also need to have the Python development libraries installed on your system.  On linux this is usually packaged as libpython3-dev.  Supposedly on Mac and Windows this is packaged with Python itself so it should hopefully "just work".
