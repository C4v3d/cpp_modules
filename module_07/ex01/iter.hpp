#ifndef ITER_HPP
# define ITER_HPP

#include <cstdio>
#include <iostream>

template <typename T, typename F> void iter(T * addr, size_t const & len, F func){
	for (size_t i = 0; i < len; i++) {
		func(addr[i]);
	}
}

template <typename T> void	print_iter(T const & el) {
	std::cout << el << std::endl;
}

#endif
