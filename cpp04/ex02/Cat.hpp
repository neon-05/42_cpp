#ifndef CAT_HPP
#define CAT_HPP
#include <string>
#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Cat: public AbstractAnimal
{
public:
	Cat( void );
	Cat( const Cat& );
	~Cat();

	Cat& operator=( const Cat& );
	void makeSound( void ) const;
private:
	Brain *_brain;
};

#endif