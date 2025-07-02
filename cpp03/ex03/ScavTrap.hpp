#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string );
	ScavTrap( const ScavTrap& );
	~ScavTrap();

	ScavTrap& operator=( const ScavTrap&);

	void guardGate( void );
};

#endif