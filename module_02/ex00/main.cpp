#include "Fixed.hpp"
#include <iostream>

int	main(void) {

	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "Setting a to 8" << std::endl;
	a.setRawBits(8);
	std::cout << a.getRawBits() << std::endl;

	return (0);
}
