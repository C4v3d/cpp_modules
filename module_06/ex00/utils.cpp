#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <limits>
#include "ScalarConverter.hpp"

std::string	trim(std::string const & src) {
	std::string	res(src);

	res.erase(0,res.find_first_not_of(" \n\r\t"));
	res.erase(res.find_last_not_of(" \n\r\t") + 1);
	return(res);
}

int	safeAtoi(std::string str) {
	int	res;
	size_t	minusSign = str.find_first_of('-');

	if (str == "-2147483648")
		return (-2147483648);
	if (minusSign == 0)
		str.erase(0, 1);
	res = std::atoi(str.c_str());
	if (res < 0)
		throw ScalarConverter::valueTooLargeException();
	return (minusSign == 0 ? (res = res * -1) : res);
}

void	decimalFormatChecker(std::string const & str, t_type type) {
	size_t	minusSign = str.find_last_of('-');
	size_t	decimalPos = str.find_first_of('.');
	size_t	fFlag;
	if (minusSign > 0 && minusSign != str.npos)
		throw (ScalarConverter::incorrectFormatException());
	if (decimalPos == 0 || decimalPos == str.size() - 1)
		throw (ScalarConverter::incorrectFormatException());
	if (str.find_first_not_of(NUMSET) != decimalPos)
		throw (ScalarConverter::incorrectFormatException());
	if (type == DOUBLE && str.find_first_not_of (NUMSET, decimalPos + 1) != str.npos)
		throw (ScalarConverter::incorrectFormatException());
	if (type == FLOAT) {
		fFlag = str.find_first_not_of(NUMSET, decimalPos + 1);
		if (fFlag != str.size() - 1 || str[fFlag] != 'f' || fFlag - 1 == decimalPos)
			throw (ScalarConverter::incorrectFormatException());
	}
}

void	printN(std::string const & s) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << nan(s.c_str()) << 'f' << std::endl;
	std::cout << "double: " << nan(s.c_str()) << std::endl;
}

void	printInf(int flag) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << std::numeric_limits<int>::infinity() << std::endl;
	if (flag) {
		std::cout << "float: " << -std::numeric_limits<float>::infinity() << 'f' << std::endl;
		std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
	}
	else {
		std::cout << "float: " << std::numeric_limits<float>::infinity() << 'f' << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
}
