#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal
{
public:
	Animal( void );
	Animal( const Animal& );
	virtual ~Animal();

	Animal& operator=( const Animal& );

	std::string getType( void ) const;
	virtual void makeSound( void ) const;

protected:
	Animal( std::string );

	std::string _type;
};

#endif