#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
public:
	HumanB( std::string);
	~HumanB();
	void attack( void );
	void setWeapon( Weapon& );
	Weapon& getWeapon( void );

	std::string name;

private:
	Weapon *_weapon;
};

#endif