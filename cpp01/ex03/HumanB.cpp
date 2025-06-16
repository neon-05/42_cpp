#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->name = name;
}

HumanB::~HumanB( void ) {}

void HumanB::attack( void )
{
	std::cout << this->name << " attacks with " << this->_weapon.getType() << std::endl;
}

void HumanB::setWeapon( Weapon weapon ) { this->_weapon = weapon; }
Weapon HumanB::getWeapon( void ) { return this->_weapon; }