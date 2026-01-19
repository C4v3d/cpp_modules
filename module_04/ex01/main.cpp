#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int	main(void) {
	std::cout << "---- Simple brain testing ----\n" << std::endl;
	Dog* bulldog = new Dog();
	std::cout << "*Setting Ideas (Food)*" << std::endl;
	bulldog->setIdea("Food");
	std::cout << "The bulldog is thinking about: " << bulldog->getIdea(0) << std::endl;
	std::cout << "Copying Bulldog" << std::endl;
	Dog* dog = new Dog(*bulldog);
	std::cout << "Deleting Bulldog" << std::endl;
	delete bulldog;
	std::cout << "Dog is thinking about: " << dog->getIdea(0) << std::endl;
	delete dog;

	std::cout << "\n---- Intense brain testing ----\n" << std::endl;
	Cat* cat = new Cat();
	cat->makeSound();
	std::cout << cat->getIdea(0) << std::endl;
	std::cout << "Filling brain with ideas" << std::endl;
	for (int i = 0; i < 104; i++) {
		cat->setIdea("Food");
	}
	std::cout << "Checking cat brain:" << cat->getIdea(64) << std::endl;
	std::cout << "Chhecking out of brain: " << cat->getIdea(101) << std::endl;
	delete cat;

	std::cout << "\n---- Create 6 animals (3 Dog and 3 Cat) ----\n"  << std::endl;
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
