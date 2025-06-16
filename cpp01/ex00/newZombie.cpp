#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie *zombie = new Zombie(); // use new to allocate on the heap
	zombie->name = name;
	return (zombie);
}