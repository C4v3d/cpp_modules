#ifndef TEMP_HPP
# define TEMP_HPP

template <typename T> void swap(T & x, T & y) {
	T	tmp = x;

	x = y;
	y = tmp;
}

template <typename T> T min(T const & x, T const & y) {
	return (x < y) ? x : y;
}

template <typename T> T max(T const & x, T const & y) {
	return (x > y) ? x : y;
}

#endif
