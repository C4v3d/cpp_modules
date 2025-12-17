#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

int	main(void) {

	std::cout << "Creating Zombie from default constructor." << std::endl;
	Zombie	def;
	def.announce();

	std::cout << "Creating Zombie with parameter." << std::endl;
	Zombie	par("Carl");
	par.announce();

	std::cout << "Creating Zombie from newZombie function." << std::endl;
	Zombie *rick = newZombie("Rick");
	if (!rick)
		return (1);
	rick->announce();
	delete rick;

	std::cout << "Creating Zombie from randomChump." << std::endl;
	randomChump("Michonne");

	return (0);
}
