#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, short grade): _name(name), _grade(grade){
	if (_grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (_grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name) {
	*this = other;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

const std::string	Bureaucrat::getName() const {
	return (_name);
}

short	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::incrGrade() {
	try {
		if (_grade - 1 < 1)
			throw (_grade);
		_grade--;
	}
	catch (short grade) {
		std::cout << "(" << grade << ")"
			<< " Promotion result in out of bound grade ! (1 - 150)\n" << std::endl;
	}
}

void	Bureaucrat::decrGrade() {
	try {
		if (_grade + 1 > 150)
			throw (_grade);
		_grade++;
	}
	catch (short grade) {
		std::cout << "(" << grade << ")"
			<< " De-ranking result in out of bound grade ! (1 - 150)\n" << std::endl;
	}
}

Bureaucrat::GradeTooLowException::GradeTooLowException(): _message("[ Out of bound ] Grade is too low") {
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return (_message.c_str());
}

Bureaucrat::GradeTooHighException::GradeTooHighException(): _message("[ Out of bound ] Grade is too High") {
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return (_message.c_str());
}
