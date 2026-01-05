#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int	main(void) {
	std::cout << "Creating a Dog and a Cat\n" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nDeleting them\n" << std::endl;

	delete j;//should not create a leak
	delete i;

	std::cout << "\nCreate 6 animals (3 Dog and 3 Cat)\n"  << std::endl;
	Animal	*animals[6] = {new Dog(), new Dog(), new Dog(),
				new Cat(), new Cat(), new Cat()};

	std::cout << "\nWhat does the dog (and cat) says ?\n" << std::endl;
	for (int i = 0; i < 6; i++) {
		animals[i]->makeSound();
	}

	for (int i = 0; i < 6; i++) {
		delete animals[i];
	}

	std::cout << "\nMore cats !\n" << std::endl;
	Animal	*cat = new Cat();
	Animal	copyCat = *cat;

	std::cout << "Cat address: " << &cat << std::endl;
	std::cout << "CopyCat address: " << &copyCat << std::endl;

	delete cat;
	return 0;
}
