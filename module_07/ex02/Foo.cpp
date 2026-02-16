#include "Foo.hpp"

Foo::Foo(): name("Foo"), age(42) {} ;

Foo::Foo(Foo const & other) { *this = other; }

Foo& Foo::operator=(Foo const & other) {
	if (this != &other) {
		this->age = other.age;
		this->name = other.name;
	}
	return (*this);
}

Foo::~Foo() {};

std::ostream & operator<<(std::ostream & os, Foo const & foo) {
	os << "Foo: ";
	os << "name: " << foo.name << ", ";
	os << "age: " << foo.age;
	return (os);
}

