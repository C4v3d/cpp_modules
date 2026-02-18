#ifndef EASYFIND_HPP
# define EASYFIND_HPP

/* End point to the element after the last element */
template <typename T>
typename T::iterator  easyfind(T & input, int const & target) {
  return (std::find(input.begin(), input.end(), target));
}

#endif
