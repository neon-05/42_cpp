#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap ct1 = ClapTrap("Josh");
	ClapTrap ct2 = ClapTrap();

	ct1.attack("something probably");
	ct1.takeDamage(9);
	ct2.takeDamage(12);
	ct1.beRepaired(-1);
	ct1.beRepaired(1);
	ct1.beRepaired(1);
	ct1.beRepaired(1);
	ct1.beRepaired(1);
	ct1.beRepaired(1);
	ct1.beRepaired(1);
	ct1.beRepaired(1);
	ct1.beRepaired(1);
	ct1.beRepaired(1);

	return 0;
}
