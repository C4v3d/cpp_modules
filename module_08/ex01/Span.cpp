#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <stdexcept>	

Span::Span():
  _maxSize(3)
{}

Span::Span(unsigned int const & N):
  _maxSize(N)
{}

Span::Span(Span const & other) { *this = other; }
Span& Span::operator=(Span const & other) {
  if (this != &other) {
    _maxSize = other._maxSize;
    vec = other.vec;
  }
  return (*this);
}
Span::~Span() {}

void  Span::addNumber(int const & num) {
  if (vec.size() >= _maxSize)
    throw std::overflow_error("overflow");
  vec.push_back(num);
  std::cout << "Value added !" << std::endl;
}

void	Span::multiAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
  unsigned int len = std::distance(begin, end);
	if (vec.size() + len > _maxSize)
    throw std::overflow_error("single overflow");
	vec.insert(vec.end(), begin, end);
  std::cout << "Values inserted !" << std::endl;
}

int	Span::longestSpan() const {
	if  (vec.empty() ||  vec.size() == 1)
		throw std::out_of_range("Not enough element for a comparison.");
  std::vector<int>::const_iterator begin = vec.begin();
	std::vector<int>::const_iterator end = vec.end();
  return (*(std::max_element(begin, end)) - *(std::min_element(begin, end)));
}

int Span::shortestSpan() const {
  if (vec.empty() || vec.size() == 1)
    throw std::out_of_range("Not enough element for a comparison.");
  std::vector<int>  tmp(vec);
  std::sort(tmp.begin(), tmp.end());
  std::vector<int>::iterator smallest = std::min_element(tmp.begin(), tmp.end());
  return (*std::min_element(smallest + 1, tmp.end()) - *smallest);
}

std::ostream& operator<<(std::ostream & os, Span s) {
  std::vector<int>::iterator end = s.vec.end();
  for (std::vector<int>::iterator it = s.vec.begin(); it != end; it++)
    os << *it << ' ';
  os << '\n';
  return os;
}
