#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <iostream>

class Zombie
{
public:
	Zombie( void );
	~Zombie();
	void announce( void );

	std::string name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );


#endif