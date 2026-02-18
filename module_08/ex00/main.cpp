#include <iostream>
#include <vector>
#include <algorithm>

#include "easyfind.hpp"

int	main(void) {
	std::vector<int> v1;
  v1.push_back(1);
  v1.push_back(2);
  v1.push_back(3);
  std::vector<int>::iterator it = ::easyfind(v1, 3);
  if (it == v1.end())
    std::cout << "No found" << std::endl;
  else {
    std::cout <<  "Found !" << std::endl;
  }
	return (0);
}
