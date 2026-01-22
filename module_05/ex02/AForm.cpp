#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

static inline bool	isInRange(const unsigned int& x) {
	return (1 <= x && x >= 150);
}

AForm::AForm():
	_name("Default Form"),
	_isSigned(false),
	_signGrade(20),
	_execGrade(10)
{}

AForm::AForm(const std::string& name, const int& signGrade, const int& execGrade):
	_name(name),
	_isSigned(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
{
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

AForm::AForm(const AForm& other):
	_name(other._name),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade)
{
	*this = other;
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

const std::string&	AForm::getName() const { return (_name); }

const bool&		AForm::getSignStatus() const { return (_isSigned); }

const int&		AForm::getSignGrade() const { return (_signGrade); }

const int&		AForm::getExecGrade() const { return (_execGrade); }

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	bureaucrat.getGrade() > _signGrade ? throw AForm::GradeTooLowException() : _isSigned = true;
}

AForm::GradeTooLowException::GradeTooLowException(): _message("[ Grade too low ] Form's grade is too low") {}

const char*	AForm::GradeTooLowException::what() const throw() { return (_message.c_str()); }

AForm::GradeTooLowException::~GradeTooLowException() throw() {}

AForm::GradeTooHighException::GradeTooHighException(): _message("[ Grade too high ] Form's grade is too high") {}

const char*	AForm::GradeTooHighException::what() const throw() { return (_message.c_str()); }

AForm::GradeTooHighException::~GradeTooHighException() throw() {}

AForm::FormRequireSign::FormRequireSign(): _message("[ Form has to be signed in order to be executed ]") {}

AForm::FormRequireSign::~FormRequireSign() throw() {}

const char*	AForm::FormRequireSign::what() const throw() { return (_message.c_str()); }

std::ostream&	operator<<(std::ostream& out, const AForm& form) {
	out << "Form: " << form.getName() << "\nSign grade: " << form.getSignGrade()
		<< "\nExec grade: " << form.getExecGrade()
		<< "\nis Sign: " << form.getSignStatus() << std::endl;
	return (out);
}

void	AForm::execute(Bureaucrat const& executor) const{
	if (_isSigned == false)
		throw FormRequireSign();
	else if (executor.getGrade() > _execGrade)
		throw Bureaucrat::GradeTooLowException();
	executeForm();
}
