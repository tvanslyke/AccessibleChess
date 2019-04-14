#ifndef CUTECHESS_PYTHON_PYAPI_H
#define CUTECHESS_PYTHON_PYAPI_H

#include <memory>
#include <thread>
#include <atomic>
#include <stdexcept>
#include <mutex>
#include <QString>
#include <QThread>
#include <cassert>
#undef slots
#include <Python.h>
#define slots Q_SLOTS

namespace py {

struct Decref {
	void operator()(PyObject* p) const {
		Py_XDECREF(p);
	}
};

struct EndInterp {
	void operator()(PyThreadState* st) const {
		Py_EndInterpreter(st);
	}
};

template <class PyObjectType = PyObject>
using pyobject_ptr = std::unique_ptr<PyObjectType, Decref>;

template <class T>
pyobject_ptr<T> copy_ref(T* pyobj) {
	Py_XINCREF(pyobj);
	return pyobject_ptr<T>(pyobj);
}

template <class T>
pyobject_ptr<T> copy_ref(const pyobject_ptr<T>& p) {
	return copy_ref(p.get());
}

template <class T>
pyobject_ptr<T> acquire_ref(T* pyobj_ptr) {
	return pyobject_ptr<T>(pyobj_ptr);
}

struct PythonException: std::runtime_error {
	using std::runtime_error::runtime_error;
	using std::runtime_error::what;
	~PythonException() = default;
};


inline pyobject_ptr<> pyunicode_from_qstring(const QString& s) {
	auto as_bytes = s.toLatin1();
	return pyobject_ptr<>(
		s.isNull() ? nullptr : PyUnicode_FromStringAndSize(as_bytes.data(), as_bytes.size())
	);
}

inline void check_python_exceptions() {
	if(not PyErr_Occurred()) {
		return;
	}
	PyObject* exc_type;
	PyObject* exc_value;
	PyObject* exc_tb;
	PyErr_Fetch(&exc_type, &exc_value, &exc_tb);
	assert(exc_type or exc_value);
	assert(not PyErr_Occurred());
	PyErr_NormalizeException(&exc_type, &exc_value, &exc_tb);

	pyobject_ptr<> tp(exc_type);
	pyobject_ptr<> val(exc_value);
	pyobject_ptr<> tb(exc_tb);
	pyobject_ptr<> traceback_module(PyImport_ImportModule("traceback")); 
	assert(traceback_module);
	std::string error_string;
	{
		pyobject_ptr<> err_string(nullptr);
		if(val) {
			err_string.reset(PyUnicode_FromFormat(
				"Python exception of type '%S' raised:\r\n\t\"%S\"",
				tp.get(),
				val.get()
			));
		} else {
			err_string.reset(PyUnicode_FromFormat(
				"Python exception of type '%S' raised:",
				tp.get()
			));
		}
		assert(err_string);
		Py_ssize_t sz;
		const char* data = PyUnicode_AsUTF8AndSize(err_string.get(), &sz);
		assert(data);
		error_string.assign(data, sz);
	}
	if(not tb) {
		throw PythonException(error_string);
	} else {
		error_string += "\r\n";
	}
	pyobject_ptr<> formatted_exc;
	if(val and tp) {
		pyobject_ptr<> fmt_exc_fn(PyObject_GetAttrString(traceback_module.get(), "format_exception"));
		assert(fmt_exc_fn);
		formatted_exc.reset(PyObject_CallFunctionObjArgs(fmt_exc_fn.get(), tp.get(), val.get(), tb.get(), nullptr));
		assert(formatted_exc);
	} else {
		pyobject_ptr<> fmt_tb_fn(PyObject_GetAttrString(traceback_module.get(), "format_exception"));
		assert(fmt_tb_fn);
		formatted_exc.reset(PyObject_CallFunctionObjArgs(fmt_tb_fn.get(), tb.get(), nullptr));
		assert(formatted_exc);
	}
	pyobject_ptr<> tb_iter(PyObject_GetIter(formatted_exc.get()));
	assert(PyIter_Check(tb_iter.get()));
	for(
		pyobject_ptr<> item(PyIter_Next(tb_iter.get()));
		item;
		item.reset(PyIter_Next(tb_iter.get()))
	) {
		Py_ssize_t sz;
		const char* data = PyUnicode_AsUTF8AndSize(item.get(), &sz);
		assert(data);
		error_string.append(data, sz);
	}
	throw PythonException(error_string);
}

struct GILMutex {

	GILMutex():
		mutex_{},
		entry_count_(0u),
		saved_(nullptr)
	{

	}

	GILMutex(const GILMutex&) = delete;
	GILMutex(GILMutex&&)      = delete;

	GILMutex& operator=(const GILMutex&) = delete;
	GILMutex& operator=(GILMutex&&)      = delete;

	void lock() {
		mutex_.lock();
		if(entry_count_++ == 0u) {
			assert(saved_);
			PyEval_RestoreThread(saved_);
			saved_ = nullptr;
		}
	}

	void unlock() {
		if(--entry_count_ == 0u) {
			assert(not saved_);
			saved_ = PyEval_SaveThread();
		}
		mutex_.unlock();
	}

	void initialize_thread_state() {
		saved_ = PyEval_SaveThread();
	}

private:
	std::recursive_mutex mutex_;
	std::size_t entry_count_ = 0u;
	PyThreadState* saved_ = nullptr;
};


} /* namespace py */


#endif /* CUTECHESS_PYTHON_PYAPI_H */
