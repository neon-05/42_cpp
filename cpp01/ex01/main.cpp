#include "Zombie.hpp"

int main( void )
{
	int N = 8;
	Zombie *horde = zombieHorde(N, "sire brainless the Nth");

	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
