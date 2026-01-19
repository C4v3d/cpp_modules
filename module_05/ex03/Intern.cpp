#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
	_funcMap["shrubbery request"] = &Intern::getShrubberyForm;
	_funcMap["robotomy request"] = &Intern::getRobotomyForm;
	_funcMap["pardon request"] = &Intern::getPardonForm;
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
	std::map<std::string, AForm*(Intern::*)(std::string const &) const>::const_iterator it;
	it = _funcMap.find(formName);
	if (it == _funcMap.end()) {
		std::cout << "Intern cannot create form: " << formName << std::endl;
		return NULL;
	}
	std::cout << "Intern creates " << formName << std::endl;
    	return (this->*(it->second))(target);
}
