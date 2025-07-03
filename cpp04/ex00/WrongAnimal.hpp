#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>

class WrongAnimal
{
public:
	WrongAnimal( void );
	WrongAnimal( const WrongAnimal& );
	~WrongAnimal();

	WrongAnimal& operator=( const WrongAnimal& );

	std::string getType( void ) const;
	void makeSound( void ) const;

protected:
	WrongAnimal( std::string );

	std::string _type;
};

#endif