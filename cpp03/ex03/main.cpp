#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap dt = DiamondTrap("Josh");

	dt.attack("killer queen");
	dt.highFiveGuys();
	dt.guardGate();
	dt.whoAmI();

	return 0;
}
