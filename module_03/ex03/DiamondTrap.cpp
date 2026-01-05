#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	std::cout << "creating DiamondTrap: " << name << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_defHitPoints;
	this->_energyPoints = ScavTrap::_defEnergyPoints;
	this->_attackDamage = FragTrap::_defAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "Calling DiamonTrap Copy Constructor" << std::endl;
	*this = other;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "calling Diamond Trap Copy assignement" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "Destroying: " << this->_name << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "ClapTrap name: " << ClapTrap::_name << "\nDiamondTrap name: " << this->_name << std::endl;
}
