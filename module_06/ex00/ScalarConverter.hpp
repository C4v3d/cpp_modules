#ifndef SCALAR_H
# define SCALAR_H

#include <string>

#define NUMSET "-1234567890"

typedef enum e_type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	UNKNOWN = -1
}	t_type;

class ScalarConverter {
public:
	static void convert(std::string const & str);
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & other);
	ScalarConverter& operator=(ScalarConverter const & other);
	~ScalarConverter();

	static void	fromChar(std::string const & str);
	static void	fromInt(std::string const & str);
	static void	fromFloat(std::string const & str);
	static void	fromDouble(std::string const & str);

	// static void	printConversions(int const & val);
	// static void	printConversions(float const & val);
	// static void	printConversions(double const & val);

	static void (*funcPtrs[4])(std::string const &);
};

#endif
