#include "AbstractAnimal.hpp"
#include "colors.h"
#include <iostream>

AbstractAnimal::AbstractAnimal( void ) : _type("undefined animal")
{
	std::cout << BLUE << "created animal of type " << _type << " (default)" << RESET << std::endl;
}

AbstractAnimal::AbstractAnimal( std::string type ) : _type(type)
{
	std::cout << BLUE << "created animal of type " << _type << " (type)" << RESET << std::endl;
}

AbstractAnimal::AbstractAnimal( const AbstractAnimal& other ) : _type(other._type)
{
	std::cout << BLUE << "created animal of type " << _type << " (copy)" << RESET << std::endl;
}

AbstractAnimal::~AbstractAnimal()
{
	std::cout << BLUE << "destroyed animal of type " << _type << RESET << std::endl;
}

AbstractAnimal& AbstractAnimal::operator=( const AbstractAnimal& other )
{
	_type = other._type;
	std::cout << BLUE << "created animal of type " << _type << " (copy=)" << RESET << std::endl;
	return *this;
}

std::string AbstractAnimal::getType( void ) const { return _type; }
void AbstractAnimal::makeSound( void ) const { std::cout << "* very normal animal sound *" << std::endl; }
