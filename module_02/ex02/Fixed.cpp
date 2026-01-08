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
		_fixedPoint = other._fixedPoint;
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
	return (_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	_fixedPoint = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)_fixedPoint / (float)(1 << _fractionalBits));
}

int	Fixed::toInt(void) const {
	return(_fixedPoint >> _fractionalBits);
}

/* Insert Overload */
std::ostream&	operator<<(std::ostream& output, const Fixed& fixed) {
	output << fixed.toFloat();
	return (output);
}
/* Comparison Overload */
bool	Fixed::operator<(const Fixed& other) const {
	return (_fixedPoint < other._fixedPoint);
}

bool	Fixed::operator>(const Fixed& other) const {
	return (_fixedPoint > other._fixedPoint);
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (_fixedPoint <= other._fixedPoint);
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (_fixedPoint >= other._fixedPoint);
}

bool	Fixed::operator==(const Fixed& other) const {
	return (_fixedPoint == other._fixedPoint);
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (_fixedPoint != other._fixedPoint);
}

/* Arithmetic Overload */
Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	res;
	res._fixedPoint = (_fixedPoint + other._fixedPoint) >> _fractionalBits;
	return (res);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed res;
	res._fixedPoint = (_fixedPoint - other._fixedPoint) >> _fractionalBits;
	return (res);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed res;
	res._fixedPoint = (_fixedPoint * other._fixedPoint) >> _fractionalBits;
	return (res);
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed res;
	res._fixedPoint = (_fixedPoint / other._fixedPoint) >> _fractionalBits;
	return (res);
}

Fixed&	Fixed::operator++(void) {
	_fixedPoint++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	_fixedPoint++;
	return (tmp);
}

Fixed& Fixed::operator--(void) {
	_fixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed	tmp = *this;
	_fixedPoint--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return(a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a.getRawBits() > b.getRawBits() ? a : b);
}
