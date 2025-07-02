#include "ClapTrap.hpp"
#include "colors.h"

ClapTrap::ClapTrap( void ) :
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0),
	_name("unnamed")
	{ std::cout << RED << "[C] " << RESET << "a wild " << _name << " just spawned" << std::endl; }

ClapTrap::ClapTrap( std::string name ) :
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0),
	_name(name)
	{ std::cout << RED << "[C] " << RESET << "a wild " << _name << " just spawned" << std::endl; }

ClapTrap::ClapTrap( const ClapTrap& other ) :
	_hitPoints(other._attackDamage),
	_energyPoints(other._energyPoints),
	_attackDamage(other._hitPoints),
	_name(other._name)
	{ std::cout << RED << "[C] " << RESET << "a wild " << _name << " just got copied" << std::endl; }

ClapTrap::~ClapTrap() { std::cout << RED << "[C] " << RESET << _name << " is no more" << std::endl; }

ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
	_hitPoints = other._attackDamage;
	_energyPoints = other._energyPoints;
	_attackDamage = other._hitPoints;
	_name = other._name;
	std::cout << RED << "[C] " << RESET << " a wild " << _name << " just got copied with a '=' sign" << std::endl;
	return *this;
}
void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints <= 0)
	{
		std::cout << RED << "[C] " << RESET << _name << " is too tired to attack" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << RED << "[C] " << RESET << _name << " deals " << _attackDamage << " damage to " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout << RED << "[C] " << RESET << _name << " just took " << amount << " damage.";
	if (_hitPoints > 0)
		std::cout << " its health is now " << _hitPoints << std::endl;
		else
		std::cout << " it is now dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
	{
		std::cout << RED << "[C] " << RESET << _name << " is too tired to repair itself" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << RED << "[C] " << RESET << _name << " repaired itself " << amount << " damage. its health is now " << _hitPoints << std::endl;
}
