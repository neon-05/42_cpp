#include "Cat.hpp"
#include "colors.h"
#include <iostream>

Cat::Cat( void ) : Animal("cat")
{
	std::cout << GREEN << "created cat (default)" << RESET << std::endl;
}

Cat::Cat( const Cat& other ) : Animal(other)
{
	std::cout << GREEN << "created cat (copy)" << RESET << std::endl;
}

Cat::~Cat()
{
	std::cout << GREEN << "destroyed cat" << RESET << std::endl;
}

Cat& Cat::operator=( const Cat& other )
{
	_type = other._type;
	std::cout << GREEN << "created cat (copy=)" << RESET << std::endl;
	return *this;
}

void Cat::makeSound( void ) const { std::cout << "meow :3" << std::endl; }
