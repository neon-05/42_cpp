#include "Cat.hpp"
#include "colors.h"
#include <iostream>

Cat::Cat( void ) : AbstractAnimal("cat"), _brain(new Brain())
{
	std::cout << GREEN << "created cat (default)" << RESET << std::endl;
}

Cat::Cat( const Cat& other ) : AbstractAnimal(other), _brain(new Brain())
{
	std::cout << GREEN << "created cat (copy)" << RESET << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << GREEN << "destroyed cat" << RESET << std::endl;
}

Cat& Cat::operator=( const Cat& other )
{
	_type = other._type;
	_brain = other._brain;
	std::cout << GREEN << "created cat (copy=)" << RESET << std::endl;
	return *this;
}

void Cat::makeSound( void ) const { std::cout << "meow :3" << std::endl; }
