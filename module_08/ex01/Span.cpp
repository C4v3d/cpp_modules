#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(): _maxSize(3), _curSize(0) {}
Span::Span(unsigned int const & N): _maxSize(N), _curSize(0) {}
Span::Span(Span const & other) { *this = other; }
Span& Span::operator=(Span const & other) {
  if (this != &other) {
    this->_maxSize = other._maxSize;
    this->_curSize = other._curSize;
    this->vec = other.vec;
  }
  return (*this);
}
Span::~Span() {}

const unsigned int& Span::getCurSize() const { return this->_curSize; }

const unsigned int& Span::getMaxSize() const { return this->_maxSize; }

void  Span::addNumber(int const & num) {
  if (_curSize >= this->_maxSize)
    throw Span::VecIsFullException();
  this->vec.push_back(num);
  this->_curSize++;
}

void	Span::longestSpan() const {
	if  (vec.empty() || _curSize == 1)
		throw ;
	std::vector<int>::const_iterator begin = vec.begin();
	std::vector<int>::const_iterator end = vec.end();
	std::cout << "Biggest Span: " << *(std::max_element(begin, end)) - *(std::min_element(begin, end)) << std::endl;
}

void  Span::shortestSpan() const {
  if (vec.empty() || _curSize == 1)
    throw ;
  std::vector<int>::const_iterator begin = vec.begin();
  std::vector<int>::const_iterator end = vec.end();
  std::vector<int>::const_iterator smallest = std::min_element(begin, end);
  std::vector<int>::const_iterator tmp = std::min_element(smallest + 1, end);
  std::cout << "Smallest: " << *smallest << std::endl;
  std::cout << "tmp: " << *tmp << std::endl;
  std::cout << "Smallest Span: " << *(tmp) - *(smallest) << std::endl;

}

const char* Span::VecIsFullException::what() const throw() { return "Vec is vect.full" ;}

std::ostream& operator<<(std::ostream & os, Span s) {
  std::vector<int>::iterator end = s.vec.end();
  os << "Max size: " << s.getMaxSize();
  os << " Current size: " << s.getCurSize() << "\n";
  for (std::vector<int>::iterator it = s.vec.begin(); it != end; it++)
    os << *it << ' ';
  os << '\n';
  return os;
}
