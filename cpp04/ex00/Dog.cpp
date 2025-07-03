#include "Dog.hpp"
#include "colors.h"
#include <iostream>

Dog::Dog( void ) : Animal("dog")
{
	std::cout << RED << "created dog (default)" << RESET << std::endl;
}

Dog::Dog( const Dog& other ) : Animal(other)
{
	std::cout << RED << "created dog (copy)" << RESET << std::endl;
}

Dog::~Dog()
{
	std::cout << RED << "destroyed dog" << RESET << std::endl;
}

Dog& Dog::operator=( const Dog& other )
{
	_type = other._type;
	std::cout << RED << "created dog (copy=)" << RESET << std::endl;
	return *this;
}

void Dog::makeSound( void ) const { std::cout << "woof" << std::endl; }
