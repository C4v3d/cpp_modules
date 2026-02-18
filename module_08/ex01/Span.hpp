#ifndef SPAN_HPP
# define SPAN_HPP

class Span {
public:
  Span();
  Span(unsigned int const & N);
  Span(Span const & other);
  Span& operator=(Span const & other);
  ~Span();

  void  addNumber(int const & num);
private:
  unsigned int  _n;
  int           *_arr;
};

#endif
