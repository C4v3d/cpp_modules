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


	void 	addNumber(int const & num);
  void	multiAdd(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int	longestSpan()const;
	int	shortestSpan() const;

private:
	unsigned int _maxSize;
};

std::ostream& operator<<(std::ostream & os, Span s);

#endif
