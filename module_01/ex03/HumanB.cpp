#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name): _name(name) {
}

HumanB::~HumanB() {
}

void	HumanB::attack() const {
	std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}
