#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
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

	using ScavTrap::attack;
	void whoAmI( void );

private:
	std::string _name;
};

#endif