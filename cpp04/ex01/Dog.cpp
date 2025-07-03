#include "Dog.hpp"
#include "colors.h"
#include <iostream>

Dog::Dog( void ) : Animal("dog"), _brain(new Brain())
{
	std::cout << RED << "created dog (default)" << RESET << std::endl;
}

Dog::Dog( const Dog& other ) : Animal(other), _brain(new Brain())
{
	std::cout << RED << "created dog (copy)" << RESET << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << RED << "destroyed dog" << RESET << std::endl;
}

Dog& Dog::operator=( const Dog& other )
{
	_type = other._type;
	_brain = other._brain;
	std::cout << RED << "created dog (copy=)" << RESET << std::endl;
	return *this;
}

void Dog::makeSound( void ) const { std::cout << "woof" << std::endl; }
