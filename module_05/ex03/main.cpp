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
		Intern			Steve;

		//form = Steve.makeForm("bad form request", "who"); // Shouldn't create a Form
		form = Steve.makeForm("robotomy request", "Bender");
		john.signForm(*form);
		john.executeForm(*form);
		delete form;

		form = Steve.makeForm("shrubbery request", "42 Lausanne");
		john.signForm(*form);
		john.executeForm(*form);
		delete form;

		form = Steve.makeForm("pardon request", "Spencer");
		john.signForm(*form);
		john.executeForm(*form);
		std::cout << "promoting john !" << std::endl;
		for (int i = 0; i < 5; i++)
			john.incrGrade();
		john.executeForm(*form);
		delete form;

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
