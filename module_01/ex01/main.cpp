#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void) {
	int	nZombie = 5;

	Zombie*	horde = zombieHorde(nZombie, "test");
	for (int i = 0; i < nZombie; i++) {
		horde[i].announce();
	}
	delete[] horde;
}
