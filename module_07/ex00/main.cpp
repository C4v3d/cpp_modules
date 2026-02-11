#include "temp.hpp"
#include <iostream>

int	main(void) {

	{
		int	a = 3;
		int	b = 15;

		std::cout << "Original a value: " << a << std::endl;
		std::cout << "Original b value: " << b << std::endl;
		std::cout << "Swaping" << std::endl;
		::swap(a, b);
		std::cout << "a value: " << a << std::endl;
		std::cout << "b value: " << b << std::endl;
		std::cout << "min value between a and b: " << ::min(a, b) << std::endl;
		std::cout << "max value between a and b: " << ::max(a, b) << std::endl;
	}
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return (0);
}
