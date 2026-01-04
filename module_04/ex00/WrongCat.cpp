#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("WrongCat") {
	std::cout << "Default Wrong cat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other.type) {
	std::cout << "Wrong Cat copy constructor called" << std::endl;
	*this = other;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout << "Wrong Cat copy assignement called" << std::endl; 
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "Wrong cat default destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Bzzzz Bzzzz..." << std::endl;
}

