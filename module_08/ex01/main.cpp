#include "Span.hpp"
#include <iostream>

int main(void) {
	Span  span1;
	 std::cout << "Creating span instance with default constructor." << std::endl;
	 std::cout << span1 << std::endl;
	 std::cout << "Adding value [3]." << std::endl;
	 try {
		span1.addNumber(3);
	 } catch (std::exception & e) { std::cout << e.what() << std::endl; }
	 std::cout << span1 << std::endl;
	 std::cout << "Adding second value [5]" << std::endl;
	 try {
	   	span1.addNumber(5);
	 } catch (std::exception & e) { std::cout << e.what() << std::endl; }
	 std::cout << "adding last value [42]" << std::endl;
	 try {
	   	span1.addNumber(42);
	 } catch (std::exception & e) { std::cout << e.what() << std::endl; }
	 std::cout << span1 << std::endl;
	 std::cout << "Trying to add a value even tho the buffer is full" << std::endl;
	 try {
	   	span1.addNumber(9);
	 } catch (std::exception & e) { std::cout <<  e.what() << std::endl; }
	 std::cout << span1 << std::endl;
	span1.longestSpan();
  span1.shortestSpan();
}
