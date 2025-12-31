#include "Fixed.hpp"
#include <iostream>

int	main(void) {

	Fixed	a(2.2f);
	Fixed	b(1);

	if (a < b)
		std::cout << "A is smaller than b" << std::endl;
	return (0);
}
