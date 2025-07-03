#include "WrongAnimal.hpp"
#include "colors.h"
#include <iostream>

WrongAnimal::WrongAnimal( void ) : _type("undefined animal")
{
	std::cout << BLUE << "created animal of type " << _type << " (default)" << RESET << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type(type)
{
	std::cout << BLUE << "created animal of type " << _type << " (type)" << RESET << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) : _type(other._type)
{
	std::cout << BLUE << "created animal of type " << _type << " (copy)" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BLUE << "destroyed animal of type " << _type << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
	_type = other._type;
	std::cout << BLUE << "created animal of type " << _type << " (copy=)" << RESET << std::endl;
	return *this;
}

std::string WrongAnimal::getType( void ) const { return _type; }
void WrongAnimal::makeSound( void ) const { std::cout << "* very normal animal sound *" << std::endl; }
