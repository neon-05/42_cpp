#include "classes.h"
#include "Character.hpp"

Character::Character( std::string name ) : _name(name), _equippedMateriaCount(0) {}
Character::~Character() { for (int i = 0; i < _equippedMateriaCount; i++) delete _inventory[i]; }

void Character::use( int i, ICharacter& target ) { _inventory[i]->use(target); }

const std::string& Character::getName( void ) const { return _name; }

void Character::equip( AMateria *materia )
{
	if (_equippedMateriaCount < 4)
	{
		_inventory[_equippedMateriaCount] = materia;
		_equippedMateriaCount++;
	}
}

void Character::unequip( int i )
{
	if (0 <= i && i < _equippedMateriaCount)
	{
		delete _inventory[i];
		_equippedMateriaCount--;
		while (i < 3)
		{
			_inventory[i] = _inventory[i + 1];
			i++;
		}
	}
}