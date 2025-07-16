#include "classes.h"
#include "AMateria.hpp"

AMateria::AMateria( const std::string& type ) : _type(type) {}
AMateria::~AMateria() {}
const std::string& AMateria::getType( void ) const { return _type; }