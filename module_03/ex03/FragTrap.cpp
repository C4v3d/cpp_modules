#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
	std::cout << "Creating FragTrap: " << name << std::endl;
	this->_attackDamage = _defAttackDamage;
	this->_energyPoints = _defEnergyPoints;
	this->_hitPoints = _defHitPoints; 
};

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) {
	*this = other;
	std::cout << "Creating FragTrap from: " << other._name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	std::cout << "Copying data from : " << other._name << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "Destroying FragTrap: " << this->_name << std::endl;
};

void	FragTrap::highFivesGuys(void) {
	std::cout << "Yay ! Hightfive !" << std::endl;
}
