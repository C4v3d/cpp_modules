#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _fixedPoint(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignement operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other._fixedPoint;
	return (*this);
}

Fixed::Fixed(const int value): _fixedPoint(value << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value): _fixedPoint(roundf(value * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)this->_fixedPoint / (float)(1 << _fractionalBits));
}

int	Fixed::toInt(void) const {
	return(this->_fixedPoint >> _fractionalBits);
}

/* Insert Overload */
std::ostream&	operator<<(std::ostream& output, const Fixed& fixed) {
	output << fixed.toFloat();
	return (output);
}
/* Comparison Overload */
bool	Fixed::operator<(const Fixed& other) const {
	return (this->_fixedPoint < other._fixedPoint);
}

bool	Fixed::operator>(const Fixed& other) const {
	return (this->_fixedPoint > other._fixedPoint);
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (this->_fixedPoint <= other._fixedPoint);
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (this->_fixedPoint >= other._fixedPoint);
}

bool	Fixed::operator==(const Fixed& other) const {
	return (this->_fixedPoint == other._fixedPoint);
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (this->_fixedPoint != other._fixedPoint);
}

/* Arithmetic Overload */
Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	res = this->_fixedPoint + other._fixedPoint;
	return (res);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed res = this->_fixedPoint - other._fixedPoint;
	return (res);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed res = this->_fixedPoint * other._fixedPoint;
	return (res);
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed res = this->_fixedPoint / other._fixedPoint;
	return (res);
}

Fixed&	Fixed::operator++(void) {
	this->_fixedPoint++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	this->_fixedPoint++;
	return (tmp);
}

Fixed& Fixed::operator--(void) {
	this->_fixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed	tmp = *this;
	this->_fixedPoint--;
	return (tmp);
}
