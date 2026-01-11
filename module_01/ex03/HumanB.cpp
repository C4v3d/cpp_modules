#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name): _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {
}

void	HumanB::attack() const {
	if (_weapon == NULL) {
		std::cout << "Can't attacks with no weapon" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}
