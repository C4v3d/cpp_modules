#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
	std::cout << "Creating FragTrap: " << name << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
};

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
	*this = other;
	std::cout << "Creating FragTrap from: " << other._name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cout << "Copying data from : " << other._name << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "Destroying FragTrap: " << this->_name << std::endl;
};

void	FragTrap::highFivesGuys(void) {
	std::cout << "Yay ! Hightfive !" << std::endl;
}
