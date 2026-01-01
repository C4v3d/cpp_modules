#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	a("Bob");

	std::cout << a << std::endl;

	for (int i = 0; i < 5; i++) {
		a.attack("John");
	}

	std::cout << a << std::endl;
	return (0);
}
