#include "ScalarConverter.hpp"

#include <iostream>
#include <string>

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Wrong number of argument(s)" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
