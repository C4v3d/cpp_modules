#include "ScalarConverter.hpp"

#include <ostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>

void (*ScalarConverter::funcPtrs[4])(std::string const &) = {
	&ScalarConverter::fromChar,
	&ScalarConverter::fromInt,
	&ScalarConverter::fromFloat,
	&ScalarConverter::fromDouble
};

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter const & other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const & other) {return ((void)other, *this);}

ScalarConverter::~ScalarConverter() {};

void	ScalarConverter::fromChar(std::string const & str) {
	std::string::const_iterator  it=str.begin();
	::printConversions(*it);
}

void	ScalarConverter::fromInt(std::string const & str) {
	int	res;
	size_t	minusSign = str.find_last_of('-');

	if (minusSign > 0 && minusSign != str.npos) {
		std::cout << "Wronf integer format" << std::endl;
		return ;
	}
	if (str.size() > 10 && minusSign != 0) {
		std::cout << "Value too Large" << std::endl;
		return ;
	}
	try {
		res = safeAtoi(str);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	::printConversions<int>(res);
}

void	ScalarConverter::fromFloat(std::string const & str) {
	float	res = 0;

	if (str == "nanf") {
		printN(str);
		return ;
	}
	try {
		decimalFormatChecker(str, FLOAT);
		std::string	s(str);
		s.erase(s.find_last_of('f'));
		res = std::atof(s.c_str());
		::printConversions(res);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void	ScalarConverter::fromDouble(std::string const & str) {
	double	res;
	if (str == "nan") {
		printN(str);
		return ;
	}
	try {
		decimalFormatChecker(str, DOUBLE);
		res = std::atof(str.c_str());
		::printConversions(res);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

static t_type	type_id(std::string const & str) {

	if (str == "nan")
		return (DOUBLE);
	if (str == "nanf")
		return (FLOAT);
	if (str.find_first_of('.') != str.npos) {
		if (str.find_last_of('f') != str.npos)
			return (FLOAT);
		else
			return (DOUBLE);
	}
	else {
		if (str.size() == 1 && std::isalpha(str[0]))
			return (CHAR);
		else if (str.find_first_not_of("-1234567890") == str.npos)
			return (INT);
	}
	return (UNKNOWN);
}

static void	printInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << std::numeric_limits<int>::infinity() << std::endl;
	std::cout << "float: " << std::numeric_limits<float>::infinity() << 'f' << std::endl;
	std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
}

void	ScalarConverter::convert(std::string const & str) {
	t_type	inputType;

	if (str.empty()) {
		std::cout << "String empty" << std::endl;
		return ;
	}
	if (str == "+inff" || str == "-inff" || str == "+inf" || str == "-inf") {
		printInf();
		return ;
	}
	std::string	s(trim(str));
	inputType = type_id(s);
	if (inputType >= 0)
		(funcPtrs[inputType](s));
	else
		std::cout << "Unknown type, please enter one of these -> [int, long, double, char]." << std::endl;
}

const char*	ScalarConverter::valueTooLargeException::what() const throw() { return ("Value is too big"); }
