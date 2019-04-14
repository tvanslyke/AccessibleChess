#include "voiceassistant.h"
#include "MessageQueue.h"
#include <Python.h>
#include <iostream>
#include <thread>
#include <atomic>
#include "cutechessapp.h"
#include "mainwindow.h"

#ifndef VOICE_ASSISTANT_PATH
# error "'VOICE_ASSISTANT_PATH' must be defined."
#endif /* VOICE_ASSISTANT_PATH */

// Stringify 'VOICE_ASSISTANT_PATH'. (VOICE_ASSISTANT_PATH is defined by a compiler flag)
#define MAKE_VOICE_ASSISTANT_STRING_HELPER(x) #x
#define MAKE_VOICE_ASSISTANT_STRING(x) MAKE_VOICE_ASSISTANT_STRING_HELPER(x)

using namespace py;

GILMutex VoiceAssistant::gil_mutex{};
pyobject_ptr<> VoiceAssistant::accessible_chess_module{nullptr};

VoiceAssistant::VoiceAssistant():
	game_(nullptr),
	py_comm_(nullptr),
	python_thread_()
{
	std::atomic<bool> is_ready(false);
	python_thread_ = std::thread([&is_ready](VoiceAssistant* va) {
		try {
			VoiceAssistant::init_python_interpreter();
			// Acquire the GIL.
			std::lock_guard<GILMutex> hold_(gil_mutex);
			// Find the accessible_chess.py module's main() function.
			pyobject_ptr<> main_fn(PyObject_GetAttrString(accessible_chess_module.get(), "main"));
			check_python_exceptions();
			assert(main_fn); // shouldn't happen, an exception ought to have been set if this is null
			assert(PyFunction_Check(main_fn.get()) && "accessible_chess.main is not a function!");
			// Create a new PyComm Python object by invoking the associated type object
			va->py_comm_.reset(static_cast<PyComm*>(PyObject_CallFunctionObjArgs(
				reinterpret_cast<PyObject*>(&PyComm::python_type),
				static_cast<PyObject*>(nullptr)
			)));
			check_python_exceptions();
			assert(va->py_comm_);
			va->py_comm_->initialize(va);
			pyobject_ptr<> pycomm(copy_ref(va->py_comm_));
			is_ready = true;
			// Invoke 'accessible_chess.main()' with the PyComm object.
			static_cast<pyobject_ptr<>>(
				PyObject_CallFunctionObjArgs(main_fn.get(), pycomm.get(), static_cast<PyObject*>(nullptr))
			);
			check_python_exceptions();
		} catch(const PythonException& e) {
			std::cerr << "Unhandled Python exception:" << std::endl;
			std::cerr << e.what() << std::endl;
			std::terminate();
		} catch(const std::exception& e) {
			std::cerr << "Unhandled C++ exception:" << std::endl;
			std::cerr << e.what() << std::endl;
			std::terminate();
		}
	}, this);
	// wait for initialization of 'py_comm_'
	while(not is_ready) {
		std::this_thread::yield();
	}
}

VoiceAssistant::~VoiceAssistant() {
	python_thread_.join();
}


Chess::Board* VoiceAssistant::board() const {
	return game_ ? game_->board() : nullptr;
}

MainWindow* VoiceAssistant::game_window() const {
	// Get the game window associated with 'this->game()'.
	auto windows = CuteChessApplication::instance()->gameWindows();
	if(not game()) {
		return nullptr;
	}
	for(auto window: windows) {
		if(window->game() == game()) {
			return window;
		}
	}
	return nullptr;
}

ChessGame* VoiceAssistant::game() const {
	return game_;
}

py::MessageQueue& VoiceAssistant::outgoing_messages() const {
	assert(py_comm_);
	assert(py_comm_->outgoing_messages);
	return *py_comm_->outgoing_messages;
}

void VoiceAssistant::init_python_interpreter() {
	static std::once_flag flag;
	std::call_once(flag, initialize_python_interpreter);
}

void VoiceAssistant::set_game(ChessGame* new_game) {
	// When we start a new game, a bunch of signals need to be disconnected from the old
	// game and then connected again to the new one.  We do all of that here, except for
	// when the new game's window hasn't been created yet (we need some of signals from
	// the associated MainWindow object).  In that case, wait for the game to emit our 
	// gameWindowCreated() signal, and then finish connecting the signals.

	if(game()) {
		// Disconnect the old game.
		auto white_player = game()->player(Chess::Side::White);
		auto black_player = game()->player(Chess::Side::Black);
		if(auto as_human = dynamic_cast<HumanPlayer*>(white_player)) {
			disconnect(this, &VoiceAssistant::humanMoveMade, as_human, &HumanPlayer::onHumanMove);
		}
		if(auto as_human = dynamic_cast<HumanPlayer*>(black_player)) {
			disconnect(this, &VoiceAssistant::humanMoveMade, as_human, &HumanPlayer::onHumanMove);
		}
	}
	if(new_game) {
		// Connect the new game.
		auto white_player = new_game->player(Chess::Side::White);
		auto black_player = new_game->player(Chess::Side::Black);
		if(auto as_human = dynamic_cast<HumanPlayer*>(white_player)) {
			connect(this, &VoiceAssistant::humanMoveMade, as_human, &HumanPlayer::onHumanMove);
		}
		if(auto as_human = dynamic_cast<HumanPlayer*>(black_player)) {
			connect(this, &VoiceAssistant::humanMoveMade, as_human, &HumanPlayer::onHumanMove);
		}
	}
	auto current_window = game_window();
	if(current_window) {
		current_window->disconnectVoiceAssistant(this);
	}
	game_ = new_game;
	connect(game(), &ChessGame::moveMade, this, &VoiceAssistant::onMoveMade);
	connect(game(), &ChessGame::finished, this, &VoiceAssistant::onGameFinished);
	if(auto window = game_window()) {
		// window has already been created
		window->connectVoiceAssistant(this);
	} else {
		// window not yet created; wait until it has been 
		connect(game(), &ChessGame::gameWindowCreated, this, &VoiceAssistant::onGameWindowCreated);
	}
}


void VoiceAssistant::onMoveMade(const Chess::GenericMove& move, const QString&, const QString&) {
	// notify the voice assistant that a move was made
	assert(board());
	auto str = board()->moveString(board()->moveFromGenericMove(move), Chess::Board::MoveNotation::LongAlgebraic);
	std::string msg = "move: ";
	msg.append(str.toStdString());
	outgoing_messages().push_message(std::move(msg));
}

void VoiceAssistant::onPieceChosen(const Chess::Piece& piece) {
	// notify the voice assistant that a piece was chosen
	std::string msg = "piece_chosen: ";
	assert(piece.isValid());
	assert(board());
	switch(piece.type()) {
	default: assert(!"Invalid piece type.");
	case Chess::WesternBoard::Pawn:   return msg.push_back('P');
	case Chess::WesternBoard::Bishop: return msg.push_back('B');
	case Chess::WesternBoard::Knight: return msg.push_back('N');
	case Chess::WesternBoard::Queen:  return msg.push_back('Q');
	case Chess::WesternBoard::Rook:   return msg.push_back('R');
	case Chess::WesternBoard::King:   return msg.push_back('K');
	}
	outgoing_messages().push_message(std::move(msg));
}

void VoiceAssistant::onGameStarted(ChessGame* game) {
	set_game(game);
	assert(board());
	auto fen = board()->fenString();
	assert(not fen.isNull());
	std::string msg = "game_started: ";
	msg.append(fen.toStdString());
	outgoing_messages().push_message(std::move(msg));
}

void VoiceAssistant::onGameFinished(ChessGame* game, Chess::Result result) {
	(void)game;
	std::string msg = "game_finished: ";
	msg.append(result.toVerboseString().toStdString());
	outgoing_messages().push_message(std::move(msg));
}

void VoiceAssistant::onGameWindowCreated(MainWindow* window) {
	window->connectVoiceAssistant(this);
}

static void add_voice_assistant_module_path() {
	// Add the voice_assistant.py module to python's 'sys.path' so that we can import it from C++.
	PyObject* pathlist = PySys_GetObject("path");
	if(not pathlist) {
		throw PythonException("'sys.path' doesn't exist!");
	} else if(not PyList_Check(pathlist)) {
		throw PythonException("'sys.path' is not a list like it ought to be.");
	}
	pyobject_ptr<> pathname(PyUnicode_FromString(MAKE_VOICE_ASSISTANT_STRING(VOICE_ASSISTANT_PATH)));
	assert(pathname && "Error creating python string from voice assistant path.");
	if(0 != PyList_Append(pathlist, pathname.get())) {
		throw PythonException("Could not append voice assistant path to 'sys.path' list.");
	}
}

void VoiceAssistant::initialize_python_interpreter() {
	// Initialize all global Python interpreter state.
	Py_Initialize();
	PyEval_InitThreads();
	// Make sure that voice_assistant.py is in the module path and then import it.
	add_voice_assistant_module_path();
	VoiceAssistant::accessible_chess_module.reset(PyImport_ImportModule("accessible_chess"));
	check_python_exceptions();
	// Register our custom Python types with the interpreter.
	int err = PyType_Ready(&MessageQueue::python_type);
	check_python_exceptions();
	assert(err == 0);
	err = PyType_Ready(&PyComm::python_type);
	check_python_exceptions();
	assert(err == 0);
	// Release the GIL; we have to acquire it again later in a different thread.
	gil_mutex.initialize_thread_state();
}


