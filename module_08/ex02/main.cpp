#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	deque_test() {
	MutantStack<int> mutant;
	mutant.push(3);
	mutant.push(34);
	mutant.push(42);

	for (std::deque<int>::iterator it = mutant.begin();
		it != mutant.end(); it++)
		std::cout << *it << std::endl;
}

void	list_check() {
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(mstack);
}

int main(void) {
	std::cout << "Begin Basic tests" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "Begin deque tests" << std::endl;
	deque_test();
	std::cout << "Begin list tests" << std::endl;
	list_check();
	return (0);
}

