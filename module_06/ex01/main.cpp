#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int	main(void) {
	Data		data;
	Data		*p = &data;
	Data		*p2;
	uintptr_t	serializedData;

	p->i = 42;
	std::cout << "p is pointing at address: " << p << " With value: " << p->i << std::endl;
	serializedData = Serializer::serialize(p);
	std::cout << "Data has been serialized in serializedData: " << serializedData << std::endl;

	std::cout << "Deserializing in p2" << std::endl;
	p2 = Serializer::deserialize(serializedData);
	std::cout << "p2 is pointing at address: " << p2 << " With value: " << p2->i << std::endl;


	std::cout << "Checking if addresses match" << std::endl;

	if (p == p2)
		std::cout << "Great !" << std::endl;
	else
		std::cout << "failed !" << std::endl;
	return (0);
}
