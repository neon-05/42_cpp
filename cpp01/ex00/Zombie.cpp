#include "Zombie.hpp"

Zombie::Zombie(void) {std::cout << "<unnamed zombie> (created)" << std::endl;}
Zombie::~Zombie(void) {std::cout << this->name << " (deleted)" << std::endl;}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
