#include "MessageQueue.h"

#include <cstdlib>

using namespace py;

void MessageQueue::push_message(std::string msg) {
	std::lock_guard<std::mutex> hold_(mutex_);
	messages_.push_back(std::move(msg));
}

py::pyobject_ptr<> MessageQueue::pop_message() {
	std::unique_lock<std::mutex> lock(mutex_);
	if(messages_.size() == 0u) {
		lock.unlock();
		PyErr_SetString(PyExc_ValueError, "Attempt to pop message from empty CppMessageQueue instance.");
		return nullptr;
	}
	auto& msg = messages_.front();
	py::pyobject_ptr<> str(PyUnicode_FromStringAndSize(msg.data(), msg.size()));
	if(str) {
		messages_.pop_front();
	}
	return str;
}

std::size_t MessageQueue::message_count() const {
	std::lock_guard<std::mutex> hold_(mutex_);
	return messages_.size();
}

static bool MessageQueue_check(PyObject *self) {
	return Py_TYPE(self) == &MessageQueue::python_type;
}

static void MessageQueue_dealloc(PyObject* self) {
	assert(MessageQueue_check(self));
	reinterpret_cast<MessageQueue*>(self)->~MessageQueue();
	Py_TYPE(self)->tp_free(self);
}

static int MessageQueue_init(PyObject *self, PyObject *args, PyObject *kwds) {
	char* kwords[] = {nullptr};
	if(not PyArg_ParseTupleAndKeywords(args, kwds, "", kwords)) {
		return -1;
	}
	PyObject head{*self};
	new (static_cast<MessageQueue*>(self)) MessageQueue(head);
	return 0;
}

static PyObject* MessageQueue_message_count(PyObject* self, PyObject* args) {
	(void)args;
	if(not MessageQueue_check(self)) {
		return PyErr_Format(PyExc_TypeError, "An instance of CppMessageQueue is required.");
	}
	return PyLong_FromSize_t(reinterpret_cast<MessageQueue*>(self)->message_count());
}

static PyObject* MessageQueue_pop_message(PyObject* self, PyObject* args) {
	(void)args;
	if(not MessageQueue_check(self)) {
		return PyErr_Format(PyExc_TypeError, "An instance of CppMessageQueue is required.");
	}
	return reinterpret_cast<MessageQueue*>(self)->pop_message().release();
}

static PyMethodDef MessageQueue_methods[] = {
	PyMethodDef{
		"message_count",
		reinterpret_cast<PyCFunction>(MessageQueue_message_count),
		METH_NOARGS,
		"Returns the number of messages in the queue."
	},
	PyMethodDef{
		"pop_message",
		reinterpret_cast<PyCFunction>(MessageQueue_pop_message),
		METH_NOARGS,
		"Pop and return the message at the front of the queue."
	},
	PyMethodDef{nullptr, nullptr, 0, nullptr}
};

PyTypeObject MessageQueue::python_type = PyTypeObject{
	PyVarObject_HEAD_INIT(&PyType_Type, 0)
	"CppMessageQueue",
	sizeof(MessageQueue),
	0,
	MessageQueue_dealloc,                         /* tp_dealloc */
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
	"A simple thread-safe queue of C++ strings.", /* tp_doc */
	0,                                            /* tp_traverse */
	0,                                            /* tp_clear */
	0,                                            /* tp_richcompare */
	0,                                            /* tp_weaklistoffset */
	0,                                            /* tp_iter */
	0,                                            /* tp_iternext */
	MessageQueue_methods,                         /* tp_methods */
	0,                                            /* tp_members */
	0,                                            /* tp_getset */
	0,                                            /* tp_base */
	0,                                            /* tp_dict */
	0,                                            /* tp_descr_get */
	0,                                            /* tp_descr_set */
	0,                                            /* tp_dictoffset */
	(initproc)MessageQueue_init,                  /* tp_init */
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


