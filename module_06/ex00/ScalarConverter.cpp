#include "ScalarConverter.hpp"

#include <string>
#include <iostream>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter const & other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const & other) {return ((void)other, *this);}

ScalarConverter::~ScalarConverter() {};

/* Converter */

void ScalarConverter::convert(std::string const & str) {
	std::cout << str << std::endl;
}
