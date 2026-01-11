#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void) {

	try {
		Bureaucrat	bur("Billy", 43);
		Form		form("sign this", 40, 40);

		std::cout << bur << std::endl;
		std::cout << form << std::endl;

		bur.signForm(form);

		std::cout << form << std::endl;

	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
