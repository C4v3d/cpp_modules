#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	a("Bob");
	std::cout << a << std::endl;

	std::cout << "Bob attack 5 times" << std::endl;
	for (int i = 0; i < 5; i++) {
		a.attack("John");
	}
	std::cout << a << std::endl;

	std::cout << "Bob takes 5 damage" << std::endl;
	a.takeDamage(5);
	std::cout << a << std::endl;

	std::cout << "Bob repairs itself 5 times for 1 HP" << std::endl;
	for (int i = 0; i < 5; i++)
		a.beRepaired(1);
	std::cout << a << std::endl;

	std::cout << "Bob attack but has no energy left" << std::endl;
	a.attack("John");
	std::cout << a << std::endl;

	std::cout << "Bob repairs but has no energy left" << std::endl;
	a.beRepaired(100);
	std::cout << a << std::endl;

	std::cout << "Bob takes 25 damage" << std::endl;
	a.takeDamage(25);
	std::cout << a << std::endl;

	std::cout << "Bob repairs but is dead" << std::endl;
	a.beRepaired(50);

	std::cout << "Bob attack but is dead" << std::endl;
	a.attack("John");

	std::cout << a << std::endl;

	return (0);
}
