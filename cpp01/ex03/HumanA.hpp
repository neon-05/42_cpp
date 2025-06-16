#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
public:
	HumanA( std::string, Weapon );
	~HumanA();
	void attack( void );

	std::string name;
	Weapon weapon;
};

#endif