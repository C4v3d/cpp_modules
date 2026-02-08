#include "Base.hpp"
#include <iostream>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void) {
	srand(time(0));
	int	r = rand() % 3;

	std::cout << r << std::endl;
	switch(r) {
		case 0:
			return (new(A));
			break;
		case 1:
			return (new(B));
			break;
		default:
			return (new(C));
	}
}

void	identify(Base * p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else
		std::cout << "Type is C" << std::endl;
}

void identify(Base & p) {
	Base *base = &p;
	if (dynamic_cast<A*>(base))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(base))
		std::cout << "Type is B" << std::endl;
	else
		std::cout << "Type is C" << std::endl;

}

int	main(void) {
	Base *base = generate();
	Base &rBase = *base;

	identify(base);
	identify(rBase);
	delete(base);
	return (0);
}
