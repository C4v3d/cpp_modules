#include "ScalarConverter.hpp"

#include <string>
#include <iostream>
#include <cstdlib>

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
/*	This function should throw when atoi fails	*/
static int	safeAtoi(std::string str) {
	int	res;
	size_t	minusSign = str.find_first_of('-');

	if (minusSign == 0)
		str.erase(0, 1);
	res = std::atoi(str.c_str());
	if (res < 0)
		throw ScalarConverter::valueTooLargeException();
	return (minusSign == 0 ? (res = res * -1) : res);
}

/*	INT 		*/
void	ScalarConverter::fromInt(std::string const & str) {
	int	res;
	size_t	minusSign = str.find_last_of('-');

	if (minusSign > 0 && minusSign != str.npos) {
		std::cout << "Wronf integer format" << std::endl;
		return ;
	}
	if (str.size() > 11) {
		std::cout << "Value too big" << std::endl;
		return;
	}
	try {
		res = safeAtoi(str);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return ;
	}
	::printConversions<int>(res);
}

/*	FLOAT		*/
void	ScalarConverter::fromFloat(std::string const & str) {
	size_t	decimalPos = str.find_first_of('.');
	size_t	fFlag;
	size_t	minusSign = str.find_last_of('-');

	if (minusSign > 0 && minusSign != str.npos) {
		std::cout << "Found minus sign in the wrong pos" << std::endl;
		return ;
	}
	if (decimalPos == 0 || decimalPos == str.npos) {
		std::cout << "Incorrect Float Format" << std::endl;
	}
	if (str.find_first_not_of(NUMSET) != decimalPos) {
		std::cout << "Found wrong char before decimal Point" << std::endl;
		return ;
	}
	fFlag = str.find_first_not_of(NUMSET, decimalPos + 1);
	if (fFlag != str.size() - 1 || str[fFlag] != 'f' || fFlag - 1 == decimalPos) {
		std::cout << "Found wrong char before deicmal Point" << std::endl;
		return ;
	}
}

/*	DOUBLE		*/
void	ScalarConverter::fromDouble(std::string const & str) {
	size_t	decimalPos = str.find_first_of('.');
	size_t	minusSign = str.find_last_of('-');

	if (minusSign > 0 && minusSign != str.npos) {
		std::cout << "incorrect Double format!" << std::endl;
		return ;
	}
	if (decimalPos == 0 || decimalPos == str.size() - 1) {
		std::cout << "incorrect Double format!" << std::endl;
		return ;
	}
	if (str.find_first_not_of(NUMSET) != decimalPos) {
		std::cout << "Incorrect Double format!" << std::endl;
		return ;
	}
	if (str.find_first_not_of (NUMSET, decimalPos + 1) != str.npos) {
		std::cout << "Incorrect Double format!" << std::endl;
		return ;
	}
	std::cout << "Valid Double" << std::endl;
}

/* Converter */

static t_type	type_id(std::string const & str) {

	if (str.find_first_of('.') != str.npos) {
		if (str.find_last_of('f') != str.npos) {
			return (FLOAT);
		}
		else {
			return (DOUBLE);
		}
	}
	else {
		if (str.size() == 1 && std::isalpha(str[0])) {
			return (CHAR);
		}
		else if (str.find_first_not_of("-1234567890") == str.npos) {
			return (INT);
		}
	}
	return (UNKNOWN);
}

void	ScalarConverter::convert(std::string const & str) {
	t_type	inputType;

	if (str.empty()) {
		std::cout << "String empty" << std::endl;
		return ;
	}
	inputType = type_id(str);
	if (inputType >= 0)
		(funcPtrs[inputType](str));
	else
		std::cout << "Unknown type, please enter one of these -> [int, long, double, char]." << std::endl;
}

const char*	ScalarConverter::valueTooLargeException::what() const throw() { return ("Value is too big"); }
