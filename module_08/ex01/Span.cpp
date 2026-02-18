#include "Span.hpp"
#include <iostream>

Span::Span(): _n(3) {}

Span::Span(unsigned int const & N): _n(N) {}
Span::Span(Span const & other) { *this = other; }
Span& Span::operator=(Span const & other) {
  if (this != &other) {
    this->_n = other._n;
    this->_arr = other._arr;
  }
  return (*this);
}
Span::~Span() {}

void  Span::addNumber(int const & num) {
  std::cout << "num: " << num << std::endl;
}
