#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie zombie; // no 'new' since I don't use this instance outside this scope
	zombie.name = name;
	zombie.announce();
}
