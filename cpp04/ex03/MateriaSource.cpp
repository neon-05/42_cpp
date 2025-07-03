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
	std::string materias[] = {"ice", "cure"};
	int i;
	for (i = 0; i < 2; i++) if (materias[i].compare(type) == 0) break;
	switch (i)
	{
	case 0:
		return new Ice();

	case 1:
		return new Cure();

	default:
		return NULL;
	}
}