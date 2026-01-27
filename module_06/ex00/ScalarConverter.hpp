#ifndef SCALAR_H
# define SCALAR_H

#include <string>

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

	void	fromChar(std::string const & str);
	void	fromInt(std::string const & str);
	void	fromFloat(std::string const & str);
	void	fromDouble(std::string const & str);

	void (ScalarConverter::*funcPtrs[4])(std::string const &) = {
		&ScalarConverter::fromChar,
		&ScalarConverter::fromInt,
		&ScalarConverter::fromFloat,
		&ScalarConverter::fromDouble};
	
};

#endif
