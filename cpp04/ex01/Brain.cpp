#include "Brain.hpp"
#include "colors.h"
#include <iostream>

Brain::Brain( void )
{
	std::cout << MAGENTA << "created brain (default)" << RESET << std::endl;
}

Brain::Brain( const Brain& )
{
	std::cout << MAGENTA << "created brain (copy)" << RESET << std::endl;
}

Brain::~Brain()
{
	std::cout << MAGENTA << "destroyed brain" << RESET << std::endl;
}

Brain Brain::operator=( const Brain& )
{
	std::cout << MAGENTA << "created brain (copy=)" << RESET << std::endl;
	return *this;
}