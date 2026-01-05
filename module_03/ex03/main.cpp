#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void) {
	DiamondTrap	a("Rick");
	
	std::cout << a << std::endl;
	a.attack("someone");
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
}
