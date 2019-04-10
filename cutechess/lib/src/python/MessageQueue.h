#ifndef AC_MESSAGE_QUEUE_H
#define AC_MESSAGE_QUEUE_H

#include <deque>
#include <string>
#include "pyapi.h"
#include <mutex>

namespace py {

struct MessageQueue: PyObject {
	static PyTypeObject python_type;

	MessageQueue(PyObject head):
		PyObject{head},
		mutex_{},
		messages_{}
	{
		
	}

	MessageQueue(const MessageQueue&) = delete;
	MessageQueue(MessageQueue&&)      = delete;

	MessageQueue& operator=(const MessageQueue&) = delete;
	MessageQueue& operator=(MessageQueue&&)      = delete;

	void push_message(std::string msg);
	py::pyobject_ptr<> pop_message();
	std::size_t message_count() const;
private:
	mutable std::mutex mutex_;
	std::deque<std::string> messages_;
};

} /* namespace py */

#endif /* AC_MESSAGE_QUEUE_H */
