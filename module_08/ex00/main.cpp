#include <iostream>
#include <vector>
#include <stack>
#include <list>

#include "easyfind.hpp"


void	find_vector() {
	std::cout << "Vector Basic test" << std::endl;
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	std::vector<int>::iterator it = ::easyfind(v1, 2);
	if (it == v1.end())
		std::cout << "Not found..." << std::endl;
	else {
		std::cout <<  "Found !" << std::endl;
	}

	std::cout << "Empty stack" << std::endl;
	std::vector<int> v2;
	std::vector<int>::iterator empty = ::easyfind(v2, 4);
	if (empty == v2.end())
		std::cout << "Not found..." << std::endl;
	else
		std::cout << "Found !" << std::endl;
}

void	find_deque() {
	std::cout << "Stack basic test" << std::endl;
	std::deque<int> deque1;
	deque1.push_back(32);
	deque1.push_back(3);
	deque1.push_back(42);
	std::deque<int>::iterator it = ::easyfind(deque1, 42);
	if (it == deque1.end())
		std::cout << "Not found..." << std::endl;
	else
		std::cout << "Found !" << std::endl;
	std::cout << "Empty deque" << std::endl;
	std::deque<int> empty;
	std::deque<int>::iterator emptyit = ::easyfind(empty, 33);
	if (emptyit == empty.end())
		std::cout << "Not found..." << std::endl;
	else
		std::cout << "Found !" << std::endl;
}

void	find_list() {
	std::cout << "list basic test" << std::endl;
	std::list<int> lst1;
	lst1.push_back(3);
	lst1.push_back(234);
	lst1.push_back(2239);
	lst1.push_back(0);
	lst1.push_back(1);
	std::list<int>::iterator it = ::easyfind(lst1, 0);
	if (it == lst1.end())
		std::cout << "Not found..." << std::endl;
	else
		std::cout << "Found !" << std::endl;
	std::cout << "Empty list" << std::endl;
	std::list<int> empty;
	std::list<int>::iterator emptyit = ::easyfind(empty, 33);
	if (emptyit == empty.end())
		std::cout << "Not found..." << std::endl;
	else
		std::cout << "Found !" << std::endl;

}

int	main(void) {
	find_vector();
	find_deque();
	find_list();
}
