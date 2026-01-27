#include "ScalarConverter.hpp"

#include <string>
#include <iostream>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter const & other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const & other) {return ((void)other, *this);}

ScalarConverter::~ScalarConverter() {};

/* Converter */

static t_type	type_id(std::string const & str) {
	
	if (str.find_first_of('.') != str.npos) {
		if (str.find_last_of('f') != str.npos) {
			std::cout << "Float" << std::endl;
			return (FLOAT);
		}
		else {
			std::cout << "DOUBLE" << std::endl;
			return (DOUBLE);
		}
	}
	else {
		if (str.size() == 1 && std::isalpha(str[0])) {
      			std::cout << "Char" << std::endl;
			return (CHAR);
		}
		else if (str.find_first_not_of("-1234567890") == str.npos) {
			std::cout << "Int" << std::endl;
			return (INT);
		}
	}
	std::cout << "Unknown" << std::endl;
	return (UNKNOWN);
}

void	ScalarConverter::convert(std::string const & str) {
	t_type	inputType;
	if (str.empty()) {
		std::cout << "String empty" << std::endl;
		return ;
	}
	inputType = type_id(str);
}
