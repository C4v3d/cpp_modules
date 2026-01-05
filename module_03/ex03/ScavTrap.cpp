#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string name): ClapTrap(name) {
	std::cout << "Creating ScavTrap: " << name << " from ClapTrap" << std::endl;
	this->_hitPoints = _defHitPoints;
	this->_energyPoints = _defEnergyPoints;
	this->_attackDamage = _defAttackDamage;

}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other){
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Destroying ScavTrap: " << this->_name << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << "WOW " << this->_name << " is attacking " << target << " dealing an absurd amount of damage ! (" << this->_attackDamage << ")" << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << this->_name << " is in keeper mode" << std::endl;
}
