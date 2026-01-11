#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

int	main(void) {

	try {
		Bureaucrat	john("John", 10);
		RobotomyRequestForm	form("rob");

		john.signForm(form);
		john.executeForm(form);

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
