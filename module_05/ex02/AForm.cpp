#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

static inline bool	isInRange(const unsigned int& x) {
	return (1 <= x && x >= 150);
}

AForm::AForm(const std::string& name, const int& signGrade, const int& execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade) {
	try {
		if (!isInRange(_execGrade))
			throw _execGrade;
		if (!isInRange(_signGrade))
			throw _execGrade;
	}
	catch (int grade) {
		if (grade > 150)
			throw AForm::GradeTooLowException();
		if (grade < 1)
			throw AForm::GradeTooHighException();
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



AForm::AForm(const AForm& other): _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade) {
	*this = other;
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm() {
}

const std::string&	AForm::getName() const {
	return (_name);
}

const bool&		AForm::getSignStatus() const {
	return (_isSigned);
}

const int&		AForm::getSignGrade() const {
	return (_signGrade);
}

const int&		AForm::getExecGrade() const {
	return (_execGrade);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	try {
		if (bureaucrat.getGrade() > _signGrade)
			throw AForm::GradeTooLowException();
		_isSigned = true;
	}
	catch (const std::exception& e) {
		throw 1;
	}
}

AForm::GradeTooLowException::GradeTooLowException(): _message("[ Grade too low ] Form's grade is too low") {
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return (_message.c_str());
}

AForm::GradeTooLowException::~GradeTooLowException() throw() {
}

AForm::GradeTooHighException::GradeTooHighException(): _message("[ Grade too high ] Form's grade is too high") {
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return (_message.c_str());
}

AForm::GradeTooHighException::~GradeTooHighException() throw() {
}

std::ostream&	operator<<(std::ostream& out, const AForm& form) {
	out << "Form: " << form.getName() << "\nSign grade: " << form.getSignGrade()
		<< "\nExec grade: " << form.getExecGrade()
		<< "\nis Sign: " << form.getSignStatus() << std::endl;
	return (out);
}

void	AForm::execute(Bureaucrat const& executor) {
	if (!_isSigned) {
		throw 1;
		return ;
	}
	if (executor.getGrade() > _execGrade) {
		throw 2;
	}
}
