#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	AForm* (Intern::*shrub)(std::string const &) const = &Intern::getShrubberyForm;
	AForm* (Intern::*robotomy)(std::string const &) const = &Intern::getRobotomyForm;
	AForm*	(Intern::*pardon)(std::string const &) const = &Intern::getPardonForm;
	_funcMap["shrubbery request"] = shrub;
	_funcMap["robotomy request"] = robotomy;
	_funcMap["pardon request"] = pardon;
}

Intern::Intern(Intern const & other) {
	*this = other;
}

Intern&	Intern::operator=(Intern const & other) {
	if (this != &other) {
		std::cout << "Nothing to be copied" << std::endl;
	}
	return (*this);
}

Intern::~Intern() {
}

AForm*	Intern::getShrubberyForm(std::string const & target) const{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::getRobotomyForm(std::string const & target) const {
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::getPardonForm(std::string const & target) const {
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(std::string const & formName, std::string const & target) const {
	// Needs to intiliaze a form of the requested typed specified by name
	// then return a pointer to this form;

	std::cout << _funcMap.at(formName) << std::endl;
	return(getShrubberyForm(target));
}
