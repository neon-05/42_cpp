#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include <string>
#include "AMateria.hpp"

class ICharacter
{
public:
	virtual ~ICharacter() {}
	virtual const std::string& getName() const = 0;
	virtual void equip( AMateria* ) = 0;
	virtual void unequip( int ) = 0;
	virtual void use( int, ICharacter& ) = 0;
};

#endif