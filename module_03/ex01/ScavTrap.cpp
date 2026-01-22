#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(const std::string name): ClapTrap(name) {
	std::cout << "Creating ScavTrap: " << name << " from ClapTrap" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) {
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other){
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "Destroying ScavTrap: " << _name << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	std::cout << "WOW " << _name << " is attacking " << target << " dealing an absurd amount of damage ! (" << this->_attackDamage << ")" << std::endl;
}

void	ScavTrap::guardGate(void) const {
	std::cout << _name << " is in keeper mode" << std::endl;
}
