#include "ScavTrap.hpp"
#include "colors.h"

ScavTrap::ScavTrap( void )
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << BLUE << "[S] " << RESET << "a wild " << _name << " just spawned" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
	{ std::cout << BLUE << "[S] " << RESET << "a wild " << _name << " just spawned" << std::endl; }

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other)
	{ std::cout << BLUE << "[S] " << RESET << "a wild " << _name << " just got copied" << std::endl; }

ScavTrap::~ScavTrap() { std::cout << BLUE << "[S] " << RESET << _name << " is no more" << std::endl; }

ScavTrap& ScavTrap::operator=( const ScavTrap& other )
{
	_hitPoints = other._attackDamage;
	_energyPoints = other._energyPoints;
	_attackDamage = other._hitPoints;
	_name = other._name;
	std::cout << BLUE << "[S] " << RESET << "a wild " << _name << " just got copied with a '=' sign" << std::endl;
	return *this;
}

void ScavTrap::guardGate( void )
	{ std::cout << BLUE << "[S] " << RESET <<_name << " is guarding the gate" << std::endl; }
