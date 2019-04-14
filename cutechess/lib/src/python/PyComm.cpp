#include "python/PyComm.h"
#include "python/voiceassistant.h"
#include "python/MessageQueue.h"
#include "mainwindow.h"
#include "newgamedlg.h"
#include <algorithm>
#include <cstring>

using namespace py;

static bool PyComm_check(PyObject *self) {
	return Py_TYPE(self) == &PyComm::python_type;
}

static PyComm* PyComm_ensure(PyObject *self) {
	if(not PyComm_check(self)) {
		PyErr_SetString(PyExc_TypeError, "A PyComm object is required.");
		return nullptr;
	}
	return static_cast<PyComm*>(self);
}

#define PY_COMM_ENSURE(slf, self_decl, errval)  \
	PyComm* self_decl = PyComm_ensure(slf); \
	if(not self) {                          \
		return errval;                  \
	}

int PyComm::initialize(VoiceAssistant* va) {
	voice_assistant = va;
	outgoing_messages.reset(static_cast<MessageQueue*>(PyObject_CallFunctionObjArgs(
		reinterpret_cast<PyObject*>(&py::MessageQueue::python_type),
		static_cast<PyObject*>(nullptr)
	)));
	if(not outgoing_messages) {
		return -1;
	}
	return 0;
}
	
Chess::Board* PyComm::board() const {
	return voice_assistant ? voice_assistant->board() : nullptr;
}

ChessGame* PyComm::game() const {
	return voice_assistant ? voice_assistant->game() : nullptr;
}

static PyObject* PyComm_new_game(PyObject* slf, PyObject* args) {
	(void)args;
	PY_COMM_ENSURE(slf, self, nullptr)
	if(self->game() and not self->game()->isFinished()) {
		return PyErr_Format(PyExc_RuntimeError, "Cannot start new game until the current game is closed.");
	}
	assert(self->voice_assistant);
	assert(self->voice_assistant->game_window());
	emit self->voice_assistant->newGame();
	Py_RETURN_NONE;
}

static PyObject* PyComm_resign_game(PyObject* slf, PyObject* args) {
	(void)args;
	PY_COMM_ENSURE(slf, self, nullptr)
	if(not self->game()) {
		return PyErr_Format(PyExc_RuntimeError, "Cannot resign without an active game.");
	}
	assert(self->voice_assistant);
	emit self->voice_assistant->resignGame();
	Py_RETURN_NONE;
}

static PyObject* PyComm_save_game(PyObject* slf, PyObject* args) {
	(void)args;
	PY_COMM_ENSURE(slf, self, nullptr)
	if((not self->game()) or (self->game()->isFinished())) {
		return PyErr_Format(PyExc_RuntimeError, "Cannot save without an active game.");
	}
	assert(self->voice_assistant);
	self->voice_assistant->game_window()->saveGame(SAVED_GAME_PATH_STRING);
	// emit self->voice_assistant->saveGame();
	Py_RETURN_NONE;
}

static PyObject* PyComm_load_game(PyObject* slf, PyObject* args) {
	(void)args;
	PY_COMM_ENSURE(slf, self, nullptr)
	return PyErr_Format(PyExc_RuntimeError, "PyComm.load_game() is not yet implemented.");
}

static PyObject* PyComm_board_fen(PyObject* slf, PyObject* args) {
	(void)args;
	PY_COMM_ENSURE(slf, self, nullptr)
	if(not self->board()) {
		// no game.
		Py_RETURN_NONE;
	}
	QString fen(self->board()->fenString());
	if(fen.isNull()) {
		return PyErr_Format(PyExc_RuntimeError, "Error while obtaining FEN string.");
	}
	auto bytes = fen.toLatin1();
	if(bytes.isNull()) {
		return PyErr_Format(PyExc_RuntimeError, "Error while converting FEN string to Latin1.");
	}
	return PyUnicode_FromStringAndSize(bytes.data(), bytes.size());
}

static PyObject* PyComm_make_move(PyObject* slf, PyObject* arg) {
	PY_COMM_ENSURE(slf, self, nullptr)
	VoiceAssistant* va = self->voice_assistant;
	assert(va);
	if(not PyUnicode_Check(arg)) {
		return PyErr_Format(PyExc_ValueError, "Expected string/unicode object, not '%S'.", Py_TYPE(arg));
	}
	const char* movestr = PyUnicode_AsUTF8(arg);
	if(not movestr) {
		return nullptr;
	}
	if((not va->game())) {
		return PyErr_Format(PyExc_ValueError, "No active game.");
	}
	QString moveqstr(movestr);
	if(moveqstr.isNull()) {
		return PyErr_Format(PyExc_ValueError, "Error while converting python string to QString in make_move().");
	}
	Chess::GenericMove move = va->board()->genericMove(va->board()->moveFromString(moveqstr));	
	if(not va->board()->isLegalMove(va->board()->moveFromGenericMove(move))) {
		return PyErr_Format(PyExc_ValueError, "Move '%s' is not a valid move.", movestr);
	}
	auto side = va->board()->sideToMove();
	emit va->humanMoveMade(move, side);
	Py_RETURN_NONE;
}

static PyObject* PyComm_active_game(PyObject* slf, PyObject* args) {
	(void)args;
	PY_COMM_ENSURE(slf, self, nullptr)
	if(self->game()) {
		Py_RETURN_TRUE;
	} else {
		Py_RETURN_FALSE;
	}
}

static PyObject* PyComm_is_creating_new_game(PyObject* slf, PyObject* args) {
	(void)args;
	PY_COMM_ENSURE(slf, self, nullptr)
	auto* va = self->voice_assistant;
	if(va->active_new_game_dialog()) {
		Py_RETURN_TRUE;
	} else {
		Py_RETURN_FALSE;
	}
}

static PyObject* PyComm_set_player_type(PyObject* slf, PyObject* args) {
	PY_COMM_ENSURE(slf, self, nullptr)
	auto va = self->voice_assistant;
	if(not va->active_new_game_dialog()) {
		return PyErr_Format(PyExc_ValueError, "Cannot set player type while there is no active new game dialog.");
	} 
	const char* color = nullptr;
	const char* player_type  = nullptr;
	if(not PyArg_ParseTuple(args, "ss", &color, &player_type)) {
		return nullptr;
	}
	assert(color);
	assert(player_type);
	std::string color_string;
	std::string player_type_string;
	try {
		auto to_lower = [](unsigned char c) { return static_cast<char>(std::tolower(c)); };
		std::transform(color, color + std::strlen(color), std::back_inserter(color_string), to_lower);
		std::transform(player_type, player_type + std::strlen(player_type), std::back_inserter(player_type_string), to_lower);
	} catch(const std::bad_alloc&) {
		PyErr_NoMemory();
		return nullptr;
	}
	if(color_string == "black") {
		if(player_type_string == "cpu") {
			emit va->chooseBlackCPUPlayer();
		} else if(player_type_string == "human") {
			emit va->chooseBlackHumanPlayer();
		} else {
			return PyErr_Format(
				PyExc_ValueError,
				"'player_type' argument must be one of 'cpu' or 'human' (case insensitive) not '%s'.",
				player_type
			);
		}
	} else if(color_string == "white") {
		if(player_type_string == "cpu") {
			emit va->chooseWhiteCPUPlayer();
		} else if(player_type_string == "human") {
			emit va->chooseWhiteHumanPlayer();
		} else {
			return PyErr_Format(
				PyExc_ValueError,
				"'player_type' argument must be one of 'cpu' or 'human' (case insensitive) not '%s'.",
				player_type
			);
		}
	} else {
		return PyErr_Format(
			PyExc_ValueError,
			"'side' argument must be one of 'black' or 'white' (case insensitive) not '%s'.",
			color
		);
	}
	Py_RETURN_NONE;
}

static PyObject* PyComm_cancel_new_game(PyObject* slf, PyObject* args) {
	PY_COMM_ENSURE(slf, self, nullptr)
	(void)args;
	auto va = self->voice_assistant;
	if(not va->active_new_game_dialog()) {
		return PyErr_Format(PyExc_ValueError, "Cannot cancel new game while there is no active new game dialog.");
	}
	emit va->cancelNewGame();
	Py_RETURN_NONE;
}

static PyObject* PyComm_start_new_game(PyObject* slf, PyObject* args) {
	PY_COMM_ENSURE(slf, self, nullptr)
	(void)args;
	auto va = self->voice_assistant;
	if(not va->active_new_game_dialog()) {
		return PyErr_Format(PyExc_ValueError, "Cannot start new game while there is no active new game dialog.");
	}
	emit va->acceptNewGame();
	Py_RETURN_NONE;
}

static PyObject* PyComm_load_saved_game(PyObject* slf, PyObject* args) {
	PY_COMM_ENSURE(slf, self, nullptr)
	(void)args;
	auto va = self->voice_assistant;
	if(not va->active_new_game_dialog()) {
		return PyErr_Format(PyExc_ValueError, "Cannot start new game while there is no active new game dialog.");
	}
	va->get_new_game_dialog()->load_mode = true;
	emit va->acceptNewGame();
	Py_RETURN_NONE;
}


static PyGetSetDef PyComm_getset[] = {
	PyGetSetDef{
		const_cast<char*>("messages"),
		+[](PyObject* slf, void*) -> PyObject* {
			auto* self = PyComm_ensure(slf);
			if(not self) {
				return nullptr;
			}
			if(not self->outgoing_messages) {
				Py_RETURN_NONE;
			}
			return self->outgoing_messages.get();
		},
		nullptr,
		const_cast<char*>("Queue of messages/notifications/signals from Cutechess."),
		nullptr
	},
	PyGetSetDef{nullptr, nullptr, nullptr, nullptr, nullptr}
};

static void PyComm_dealloc(PyObject* self) {
	assert(PyComm_check(self));
	reinterpret_cast<PyComm*>(self)->~PyComm();
	Py_TYPE(self)->tp_free(self);
}

static int PyComm_init(PyObject *self, PyObject *args, PyObject *kwds) {
	char* kwords[] = {nullptr};
	if(not PyArg_ParseTupleAndKeywords(args, kwds, "", kwords)) {
		return -1;
	}
	PyObject head{*self};
	new (static_cast<PyComm*>(self)) PyComm(head);
	return 0;
}

static PyMethodDef PyComm_methods[] = {
	PyMethodDef{
		"active_game",
		reinterpret_cast<PyCFunction>(PyComm_active_game),
		METH_NOARGS,
		"Returns True if there is an active game, False otherwise."
	},
	PyMethodDef{
		"new_game",
		reinterpret_cast<PyCFunction>(PyComm_new_game),
		METH_NOARGS,
		"Start a new game.  Throws if there is currently an active game."
	},
	PyMethodDef{
		"save_game",
		reinterpret_cast<PyCFunction>(PyComm_save_game),
		METH_NOARGS,
		"Save the current game.  Throws if there is not currently an active game."
	},
	PyMethodDef{
		"resign_game",
		reinterpret_cast<PyCFunction>(PyComm_resign_game),
		METH_NOARGS,
		"Resign the current game.  Throws if there is not currently an active game."
	},
	PyMethodDef{
		"make_move",
		reinterpret_cast<PyCFunction>(PyComm_make_move),
		METH_O,
		"Make the move given by the SAN move string.  Throws if the move is invalid."
	},
	PyMethodDef{
		"board_fen",
		reinterpret_cast<PyCFunction>(PyComm_board_fen),
		METH_NOARGS,
		"Obtain the FEN string for the currently-active game."
	},
	PyMethodDef{
		"is_creating_new_game",
		reinterpret_cast<PyCFunction>(PyComm_is_creating_new_game),
		METH_NOARGS,
		"Check whether there is an active new game dialog open."
	},
	PyMethodDef{
		"set_player_type",
		reinterpret_cast<PyCFunction>(PyComm_set_player_type),
		METH_VARARGS,
		"Set player on 'side' (\"black\" or \"white\") to 'player_type' (\"cpu\" or \"human\")."\
		" (only valid during a new game dialog)"
	},
	PyMethodDef{
		"cancel_new_game",
		reinterpret_cast<PyCFunction>(PyComm_cancel_new_game),
		METH_NOARGS,
		"Cancel a the currently-active new game dialog. (only valid during a new game dialog)"
	},
	PyMethodDef{
		"start_new_game",
		reinterpret_cast<PyCFunction>(PyComm_start_new_game),
		METH_NOARGS,
		"Finish creating a new game. (only valid during a new game dialog)"
	},
	PyMethodDef{
		"load_saved_game",
		reinterpret_cast<PyCFunction>(PyComm_load_saved_game),
		METH_NOARGS,
		"Finish creating a new game by loading the saved game. (only valid during a new game dialog)"
	},
	PyMethodDef{nullptr, nullptr, 0, nullptr}	
};

PyTypeObject PyComm::python_type{
	PyVarObject_HEAD_INIT(nullptr, 0)
	"CppPyComm",
	sizeof(PyComm),
	0,
	PyComm_dealloc,                               /* tp_dealloc */
	0,                                            /* tp_print */
	0,                                            /* tp_getattr */
	0,                                            /* tp_setattr */
	0,                                            /* tp_reserved */
	0,                                            /* tp_repr */
	0,                                            /* tp_as_number */
	0,                                            /* tp_as_sequence */
	0,                                            /* tp_as_mapping */
	PyObject_HashNotImplemented,                  /* tp_hash */
	0,                                            /* tp_call */
	0,                                            /* tp_str */
	PyObject_GenericGetAttr,                      /* tp_getattro */
	0,                                            /* tp_setattro */
	0,                                            /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,                           /* tp_flags */
	"Type used to communicate with Cutechess.",   /* tp_doc */
	0,                                            /* tp_traverse */
	0,                                            /* tp_clear */
	0,                                            /* tp_richcompare */
	0,                                            /* tp_weaklistoffset */
	0,                                            /* tp_iter */
	0,                                            /* tp_iternext */
	PyComm_methods,                               /* tp_methods */
	0,                                            /* tp_members */
	PyComm_getset,                                /* tp_getset */
	0,                                            /* tp_base */
	0,                                            /* tp_dict */
	0,                                            /* tp_descr_get */
	0,                                            /* tp_descr_set */
	0,                                            /* tp_dictoffset */
	reinterpret_cast<initproc>(PyComm_init),      /* tp_init */
	PyType_GenericAlloc,                          /* tp_alloc */
	PyType_GenericNew,                            /* tp_new */
	PyObject_Del,                                 /* tp_free */
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

