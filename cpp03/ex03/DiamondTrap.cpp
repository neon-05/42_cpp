#include "DiamondTrap.hpp"
#include "colors.h"

DiamondTrap::DiamondTrap( void ) : ClapTrap("unnamed_clap_name"), _name("unnamed")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << MAGENTA << "[D] " << RESET << "a wild " << _name << " just spawned" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), _name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << MAGENTA << "[D] " << RESET << "a wild " << _name << " just spawned" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other), FragTrap(other), ScavTrap(other)
	{ std::cout << MAGENTA << "[D] " << RESET << "a wild " << _name << " just got copied" << std::endl; }

DiamondTrap::~DiamondTrap() { std::cout << MAGENTA << "[D] " << RESET << _name << " is no more" << std::endl; }

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other )
{
	_hitPoints = other._attackDamage;
	_energyPoints = other._energyPoints;
	_attackDamage = other._hitPoints;
	_name = other._name;
	std::cout << MAGENTA << "[D] " << RESET << "a wild " << _name << " just got copied with a '=' sign" << std::endl;
	return *this;
}

void DiamondTrap::whoAmI( void )
	{ std::cout << MAGENTA << "[D] " << RESET << "my name is " <<_name << " also known as " << ClapTrap::_name << std::endl; }
