#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void): _name("Robert") {
	this->announce();
}

Zombie::Zombie(std::string name): _name(name) {
	this->announce();
}

Zombie::Zombie(const Zombie &other): _name(other._name) {
	this->announce();
}

Zombie &Zombie::operator=(const Zombie &other) {
	this->announce();
	if (this != &other) {
		this->_name = other._name;
	}
	return (*this);
}

Zombie::~Zombie(void) {
}

void	Zombie::announce() {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
