#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "/* === right === */" << std::endl;
		const Animal* i = new Cat();
		const Animal* j = new Dog();
		const Animal* meta = new Animal();
		std::cout << i->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		
		delete i;
		delete j;
		delete meta;
	}
	{
		std::cout << "/* === wrong === */" << std::endl;
		const WrongAnimal* i = new WrongCat();
		const WrongAnimal* meta = new WrongAnimal();
		std::cout << i->getType() << " " << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		
		delete (WrongCat *) i;
		delete meta;
	}
	return 0;
}