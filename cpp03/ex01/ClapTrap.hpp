#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <string>
#include <iostream>

class ClapTrap
{
public:
	ClapTrap( void );
	ClapTrap( std::string );
	ClapTrap( const ClapTrap& );
	~ClapTrap();

	ClapTrap& operator=( const ClapTrap& );

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
	std::string _name;
};

#endif