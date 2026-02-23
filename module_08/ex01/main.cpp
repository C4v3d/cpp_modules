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
  /* ------------ */
}
