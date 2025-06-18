#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name(name), _weapon(NULL) {}

HumanB::~HumanB( void ) {}

void HumanB::attack( void )
{
	std::cout << name << " attacks with " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon( Weapon& weapon ) { _weapon = &weapon; }
Weapon& HumanB::getWeapon( void ) { return *_weapon; }