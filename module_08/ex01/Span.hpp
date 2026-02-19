#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <ostream>

class Span {
public:
	Span();
	Span(unsigned int const & N);
	Span(Span const & other);
	Span& operator=(Span const & other);
	~Span();
	std::vector<int>  vec;

	const unsigned int& getCurSize() const;
	const unsigned int& getMaxSize() const;

	void 	addNumber(int const & num);
	void	longestSpan()const;
	void	shortestSpan() const;

	class VecIsFullException : public std::exception {
	public :
		const char* what() const throw();
	};
private:
	unsigned int _maxSize;
	unsigned int _curSize;
};

std::ostream& operator<<(std::ostream & os, Span s);

#endif
