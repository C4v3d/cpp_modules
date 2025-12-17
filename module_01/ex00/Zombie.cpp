#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void): _name("Daryl") {
}

Zombie::Zombie(std::string name): _name(name) {
}

Zombie::Zombie(const Zombie &other): _name(other._name) {
}

Zombie &Zombie::operator=(const Zombie &other) {
	if (this != &other) {
		this->_name = other._name;
	}
	return (*this);
}

Zombie::~Zombie(void) {
	std::cout << this->_name << ": has been killed..." << std::endl;
}

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
