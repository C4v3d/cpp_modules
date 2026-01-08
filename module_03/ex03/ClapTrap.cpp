#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10),
			_energyPoints(10), _attackDamage(0){
	std::cout << "Creating ClapTrap: " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "Creating ClapTrap: " << this->_name << " as a copy of: " << other._name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copying: " << other._name << " to: " << this->_name << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return(*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destroying ClapTrap: "<< this->_name << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_hitPoints == 0) {
		std::cout << "This ClapTrap is dead." << std::endl;
		return ;
	}
	try {
		if (this->_energyPoints > 0) {
			std::cout << this->_name << " is attacking " << target << " causing " << this->_attackDamage << " damage !" << std::endl;
			this->_energyPoints--;
		}
		else {
			throw (this->_energyPoints);
		}
	}
	catch (unsigned int energyLeft) {
		std::cout << this->_name << " has " << energyLeft << " energy left, it cannot perform this action." << std::endl; }
}

void	ClapTrap::takeDamage(unsigned int amount) {
	try {
		if (this->_hitPoints > 0) {
			std::cout << this->_name << " takes " << amount << " damage !" << std::endl;
			if (this->_hitPoints - amount < this->_hitPoints)
				this->_hitPoints -= amount;
			else
				this->_hitPoints = 0;
		}
		else {
			throw (this->_hitPoints);
		}
	}
	catch (unsigned int pointLeft) {
		std::cout << this->_name << " has " << pointLeft << "HP, he is already dead !" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << "This ClapTrap is dead." << std::endl;
		return ;
	}
	try {
		if (this->_energyPoints > 0){
			std::cout << this->_name << " gained " << amount << "HP !" << std::endl;
			this->_hitPoints += amount;
			this->_energyPoints--;
		}
		else {
			throw (this->_energyPoints);
		}
	}
	catch (unsigned int pointLeft) {
		std::cout << this->_name << " has " << pointLeft << " energy left, it cannot perform this action." << std::endl;
	}
}
