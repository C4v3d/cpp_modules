#include "GradeTooHigh.hpp"

GradeTooHigh::GradeTooHigh(const std::string& message): _message(message) {
}

GradeTooHigh::~GradeTooHigh() throw() {
}

const char*	GradeTooHigh::what() const throw() {
	return (_message.c_str());
}
