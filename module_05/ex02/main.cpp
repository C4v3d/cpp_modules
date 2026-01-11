#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void) {

	try {
		Bureaucrat	john("John", 10);
		ShrubberyCreationForm	shform("shrub");

		john.signForm(shform);
		john.executeForm(shform);

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
