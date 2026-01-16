#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int	main(void) {
	std::cout << "Creating a Dog and a Cat\n" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << "\nDeleting them\n" << std::endl;


	delete j;
	delete i;

	Dog* bulldog = new Dog();

	bulldog->setIdea("Food");
	std::cout << bulldog->getIdea(0) << std::endl;
	delete bulldog;

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

	return 0;
}
