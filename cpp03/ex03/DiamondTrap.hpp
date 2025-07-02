#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

class DiamondTrap: public FragTrap, public ScavTrap
{
public:
	DiamondTrap( void );
	DiamondTrap( std::string );
	DiamondTrap( const DiamondTrap& );
	~DiamondTrap();

	DiamondTrap& operator=( const DiamondTrap&);

	void whoAmI( void );

private:
	std::string _name;
};

#endif