#include "Zombie.hpp"
int main(int argc, char const *argv[])
{
	if (argc < 3)
		return (2);
	Zombie	*zombie = newZombie(argv[1]);
	std::cout << zombie->name << ": hello my name is " << zombie->name << std::endl;
	randomChump(argv[2]);
	delete zombie;
	return (0);
}
