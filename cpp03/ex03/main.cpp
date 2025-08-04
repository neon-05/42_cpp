#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap dt = DiamondTrap("josh");

	dt.attack("enemy");
	dt.highFiveGuys();
	dt.guardGate();
	dt.whoAmI();

	return 0;
}
