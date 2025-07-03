#include "Animal.hpp"
#include "colors.h"
#include <iostream>

Animal::Animal( void ) : _type("undefined animal")
{
	std::cout << BLUE << "created animal of type " << _type << " (default)" << RESET << std::endl;
}

Animal::Animal( std::string type ) : _type(type)
{
	std::cout << BLUE << "created animal of type " << _type << " (type)" << RESET << std::endl;
}

Animal::Animal( const Animal& other ) : _type(other._type)
{
	std::cout << BLUE << "created animal of type " << _type << " (copy)" << RESET << std::endl;
}

Animal::~Animal()
{
	std::cout << BLUE << "destroyed animal of type " << _type << RESET << std::endl;
}

Animal& Animal::operator=( const Animal& other )
{
	_type = other._type;
	std::cout << BLUE << "created animal of type " << _type << " (copy=)" << RESET << std::endl;
	return *this;
}

std::string Animal::getType( void ) const { return _type; }
void Animal::makeSound( void ) const { std::cout << "* very normal animal sound *" << std::endl; }
