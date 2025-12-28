#include "Fixed.hpp"
#include <iostream>

int	main(void) {

	Fixed	a(13);

	std::cout << a.getRawBits() << std::endl;
	return (0);
}
