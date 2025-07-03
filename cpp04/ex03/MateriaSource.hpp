#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource( void );
	~MateriaSource();
	void learnMateria( AMateria* );
	AMateria *createMateria( const std::string& );
private:
	int _knownMateriaCount;
	AMateria *_knownMaterias[4];
};

#endif