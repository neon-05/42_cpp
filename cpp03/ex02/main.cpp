#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap ft1 = FragTrap("Josh");
	FragTrap ft2 = FragTrap();
	ScavTrap st1 = ScavTrap("pakistan airlines");

	ft1.attack("something probably");
	ft1.takeDamage(9);
	ft2.takeDamage(12);
	ft1.beRepaired(1);
	//ft2.guardGate(); // does not work
	st1.guardGate();
	ft1.highFiveGuys();
	//st1.highFiveGuys(); // does not work

	return 0;
}
