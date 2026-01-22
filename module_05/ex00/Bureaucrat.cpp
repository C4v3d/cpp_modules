#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): _name("Steve"), _grade(24) {}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade): _name(name), _grade(grade){
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

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const { return (_name); }

const int&	Bureaucrat::getGrade() const { return (_grade); }

void	Bureaucrat::incrGrade() {
	_grade - 1 < 1 ? throw Bureaucrat::GradeTooHighException() : _grade--;
}

void	Bureaucrat::decrGrade() {
	_grade + 1 > 150 ? throw Bureaucrat::GradeTooLowException() : _grade++;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(): _message("[ Out of bound ] Grade is too low") {}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw() {}

const char*	Bureaucrat::GradeTooLowException::what() const throw() { return (_message.c_str()); }

Bureaucrat::GradeTooHighException::GradeTooHighException(): _message("[ Out of bound ] Grade is too High") {}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw() {}

const char*	Bureaucrat::GradeTooHighException::what() const throw() { return (_message.c_str()); }

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (out);
}
