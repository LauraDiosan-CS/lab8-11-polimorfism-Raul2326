#include "ValidationException.h"

ValidationException::ValidationException() {
}

ValidationException::~ValidationException() {
}

ValidationException::ValidationException(string message) {
	this->message = message;
}

string ValidationException::Reason() throw() {
	return message;
}
