#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <stddef.h>
#include <stdexcept>
#include <ostream>

template < typename T >
class Array {
	public:
		Array();
		Array(unsigned int const & n);
		Array(Array<T> const & other);
		Array<T> & operator=(Array<T> const & other);
		~Array();

		T & operator[](unsigned int const & pos);
		const T & operator[](unsigned int const & pos) const;

		size_t getSize() const;

	private:
		unsigned int	_size;
		T * rawArray;
};

template < typename T >
Array<T>::Array(): _size(0), rawArray(NULL) {}

template < typename T >
Array<T>::Array(unsigned int const & n): _size(n), rawArray(new T[n]()) {}

template < typename T >
Array<T>::Array(Array<T> const & other) {
	this->rawArray = NULL;
	*this = other;
}

template < typename T >
Array<T> & Array<T>::operator=(Array<T> const & other) {
	if (this->rawArray != NULL)
		delete [] this->rawArray;
	this->_size = other._size;
	this->rawArray = new T[this->_size];
	for (size_t i = 0; i < this->_size; i++) {
		this->rawArray[i] = other.rawArray[i];
	}
	return (*this);
}

template < typename T >
Array<T>::~Array() { delete [] this->rawArray; }

template < typename T>
T & Array<T>::operator[](unsigned int const & pos) {
	if (pos >= this->_size)
		throw std::out_of_range("Index is out of range !");
	return this->rawArray[pos];
}

template < typename T>
const T & Array<T>::operator[](unsigned int const & pos) const{
	if (pos >= this->_size)
		throw std::out_of_range("Index is out of range !");
	return this->rawArray[pos];
}

template <typename T>
std::ostream & operator<<(std::ostream & os, const Array<T> & array) {
    os << "[";
    size_t size = array.getSize();
    for(size_t i = 0; i < size; ++i) {
        os << array[i];
        if (i < size - 1) os << ", ";
    }
    return os << "]";
}

template < typename T>
size_t Array<T>::getSize() const { return (_size); }

#endif
