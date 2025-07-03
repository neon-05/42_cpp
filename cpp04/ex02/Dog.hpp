#ifndef DOG_HPP
#define DOG_HPP
#include <string>
#include "AbstractAnimal.hpp"
#include "Brain.hpp"

class Dog: public AbstractAnimal
{
public:
	Dog( void );
	Dog( const Dog& );
	~Dog();

	Dog& operator=( const Dog& );
	void makeSound( void ) const;
private:
	Brain *_brain;
};

#endif