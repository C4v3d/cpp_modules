#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void) {

	try {
		Bureaucrat		john("john", 10);
		AForm			*form;
		Intern			anri;

		form = anri.makeForm("shrubbery request", "Ikea");
		john.signForm(*form);
		john.executeForm(*form);
		delete form;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
