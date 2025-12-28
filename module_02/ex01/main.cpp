#include "Fixed.hpp"
#include <iostream>

#include <bitset>

int	main(void) {

	int	a = 13;
	std::bitset<16>	ab(a);

	std::cout << "a decimal value: " << a << std::endl;
	std::cout << "a binary value: " << ab << std::endl;

	std::cout << "Shifting !" << std::endl;

	a = a << 8;
	std::bitset<16> cb(a);
	std::cout << "a decimal value: " << a << std::endl;
	std::cout << "a binary value: " << cb << std::endl;
	return (0);
}
