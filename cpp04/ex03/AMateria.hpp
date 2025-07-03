#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
public:
	AMateria( const std::string& );
	virtual ~AMateria();

	const std::string& getType() const; //Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use( ICharacter& ) = 0;
protected:
	std::string _type;
};

#endif