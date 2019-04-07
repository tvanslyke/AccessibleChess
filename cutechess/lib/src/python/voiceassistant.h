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

class MainWindow;

class LIB_EXPORT VoiceAssistant: public QObject
{
	Q_OBJECT
public:
	static py::GILMutex gil_mutex;

	VoiceAssistant();

	/** Get the board for the current game. */
	Chess::Board* board() const;
	GameManager* game_manager() const;
	MainWindow* game_window() const;
	ChessGame* game() const;

signals:
	void humanMoveMade(const Chess::GenericMove& move, const Chess::Side& side);
	void newGame();
	void saveGame();
	void resignGame();

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
	py::pyobject_ptr<py::PyComm>  py_comm_;
};



#endif /* PY_VOICE_ASSISTANT_H */
