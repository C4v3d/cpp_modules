#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av) {
	Harl	harl;

	switch (ac) {
		case 2:
			harl.complain(av[1]);
			break;
		default:
			std::cout << "Wrong number of arguments" << std::endl;
	}

	return (0);
}
