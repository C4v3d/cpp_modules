#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void) {

	try {
		Bureaucrat	john("John", 43);
		Form		form("sign this", 40, 40);

		std::cout << john << std::endl;
		std::cout << form << std::endl;

		john.signForm(form);

		std::cout << form << std::endl;

		Bureaucrat	billy(john);
		billy.signForm(form);
		for (int i = 0; i < 10; i++)
			billy.incrGrade();
		billy.signForm(form);
		std::cout << form << std::endl;
		john.signForm(form);

		Form wrongForm("wrongForm", 2, 400);

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
