#include "Bureaucrat.hpp"
#include <iostream>

int	main(void) {

	std::cout << "\ninit Bureaucrat a" << std::endl;
	Bureaucrat	a("George", 5);
	std::cout << a << std::endl;
	std::cout << "George is now CEO !" << std::endl;
	for (int i = 0; i < 4; i++)
		a.incrGrade();
	std::cout << a << std::endl;

	std::cout << "\ninit b as a copy of a" << std::endl;
	Bureaucrat	b(a);
	std::cout << b << std::endl;
	std::cout << "try to promote b" << std::endl;
	try {
		b.incrGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "demote b" << std::endl;
	for (int i = 0; i < 149; i++) {
		try {
			b.decrGrade();
		}
		catch (std::exception & e) {
      			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "b is now the least most important person in this enterprise" << std::endl;
	std::cout << b << std::endl;

	std::cout << "\nInit c by taking b data" << std::endl;
	Bureaucrat c = b;
	std::cout << c << std::endl;
	std::cout << "trying to demote c" << std::endl;
	try {
		c.decrGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "promote c" << std::endl;
	try {
		c.incrGrade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "\na: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "tryin to init a bureaucrat with an out of bound value" << std::endl;

	try {
		Bureaucrat	d("Stanley", 151);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}
