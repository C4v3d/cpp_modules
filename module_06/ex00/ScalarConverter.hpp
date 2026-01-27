#ifndef SCALAR_H
# define SCALAR_H

#include <string>

class ScalarConverter {
public:
	static void convert(std::string const & str);
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & other);
	ScalarConverter& operator=(ScalarConverter const & other);
	~ScalarConverter();
};

#endif
