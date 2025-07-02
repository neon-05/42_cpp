#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class FragTrap: public ClapTrap
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