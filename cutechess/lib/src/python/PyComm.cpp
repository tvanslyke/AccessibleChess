#include "python/PyComm.h"
#include "python/voiceassistant.h"
#include "python/MessageQueue.h"
#include "mainwindow.h"

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
	if(not self->game()) {
		return PyErr_Format(PyExc_RuntimeError, "Cannot save without an active game.");
	}
	assert(self->voice_assistant);
	emit self->voice_assistant->saveGame();
	Py_RETURN_NONE;
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

