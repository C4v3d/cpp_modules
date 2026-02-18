#include "Span.hpp"
#include <iostream>

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
