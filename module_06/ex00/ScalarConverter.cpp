#include "ScalarConverter.hpp"
#include "templates.hpp"

#include <cstddef>
#include <string>
#include <cstdlib>

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter const & other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const & other) {return ((void)other, *this);}

ScalarConverter::~ScalarConverter() {};

std::string	ScalarConverter::trim(std::string const & s) {
	std::string	ret(s);

	ret.erase(0,ret.find_first_not_of(" \n\r\t"));
	ret.erase(ret.find_last_not_of(" \n\r\t") + 1);
	return (ret);
}

static t_type	type_id(std::string const & str) {
	if ((str == "nan" || str == "nanf")
		|| (str == "inf" || str == "-inf")
		|| (str == "inff" || str == "-inff"))
		return (DOUBLE);
	if (str.find_first_of('.') != str.npos) {
		if (str.find_last_of('f') != str.npos)
			return (FLOAT);
		else
			return (DOUBLE);
	}
	else {
		if (str.size() == 1 && std::isprint(str[0]) && str[0] > '9')
			return (CHAR);
		else if (str.find_first_not_of("-1234567890") == str.npos)
			return (INT);
	}
	return (UNKNOWN);
}

void	convertInt(std::string & s) {
	double	tmp = std::strtod(s.c_str(), NULL);
	int	res = 0;
	::dynamicConversion(tmp, res);
}

void	convertDouble(std::string & s) {
	double	tmp;
	double	res = 0;

	if (s == "inf" || s == "inff")
		printInf(0);
	else if (s == "-inf" ||s == "-inff")
		printInf(1);
	else if (s == "nan" || s == "nanf")
		printN(s);
	else {
		decimalFormatChecker(s, DOUBLE);
		tmp = std::strtod(s.c_str(), NULL);
		::dynamicConversion(tmp, res);
	}
}

void	convertFloat(std::string & s) {
	double	tmp;
	float res = 0;

	decimalFormatChecker(s.c_str(), FLOAT);
	tmp = std::strtod(s.c_str(), NULL);
	::dynamicConversion(tmp, res);
}



void	ScalarConverter::convert(std::string const & s) {
	if (s.empty()) {
		std::cout << "String empty" << std::endl;
		return ;
	}
	std::string	tmp(trim(s));
	try {
		switch (type_id(tmp)) {
			case CHAR:
				::printConversions(*s.begin());
				break;
			case INT:
				convertInt(tmp);
				break;
			case FLOAT:
				convertFloat(tmp);
				break;
			case DOUBLE:
				convertDouble(tmp);
				break;
			default:
				std::cout << "Unknown type !" << std::endl;
		}
	}
	catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

const char*	ScalarConverter::valueTooLargeException::what() const throw() { return ("Value is too big"); }
const char*	ScalarConverter::incorrectFormatException::what() const throw() { return ("Incorrect format"); }
const char*	ScalarConverter::impossibleConversionException::what() const throw() { return ("Conversion is impossible"); }
