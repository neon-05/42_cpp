#include "classes.h"
#include "Materias.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::~Ice() {}
AMateria *Ice::clone() const { return new Ice(); }
void Ice::use( ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure::Cure() : AMateria("cure") {}
Cure::~Cure() {}
AMateria *Cure::clone() const { return new Cure(); }
void Cure::use( ICharacter& target) 
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
