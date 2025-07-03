#include "AbstractAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
	const AbstractAnimal* i = new Cat();
	const AbstractAnimal* j = new Dog();
	// const AbstractAnimal* e = new AbstractAnimal(); // does not work
	AbstractAnimal* arr[4];

	for (int i = 0; i < 4; i++)
	{
		if (i & 1)
			arr[i] = new Cat();
		else
			arr[i] = new Dog();
	}

	for (int i = 0; i < 4; i++) arr[i]->makeSound();

	for (int i = 0; i < 4; i++) delete arr[i];

	delete j;//should not create a leak
	delete i;
	return 0;
}