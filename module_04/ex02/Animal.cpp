#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
	std::cout << "Default animal constructor called" << std::endl;
}

Animal::Animal(const std::string& animalType): type(animalType) {
}

Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal& other) {
	std::cout << "Copy assignement animal called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const {
	return (this->type);
}

void	Animal::makeSound(void) const {
}
