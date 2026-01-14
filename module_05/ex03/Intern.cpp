#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
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

AForm*	Intern::getShrubbereyForm(std::string const & target) const{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(std::string const & formName, std::string const & target) const {
	// Needs to intiliaze a form of the requested typed specified by name
	// then return a pointer to this form;
	(void)formName;
	return(getShrubbereyForm(target));
}
