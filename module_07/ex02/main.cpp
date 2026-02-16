#include "Array.hpp"
#include <iostream>

int	main(void) {
	Array<int>		intArray(5);
	Array<long>		longArray(4);
	Array<char>		charArray(3);
	Array<std::string>	strArray(2);

	std::cout << "Size of intArray: " << intArray.getSize() << std::endl;
	std::cout << "Size of longArray: " << longArray.getSize() << std::endl;
	std::cout << "Size of charArrey: " << charArray.getSize() << std::endl;
	std::cout << "Size of strArrey: " << strArray.getSize() << std::endl;

	// Acces an index out of rang
	try {
		std::cout << "trying to acces index 42: " << intArray[42] << std::endl;
	} catch (std::exception & e) { std::cout << e.what() << std::endl; }
}
