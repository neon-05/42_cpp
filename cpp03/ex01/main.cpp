#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap st1 = ScavTrap("Josh");
	ScavTrap st2 = ScavTrap();
	ClapTrap ct1 = ClapTrap("eva");

	st1.attack("something probably");
	st1.takeDamage(9);
	st2.takeDamage(12);
	st1.beRepaired(1);
	st2.guardGate();
	//ct1.guardGate(); // does not work

	return 0;
}
