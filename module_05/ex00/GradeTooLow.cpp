#include "GradeTooLow.hpp"

GradeTooLow::GradeTooLow(const std::string& message): _message(message) {
}

GradeTooLow::~GradeTooLow() throw() {
}

const char*	GradeTooLow::what() const throw() {
	return (_message.c_str());
}
