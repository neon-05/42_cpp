#include "classes.h"
#include "MateriaSource.hpp"
#include "Materias.hpp"

MateriaSource::MateriaSource() : _knownMateriaCount(0) {}
MateriaSource::~MateriaSource() { for (int i = 0; i < _knownMateriaCount; i++) delete _knownMaterias[i]; }

void MateriaSource::learnMateria( AMateria *materia )
{
	if (_knownMateriaCount < 4)
	{
		_knownMaterias[_knownMateriaCount] = materia;
		_knownMateriaCount++;
	}
}

AMateria *MateriaSource::createMateria( const std::string& type )
{
	for (int i = 0; i < 4; i++) 
		if (_knownMaterias[i]->getType().compare(type) == 0)
			return _knownMaterias[i]->clone();
	return NULL;
}