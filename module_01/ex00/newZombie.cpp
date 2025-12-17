#include "Zombie.hpp"
#include <iostream>
#include <new>

Zombie	*newZombie(std::string name) {
	Zombie	*zombie;

	try {
		zombie = new Zombie(name);
		return (zombie);
	}
	catch (const std::bad_alloc& e) {
		std::cout << "Memory Allocation failed" << std::endl;
		return (NULL);
	}
}

