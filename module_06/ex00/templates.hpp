#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

#include "ScalarConverter.hpp"

class ScalarConverter;

template <typename T> void printConversions(T const &x) {
	std::cout << std::fixed << std::setprecision(1);
	if ((x > 0 && x < 256) && std::isprint(x))
		std::cout << "char: " << static_cast<char>(x) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if (x >= std::numeric_limits<int>::min() && x <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(x) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	if (x >= -std::numeric_limits<float>::max() && x <= std::numeric_limits<float>::max())
		std::cout << "float: " << static_cast<float>(x) << 'f' << std::endl;
	else
		std::cout << "float: impossible" << std::endl;

	if (x >= -std::numeric_limits<double>::max() && x <= std::numeric_limits<double>::max())
		std::cout << "double: " << static_cast<double>(x) << std::endl;
	else
		std::cout << "double: impossible" << std::endl;

}

template <typename I, typename O> void dynamicConversion(I const & input, O & output) {
	output = 0;
	if (!(input >= -std::numeric_limits<O>::max() && input <= std::numeric_limits<O>::max()))
		throw ScalarConverter::impossibleConversionException();
	output = static_cast<O>(input);
	::printConversions(output);
}

#endif