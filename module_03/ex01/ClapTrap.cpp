#include "ClapTrap.hpp"
#include <iostream>
#include <iomanip>

ClapTrap::ClapTrap() {
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10),
			_energyPoints(10), _attackDamage(0){
	std::cout << "Creating ClapTrap: " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "Creating ClapTrap: " << _name << " as a copy of: " << other._name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copying: " << other._name << " to: " << _name << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return(*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destroying ClapTrap: "<< _name << std::endl;
}

std::ostream&	operator<<(std::ostream& output, const ClapTrap& clapTrap) {
	output << std::setw(20) << std::setfill('-') << "\n"
		<< "Name: " << clapTrap._name << "\n"
		<< "Hit point(s): " << clapTrap._hitPoints << "\n"
		<< "Energy point(s): " << clapTrap._energyPoints << "\n"
		<< "Attack damage: " << clapTrap._attackDamage << "\n"
		<< std::setw(20) << std::setfill('-') << "\n" << std::endl;
	return (output);
}

void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "This ClapTrap is dead." << std::endl;
		return ;
	}
	try {
		if (_energyPoints > 0) {
			std::cout << _name << " is attacking " << target << " causing " << _attackDamage << " damage !" << std::endl;
			_energyPoints--;
		}
		else {
			throw (_energyPoints);
		}
	}
	catch (unsigned int energyLeft) {
		std::cout << _name << " has " << energyLeft << " energy left, it cannot perform this action." << std::endl; }
}

void	ClapTrap::takeDamage(unsigned int amount) {
	try {
		if (_hitPoints > 0) {
			std::cout << _name << " takes " << amount << " damage !" << std::endl;
			if (_hitPoints - amount < _hitPoints)
				_hitPoints -= amount;
			else
				_hitPoints = 0;
		}
		else {
			throw (_hitPoints);
		}
	}
	catch (unsigned int pointLeft) {
		std::cout << _name << " has " << pointLeft << "HP, he is already dead !" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "This ClapTrap is dead." << std::endl;
		return ;
	}
	try {
		if (_energyPoints > 0){
			std::cout << _name << " gained " << amount << "HP !" << std::endl;
			_hitPoints += amount;
			_energyPoints--;
		}
		else {
			throw (_energyPoints);
		}
	}
	catch (unsigned int pointLeft) {
		std::cout << _name << " has " << pointLeft << " energy left, it cannot perform this action." << std::endl;
	}
}
