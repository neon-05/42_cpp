#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdlib.h>
#include <stdint.h>
#include <iostream>

typedef struct Data_s
{
	std::string	s;
	int			i;
	void		*ptr;
}	Data;

class Serializer
{
public:
	static uintptr_t	serialize( Data* );
	static Data*		deserialize( uintptr_t );

private:
	Serializer();
	Serializer( const Serializer& );
	~Serializer();
	Serializer& operator=( const Serializer& );
};

#endif