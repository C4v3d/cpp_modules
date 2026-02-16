#include "Array.hpp"
#include "Foo.hpp"
#include <iostream>

int	main(void) {
	Array<int>		intArray(5);
	Array<long>		longArray(4);
	Array<char>		charArray(3);
	Array<std::string>	strArray(2);
	Array<Foo>		fooArray(1);

	std::cout << "Size of intArray: " << intArray.getSize() << std::endl;
	std::cout << "Size of longArray: " << longArray.getSize() << std::endl;
	std::cout << "Size of charArray: " << charArray.getSize() << std::endl;
	std::cout << "Size of strArray: " << strArray.getSize() << std::endl;
	std::cout << "Size of fooArray: " << fooArray.getSize() << std::endl;

	std::cout << "intArray: " << intArray << std::endl;
	std::cout << "longArray: " << longArray << std::endl;
	std::cout << "charArray: " << charArray << std::endl;
	std::cout << "strArray: " << strArray << std::endl;
	std::cout << "fooArray: " << fooArray << std::endl;

	// Acces an index out of rang
	try {
		std::cout << "trying to acces index 42: " << intArray[42] << std::endl;
	} catch (std::exception & e) { std::cout << e.what() << std::endl; }

	// Set value to an out of range index
	try {
		std::cout << "Setting value 42 at index 4" << std::endl;
		longArray[4] = 42;
	} catch (std::exception & e) { std::cout << e.what() << std::endl; }

	// Setting value to intArray
	for (unsigned int i = 0; i < intArray.getSize(); i++) {
		intArray[i] = i;
	}
	std::cout << "intArray: " << intArray << std::endl;
	
	// Creating New array from intArray
	Array<int>	cpyArray(intArray);
	cpyArray[2] = 42;
	std::cout << "intArrat: " << intArray << std::endl;
	std::cout << "cpyArray: " << cpyArray << std::endl;

	strArray[0] = "Hello";
	strArray[1] = "World!";

	std::cout << "strArray: " << strArray << std::endl;

	Array<std::string>	strArray2;

	std::cout << "strArray2: " << strArray2 << std::endl;
	strArray2 = strArray;
	strArray[0] = "Bla";
	strArray[1] = "Blu";
	std::cout << "strArray2: " << strArray2 << std::endl;
}
