#ifndef SCALAR_H
# define SCALAR_H

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>

#define NUMSET "-1234567890"

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN = -1
}	t_type;

std::string trim(std::string const & src);
int			safeAtoi(std::string str);
void		decimalFormatChecker(std:: string const & str, t_type type);
void		printN(std::string const & s);
void		printInf(int f);
bool		safeIsPrint(int c);

class ScalarConverter {
public:
	static void convert(std::string const & str);
	class valueTooLargeException;
	class incorrectFormatException;
	class impossibleConversionException;
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & other);
	ScalarConverter& operator=(ScalarConverter const & other);
	~ScalarConverter();

	static std::string	trim(std::string const & s);
};

class ScalarConverter::valueTooLargeException : public std::exception {
public:
	const char*	what() const throw();
};

class ScalarConverter::incorrectFormatException : public std::exception {
public:
	const char*	what() const throw();
};

class ScalarConverter::impossibleConversionException : public std::exception {
public:
	const char*	what() const throw();
};

#endif
