#ifndef FOO_HPP
# define FOO_HPP

#include <string>
#include <ostream>

class Foo {	
	public :
		Foo();
		Foo(Foo const & other);
		Foo& operator=(Foo const & other);
		~Foo();

		std::string	name;
		int		age;
};

std::ostream & operator<<(std::ostream & os, Foo const & foo);

#endif
