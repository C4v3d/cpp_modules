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
void		printInf();
bool		safeIsPrint(int c);

template <typename T> void printConversions(T const &x) {
	std::cout << std::fixed << std::setprecision(1);
	if (std::isprint(x))
		std::cout << "char: " << static_cast<char>(x) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (x >= std::numeric_limits<int>::min() && x <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(x) << std::endl;

	if (x >= -std::numeric_limits<float>::max() && x <= std::numeric_limits<float>::max())
		std::cout << "float: " << static_cast<float>(x) << 'f' << std::endl;

	if (x >= -std::numeric_limits<double>::max() && x <= std::numeric_limits<double>::max())
		std::cout << "double: " << static_cast<double>(x) << std::endl;

}
class ScalarConverter {
public:
	static void convert(std::string const & str);
	class valueTooLargeException;
	class incorrectFormatException;
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

#endif
