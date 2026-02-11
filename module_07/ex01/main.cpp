#include "iter.hpp"

int	main(void) {

	int	n[4] = {1, 2, 3, 4};
	::iter(n, 4, print_iter<int>);
	char	c[4] = {'x', 'y', 'z', 'w'};
	::iter(c, 4, print_iter<char>);
	const char	*strs[4] = {"Hello", "World", "!"};
	::iter(strs, 3, print_iter<const char*>);
	return (0);
}
