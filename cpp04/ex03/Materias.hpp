#ifndef MATERIAS_HPP
#define MATERIAS_HPP
#include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice( void );
	~Ice();
	AMateria *clone() const;
	void use(ICharacter& target);
};

class Cure: public AMateria
{
public:
	Cure( void );
	~Cure();
	AMateria *clone() const;
	void use(ICharacter& target);
};

#endif