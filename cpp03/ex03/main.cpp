#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap dt = DiamondTrap("JoJo");

	dt.attack("kira");
	dt.highFiveGuys();
	dt.guardGate();
	dt.whoAmI();

	return 0;
}
