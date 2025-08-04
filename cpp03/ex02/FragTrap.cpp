#include "FragTrap.hpp"
#include "colors.h"

FragTrap::FragTrap( void )
{
	_hitPoints = ClapTrap::_hitPoints;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "[F] " << RESET << "a default " << _name << " just spawned" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	_hitPoints = ClapTrap::_hitPoints;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GREEN << "[F] " << RESET << "a wild " << _name << " just spawned" << std::endl;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other)
	{ std::cout << GREEN << "[F] " << RESET << "a wild " << _name << " just got copied" << std::endl; }

FragTrap::~FragTrap() { std::cout << GREEN << "[F] " << RESET << _name << " is no more" << std::endl; }

FragTrap& FragTrap::operator=( const FragTrap& other )
{
	_hitPoints = other._attackDamage;
	_energyPoints = other._energyPoints;
	_attackDamage = other._hitPoints;
	_name = other._name;
	std::cout << GREEN << "[F] " << RESET << "a wild " << _name << " just got copied with a '=' sign" << std::endl;
	return *this;
}

void FragTrap::highFiveGuys( void )
	{ std::cout << GREEN << "[F] " << RESET <<_name << " is requesting a high five" << std::endl; }
