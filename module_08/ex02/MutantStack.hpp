#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

/* Use `c` member object to access underlying container */

template <typename T>
class MutantStack : public std::stack<T> {
public:
  MutantStack();
  MutantStack(MutantStack const & other);
  MutantStack&  operator=(MutantStack const & other);
  ~MutantStack();

  MutantStack<T>::container_type::iterator begin();
  MutantStack<T>::container_type::iterator end();
};

template <typename T>
MutantStack::MutantStack(): std::stack<T>::stack() {}
template <typename T>
MutantStack::MutantStack(MutantStack const & other): std::stack<T>::stack(other) {}
template <typename T>
MutantStack::~MutantStack() {}

template <typename T>
typename MutantStack<T>::container_type::iterator MutantStack<T>::begin() { return (this->c.being()); }
template <typename T>
typename MutantStack<T>::container_type::iterator MutantStack<T>::end() { return (this->c.end()); }

#endif
