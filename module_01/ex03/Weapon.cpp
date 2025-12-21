#include "Weapon.hpp"
#include <string>

#include <iostream>

Weapon::Weapon() {
}

Weapon::Weapon(std::string type): _type(type){
}

Weapon&	Weapon::operator=(const Weapon& other) {
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

Weapon::~Weapon() {
}

std::string& Weapon::getType(void) {
	return(this->_type);
}

void	Weapon::setType(const std::string type) {
	this->_type = type;
}
