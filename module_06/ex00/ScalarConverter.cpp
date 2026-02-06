#include "ScalarConverter.hpp"

#include <cstddef>
#include <string>
#include <cstdlib>
#include <limits>

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
	if (str == "nan" || str == "nanf")
		return (DOUBLE);
	if (str.find_first_of('.') != str.npos) {
		if (str.find_last_of('f') != str.npos)
			return (FLOAT);
		else
			return (DOUBLE);
	}
	else {
		if (str.size() == 1 && std::isprint(str[0]))
			return (CHAR);
		else if (str.find_first_not_of("-1234567890") == str.npos)
			return (INT);
	}
	return (UNKNOWN);
}

void	convertInt(std::string & s) {
	double	res;

	res = std::strtod(s.c_str(), NULL);
	if (!(res >= std::numeric_limits<int>::min() && res <= std::numeric_limits<int>::max()))
		throw ScalarConverter::valueTooLargeException();
	::printConversions(static_cast<int>(res));
}

void	convertDouble(std::string & s) {
	double res;

	if (s == "nan" || s == "nanf") {
		printN(s);
		return ;
	}
	decimalFormatChecker(s, DOUBLE);
	res = std::strtod(s.c_str(), NULL);
	if (!(res >= -std::numeric_limits<double>::max() && res <= std::numeric_limits<double>::max()))
		throw ScalarConverter::valueTooLargeException();
	::printConversions(static_cast<double>(res));
}

void	convertFloat(std::string & s) {
	double res;
	
	decimalFormatChecker(s.c_str(), FLOAT);
	res = std::strtod(s.c_str(), NULL);
	if (!(res >= -std::numeric_limits<float>::max() && res <= std::numeric_limits<float>::max()))
		throw ScalarConverter::valueTooLargeException();
	::printConversions(static_cast<float>(res));
}

void	ScalarConverter::convert(std::string const & s) {
	double	res;

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
				std::cout << "UNKNOWN" << std::endl;
		}
	}
	catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	res = strtod(s.c_str(), NULL);
	(void)res;
}

const char*	ScalarConverter::valueTooLargeException::what() const throw() { return ("Value is too big"); }
const char*	ScalarConverter::incorrectFormatException::what() const throw() { return ("Incorrect format"); }
