#ifndef AC_PY_COMM_H
#define AC_PY_COMM_H

#include "python/pyapi.h"
#include "python/MessageQueue.h"
#include "board/board.h"
#include "board/westernboard.h"
#include "board/move.h"
#include "board/genericmove.h"
#include "board/side.h"
#include "board/result.h"
#include "board/piece.h"
#include "humanplayer.h"
#include "chessgame.h"

class VoiceAssistant;

namespace py {

struct PyComm: PyObject {
	static PyTypeObject python_type;

	PyComm(PyObject head):
		PyObject{head},
		voice_assistant{nullptr},
		outgoing_messages{nullptr}
	{
		
	}

	PyComm(const PyComm&) = delete;
	PyComm(PyComm&&)      = delete;

	PyComm& operator=(const PyComm&) = delete;
	PyComm& operator=(PyComm&&)      = delete;

	Chess::Board* board() const;
	ChessGame* game() const;

	int initialize(VoiceAssistant* va);

	// These member functions are called from Python:
	void notify_move_made(const Chess::GenericMove& move) const;
	void notify_new_game() const;
	void notify_save_game() const;
	void notify_resign_game() const;

	pyobject_ptr<> board_fen() const;

	VoiceAssistant* voice_assistant = nullptr;
	pyobject_ptr<MessageQueue> outgoing_messages = nullptr;
};

} /* namespace py */

#endif /* AC_PY_COMM_H */
