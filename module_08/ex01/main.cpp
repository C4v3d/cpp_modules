#include "Span.hpp"
#include <iostream>
#include <cstdlib>

void  basic(void) {
  Span  span1(3);

  std::cout << "span1: \n" << std::endl;
  std::cout << span1 << std::endl;
  try {
    span1.addNumber(42);
  } catch(std::exception & e) { std::cout << e.what() << std::endl; }
  std::cout << span1 << std::endl;
  try {
    span1.addNumber(3);
    span1.addNumber(1);
  } catch (std::exception & e) { std::cout << e.what() << std::endl; }
  std::cout << span1 << std::endl;
  std::cout << "Trying to add more value than the max size" << std::endl;
  try {
    span1.addNumber(4);
  } catch(std::exception & e) { std::cout << e.what() << std::endl; }
  std::cout << span1 << std::endl;
  std::cout << "Longest span: " << span1.longestSpan() << std::endl;
  std::cout << "Shortest span: " << span1.shortestSpan() << std::endl;
  std::cout << "Shortest and longest Span with empty or only 1 element" << std::endl;
  Span  span2(10);
  try {
    std::cout << "longest span: " << span2.longestSpan() << std::endl;
  } catch (std::exception & e) { std::cout <<  e.what() << std::endl; }
  try {
    std::cout << "Shortest span: " << span2.shortestSpan() << std::endl;
  } catch (std::exception & e) { std::cout <<  e.what() << std::endl; }
  try {
    span2.addNumber(2);
    span2.longestSpan();
  } catch (std::exception & e) { std::cout << e.what() << std::endl; }

  std::cout << "With negative values !" << std::endl;
  Span n(3);

  n.addNumber(-1);
  n.addNumber(-42);
  n.addNumber(32);

  std::cout << n << std::endl;
  std::cout << "longest Span: " << n.longestSpan() << std::endl;
  std::cout << "shortestSpan: " << n.shortestSpan() << std::endl;
}

void  multipleAdd(void) {
  Span  span(1);
  std::vector<int> v(100, 1);
  try {
    span.multiAdd(v.begin(), v.end());
  } catch (std::exception & e) { std::cout << e.what() << std::endl; }
  std::cout << span << std::endl;
  Span  span1(100);
  try {
    span1.multiAdd(v.begin(), v.end());
  } catch (std::exception & e) { std::cout << e.what() << std::endl; }
  std::cout <<  span1 << std::endl;
}

void  hugeSpan(void) {
  Span span(100000);
  std::vector<int>  v;
  for(int i = 0; i < 100000; i++) {
      v.push_back(rand());
  }
  span.multiAdd(v.begin(), v.end());
  std::cout << "Biggest span: " << span.longestSpan() << std::endl;
  std::cout << "smallest span: " << span.shortestSpan() << std::endl;
}

int main(void) {
  basic();
  multipleAdd();
  hugeSpan();
}

