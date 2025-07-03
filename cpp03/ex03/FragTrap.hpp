#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap: virtual public ClapTrap
{
public:
	FragTrap( void );
	FragTrap( std::string );
	FragTrap( const FragTrap& );
	~FragTrap();

	FragTrap& operator=( const FragTrap&);

	void highFiveGuys( void );
};

#endif