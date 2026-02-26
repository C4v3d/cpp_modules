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

	typedef typename MutantStack<T>::container_type::iterator	iterator;
	typedef typename MutantStack<T>::container_type::const_iterator	const_iterator;
	typedef typename MutantStack<T>::container_type::reverse_iterator	reverse_iterator;
	typedef typename MutantStack<T>::container_type::const_reverse_iterator	const_reverse_iterator;


	iterator		begin();
	iterator		end();
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_iterator		cbegin() const;
	const_iterator		cend() const;
	const_reverse_iterator		crbegin() const;
	const_reverse_iterator		crend() const;
};


template < typename T >
MutantStack<T>::MutantStack(): std::stack<T>::stack() {}

template < typename T >
MutantStack<T>::MutantStack(MutantStack const & other): std::stack<T>::stack(other) {}

template < typename T >
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const & other) {
	if (this != &other) {}
	return *this;
}

template < typename T >
MutantStack<T>::~MutantStack() {}

template < typename T >
typename MutantStack<T>::iterator		MutantStack<T>::begin() { return this->c.begin(); }

template < typename T >
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rbegin() { return this->c.rbegin(); }

template < typename T >
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin() const { return this->c.rbegin(); }

template < typename T >
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin() const { return this->c.begin(); }


template < typename T>
typename MutantStack<T>::iterator		MutantStack<T>::end() { return this->c.end(); }

template < typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend() const { return this->c.end(); }

template < typename T>
typename MutantStack<T>::reverse_iterator		MutantStack<T>::rend() { return this->c.rend(); }

template < typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend() const { return this->c.rend(); }

#endif
