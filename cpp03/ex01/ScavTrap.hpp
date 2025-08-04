#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap: public ClapTrap
{
public:
	ScavTrap( void );
	ScavTrap( std::string );
	ScavTrap( const ScavTrap& );
	~ScavTrap();

	ScavTrap& operator=( const ScavTrap&);

	void attack(const std::string& target);
	void guardGate( void );
};

#endif