#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

/* Use `c` member object to access underlying container
 * The stack "underlying container" is deque by default,
 * but can be a vector or a list as well. */

template < typename T, typename container = std::deque<T> >
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(MutantStack const & other);
	~MutantStack();

	typedef typename container::iterator	it;

	it	begin();
	it	end();
};

template < typename T, typename Container = std::deque<T> >
MutantStack::MutantStack(): std::stack<T>::stack() {}

template < typename T, typename Container = std::deque<T> >
MutantStack::MutantStack(MutantStack const & other): std::stack<T>::stack(other) {}

template < typename T, typename Container = std::deque<T> >
MutantStack::~MutantStack() {}

template < typename T, typename Container = std::deque<T> >
it	MutantStack::begin() { return (this->c.being()); }

template < typename T, typename Container = std::deque<T> >
it	MutantStack<T>::end() { return (this->c.end()); }

#endif
