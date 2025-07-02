#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>
#include <vector>
#include <iostream>

class Zombie
{
public:
	void	announce( void );
	Zombie( void );
	~Zombie();

	std::string	name;
};

Zombie*	zombieHorde( int N, std::string name );

#endif