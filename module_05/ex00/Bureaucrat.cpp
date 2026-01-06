#include "Bureaucrat.hpp"
#include "GradeTooHigh.hpp"
#include "GradeTooLow.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, short grade): _name(name), _grade(grade){
	if (_grade < 1) {
		throw GradeTooHigh("[Out of bound] Grade is too High");
	}
	if (_grade > 150) {
		throw GradeTooLow("[Out of bound] Grade is too Low");
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
