#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void) {

	try {
		Bureaucrat	john("John", 43);
		std::cout << john << std::endl;
		Bureaucrat	billy(john);
		for (int i = 0; i < 10; i++)
			billy.incrGrade();
		ShrubberyCreationForm	forma("test");
		
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
