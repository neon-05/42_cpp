#ifndef ABSTRACTANIMAL_HPP
#define ABSTRACTANIMAL_HPP
#include <string>

class AbstractAnimal
{
public:
	AbstractAnimal( void );
	AbstractAnimal( const AbstractAnimal& );
	virtual ~AbstractAnimal() = 0;

	AbstractAnimal& operator=( const AbstractAnimal& );

	std::string getType( void ) const;
	virtual void makeSound( void ) const = 0;

protected:
	AbstractAnimal( std::string );

	std::string _type;
};

#endif