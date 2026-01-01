#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main(void) {
	FragTrap	a("Rick");

	a.highFivesGuys();
	a.attack("Negan");
	std::cout << a << std::endl;
	return (0);
}
