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

static std::string	trim(std::string const & src) {
	std::string	res(src);

	res.erase(0,res.find_first_not_of(" \n\r\t"));
	res.erase(res.find_last_not_of(" \n\r\t") + 1);
	return(res);
}

static int	safeAtoi(std::string str) {
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

/*	Checker	*/
static void	decimalFormatChecker(std::string const & str, t_type type) {
	size_t	minusSign = str.find_last_of('-');
	size_t	decimalPos = str.find_first_of('.');
	size_t	fFlag;

	if (minusSign > 0 && minusSign != str.npos) {
		std::cout << "Found minus sign in the wrong pos" << std::endl;
		throw (ScalarConverter::valueTooLargeException());
	}
	if (decimalPos == 0 || decimalPos == str.size() - 1) {
		std::cout << "incorrect Double format!" << std::endl;
		throw (ScalarConverter::valueTooLargeException());
	}
	if (str.find_first_not_of(NUMSET) != decimalPos) {
		std::cout << "Incorrect Double format!" << std::endl;
		throw (ScalarConverter::valueTooLargeException());
	}
	if (type == DOUBLE && str.find_first_not_of (NUMSET, decimalPos + 1) != str.npos) {
		std::cout << "Incorrect Double format!" << std::endl;
		throw (ScalarConverter::valueTooLargeException());
	}
	if (type == FLOAT) {
		fFlag = str.find_first_not_of(NUMSET, decimalPos + 1);
		if (fFlag != str.size() - 1 || str[fFlag] != 'f' || fFlag - 1 == decimalPos) {
			std::cout << "Found wrong char before deicmal Point" << std::endl;
			throw (ScalarConverter::valueTooLargeException());
		}
	}
}

/*	CHAR	*/
void	ScalarConverter::fromChar(std::string const & str) {
	std::string::const_iterator  it=str.begin();
	::printConversions(*it);
}

/*	INT 		*/
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

/*	FLOAT		*/
void	ScalarConverter::fromFloat(std::string const & str) {
	try {
		decimalFormatChecker(str, FLOAT);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	/* Convert from string to float */
	std::cout << str << std::endl;
}

/*	DOUBLE		*/
void	ScalarConverter::fromDouble(std::string const & str) {
	try {
		decimalFormatChecker(str, DOUBLE);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	/* Convert from string to double */
	std::cout << str << std::endl;
}

/* ID */
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
	std::string	s(trim(str));
	inputType = type_id(s);
	if (inputType >= 0)
		(funcPtrs[inputType](s));
	else
		std::cout << "Unknown type, please enter one of these -> [int, long, double, char]." << std::endl;
}

const char*	ScalarConverter::valueTooLargeException::what() const throw() { return ("Value is too big"); }
