#include "Weapon.hpp"
#include <string>

Weapon::Weapon() {
}

Weapon::Weapon(std::string type): _type(type){
}

Weapon::~Weapon() {
}

std::string& Weapon::getType(void) {
	return(this->_type);
}

void	Weapon::setType(const std::string type) {
	this->_type = type;
}
