#include <string>
#include <iostream>

int	main(void) {
	std::string	s = "HI THIS IS BRAIN";
	std::string*	p = &s;
	std::string&	r = s;

	std::cout << "String memory address: 		" << &s << std::endl;
	std::cout << "Memory address held by ptr:	" << p <<std::endl;
	std::cout << "Memory address held by ref:	" << &r << std::endl;

	std::cout << "Value of string variable:	" << s << std::endl;
	std::cout << "Value pointed to by ptr:	" << *p << std::endl;
	std::cout << "Value pointed to by ref:	" << r << std::endl;
	return (0);
}
