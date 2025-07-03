#ifndef CAT_HPP
#define CAT_HPP
#include <string>
#include "Animal.hpp"


class Cat: public Animal
{
public:
	Cat( void );
	Cat( const Cat& );
	~Cat();

	Cat& operator=( const Cat& );
	void makeSound( void ) const;
};

#endif