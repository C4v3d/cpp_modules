#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = other._fixedPoint;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other._fixedPoint;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) {
	return (this->_fixedPoint);
}
