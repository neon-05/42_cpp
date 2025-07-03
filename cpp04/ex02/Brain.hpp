#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain
{
public:
	Brain( void );
	Brain( const Brain& );
	~Brain();

	Brain operator=( const Brain& );

	std::string _ideas[100];
};


#endif