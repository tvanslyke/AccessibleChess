#ifndef PY_VOICE_ASSISTANT_H
#define PY_VOICE_ASSISTANT_H

#include "python/pyapi.h"
#include "python/MessageQueue.h"
#include "python/PyComm.h"
#include "board/board.h"
#include "board/westernboard.h"
#include "board/move.h"
#include "board/genericmove.h"
#include "board/side.h"
#include "board/result.h"
#include "board/piece.h"
#include "humanplayer.h"
#include "gamemanager.h"
#include "chessgame.h"
#include <thread>

class MainWindow;
class NewGameDialog;

class LIB_EXPORT VoiceAssistant: public QObject
{
	Q_OBJECT
public:
	static py::GILMutex gil_mutex;

	VoiceAssistant();
	~VoiceAssistant();

	/** Get the board for the current game. */
	Chess::Board* board() const;
	MainWindow* game_window() const;
	ChessGame* game() const;
	void set_new_game_dialog(NewGameDialog* p) {
		new_game_dialog_ = p;
	}

	bool active_new_game_dialog() const {
		return new_game_dialog_;
	}

	NewGameDialog* get_new_game_dialog() const {
		return new_game_dialog_;
	}

signals:
	void humanMoveMade(const Chess::GenericMove& move, const Chess::Side& side);
	void newGame();
	void saveGame();
	void resignGame();
	void chooseBlackCPUPlayer();
	void chooseWhiteCPUPlayer();
	void chooseBlackHumanPlayer();
	void chooseWhiteHumanPlayer();
	void acceptNewGame();
	void cancelNewGame();

public slots:
	void onMoveMade(const Chess::GenericMove& move, const QString& sanString, const QString& comment);
	void onPieceChosen(const Chess::Piece& piece);
	void onGameStarted(ChessGame* game);
	void onGameFinished(ChessGame* game=nullptr, Chess::Result result=Chess::Result());
	void onGameWindowCreated(MainWindow* game);

public:
	py::MessageQueue& outgoing_messages() const;
	static void init_python_interpreter();

private:
	void set_game(ChessGame* new_game);

	static void initialize_python_interpreter();
	static py::pyobject_ptr<> accessible_chess_module;

	ChessGame*                    game_;
	NewGameDialog*                new_game_dialog_;
	py::pyobject_ptr<py::PyComm>  py_comm_;
	std::thread                   python_thread_;
};



#endif /* PY_VOICE_ASSISTANT_H */
