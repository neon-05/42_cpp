#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
typedef unsigned int uint;

template <typename T>
class Array
{
private:
	T		*_arr;
	uint	len;

public:
	Array( uint );
	Array( T *, uint );
	Array( const Array& );
	~Array( void );
	Array& operator=( const Array& );

	class OutOfBoundsException: public std::exception
	{
	public:
		const char *what( void ) const throw();
	};

	T& operator[]( int );
	T operator[]( int ) const;
};


#endif