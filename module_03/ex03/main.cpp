#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void) {
	DiamondTrap	a("Rick");

	a.attack("someone");
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
}
