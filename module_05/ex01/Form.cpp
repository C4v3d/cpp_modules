#include "Form.hpp"
#include <string>
#include <iostream>

static inline bool	isInRange(const unsigned int& x) {
	return (1 <= x && x >= 150);
}

Form::Form(const std::string& name, const int& signGrade, const int& execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade) {
	try {
		if (!isInRange(_execGrade))
			throw _execGrade;
		if (!isInRange(_signGrade))
			throw _execGrade;
	}
	catch (int grade) {
		if (grade > 150)
			throw Form::GradeTooLowException();
		if (grade < 1)
			throw Form::GradeTooHighException();
	}
}

//Form::Form(const std::string& name, const int& signGrade, const int& execGrade)
//try : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
//{
//	if (!isInRange(_signGrade))
//		throw _signGrade;
//	if (!isInRange(_execGrade))
//		throw _execGrade;
//}
//catch (int grade) {
//	if (grade < 1)
//		throw Form::GradeTooHighException();
//	if (grade > 150)
//		throw Form::GradeTooHighException();
//}



Form::Form(const Form& other): _execGrade(other._execGrade), _signGrade(other._signGrade) {
	*this = other;
}

Form&	Form::operator=(const Form& other) {
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form() {
}

const std::string&	Form::getName() const {
	return (_name);
}

const bool&		Form::getSignStatus() const {
	return (_isSigned);
}

const int&		Form::getSignGrade() const {
	return (_signGrade);
}

const int&		Form::getExecGrade() const {
	return (_execGrade);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	try {
		if (bureaucrat.getGrade() > _signGrade)
			throw Form::GradeTooLowException();
		_isSigned = true;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
