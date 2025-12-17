#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);

int	main(void) {
	Zombie *z = newZombie("test");
	(void)z;
	return (0);
}
