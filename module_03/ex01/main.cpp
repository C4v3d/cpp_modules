#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main(void) {
	ScavTrap	a("Bob");
	ClapTrap	b("John");
	
	ScavTrap	c(a);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	
	a.attack("someone");
	c.takeDamage(10);
	std::cout << c << std::endl;

	return (0);
}
