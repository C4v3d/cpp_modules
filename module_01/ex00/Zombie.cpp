#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void): _name("Daryl") {
}

Zombie::Zombie(std::string name): _name(name) {
}

Zombie::~Zombie(void) {
	std::cout << this->_name << ": has been killed..." << std::endl;
}

void	Zombie::announce() const{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
