#include "Span.hpp"
#include <iostream>

int main(void) {
	Span  span1(3);

  /* Basic tests */
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
  /*--------*/
  /* Basic methods */
  std::cout << "Longest span: " << span1.longestSpan() << std::endl;
  std::cout << "Shortest span: " << span1.shortestSpan() << std::endl;
}
