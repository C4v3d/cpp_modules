#ifndef SCALAR_H
# define SCALAR_H

#include <string>
#include <iostream>
#include <limits.h>

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
void		printInf();
bool		safeIsPrint(int c);

template <typename T> void printConversions(T const &x) {
	if (safeIsPrint(x))
		std::cout << "char: " << static_cast<char>(x) << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	if (x > INT_MAX)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(x) << std::endl;
	std::cout << "float: " << static_cast<float>(x) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(x) << std::endl;
}

class ScalarConverter {
public:
	static void convert(std::string const & str);
	class valueTooLargeException;
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & other);
	ScalarConverter& operator=(ScalarConverter const & other);
	~ScalarConverter();

	static void	fromChar(std::string const & str);
	static void	fromInt(std::string const & str);
	static void	fromFloat(std::string const & str);
	static void	fromDouble(std::string const & str);

	static void (*funcPtrs[4])(std::string const &);
};

class ScalarConverter::valueTooLargeException : public std::exception {
public:
	const char*	what() const throw();
};

#endif
