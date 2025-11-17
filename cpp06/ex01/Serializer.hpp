#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

typedef struct Data_s
{

}	Data;


class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
};

#endif