#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int	main(void) {

	try {
		Bureaucrat	john("John", 10);
		ShrubberyCreationForm	shrub("park");
		RobotomyRequestForm	robotomy("Steve");
		PresidentialPardonForm	pardon("Mark");

		std::cout << john << std::endl;

		/*	Shurbbery Form	*/
		std::cout << "John tries to execute shrub form" << std::endl;
		john.executeForm(shrub);	
		std::cout << "John tries to sign the form" << std::endl;
		john.signForm(shrub);
		std::cout << "Now john can execute the form" << std::endl;
		john.executeForm(shrub);

		/*	Robotomy Form	*/
		std::cout << "John tries to execute robotmy form" << std::endl;
		john.executeForm(robotomy);
		std::cout << "But the form has to be sign..." << std::endl;
		john.signForm(robotomy);
		john.executeForm(robotomy);

		/*	Presidential Pardon Form	*/
		std::cout << "John tries to execute Presidential Pardon form" << std::endl;
		john.executeForm(pardon);
		std::cout << "But john hasn't learn form his mistakes... " << std::endl;
		john.signForm(pardon);
		john.executeForm(pardon);
		std::cout << "But only a true boss can execute this form" << std::endl;

		Bureaucrat	boss("BigBoss", 1);
		std::cout << "Big boss is going to execute it for him" << std::endl;
		boss.executeForm(pardon);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
