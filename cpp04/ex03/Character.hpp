#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
public:
	Character( std::string );
	~Character();
	void use( int, ICharacter& );
	std::string const & getName() const;
	void equip( AMateria* );
	void unequip( int );
private:
	std::string _name;
	AMateria *_inventory[4];
	int _equippedMateriaCount;
};

#endif