#include "WrongCat.hpp"
#include "colors.h"
#include <iostream>

WrongCat::WrongCat( void ) : WrongAnimal("cat")
{
	std::cout << GREEN << "created cat (default)" << RESET << std::endl;
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other)
{
	std::cout << GREEN << "created cat (copy)" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << GREEN << "destroyed cat" << RESET << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& other )
{
	_type = other._type;
	std::cout << BLUE << "created cat (copy=)" << RESET << std::endl;
	return *this;
}

void WrongCat::makeSound( void ) const { std::cout << "meow :3" << std::endl; }
