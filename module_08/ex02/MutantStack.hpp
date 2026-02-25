#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

/* Use `c` member object to access underlying container
 * The stack "underlying container" is deque by default,
 * but can be a vector or a list as well. */

template < typename T >
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(MutantStack const & other);
	MutantStack&	operator=(MutantStack const & other);
	~MutantStack();

	typedef typename MutantStack<T>::container_type::iterator	it;

	it	begin();
	it	end();
};


template < typename T >
MutantStack<T>::MutantStack(): std::stack<T>::stack() {}

template < typename T >
MutantStack<T>::MutantStack(MutantStack const & other): std::stack<T>::stack(other) {}

template < typename T >
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const & other) { return *this; }

template < typename T >
MutantStack<T>::~MutantStack() {}

template < typename T >
typename MutantStack<T>::it	MutantStack<T>::begin() { return this->c.begin(); }

template < typename T>
typename MutantStack<T>::it	MutantStack<T>::end() { return this->c.end(); }

#endif
