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
		std::cout << this->_name << " Has " << energyLeft << ", it cannot perform this action." << std::endl; }
}
