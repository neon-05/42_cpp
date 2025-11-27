#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
typedef unsigned int uint;

template <typename T>
class Array
{
public:
	Array( void );
	Array( uint );
	Array( const Array& );
	~Array( void );
	Array&	operator=( const Array& );

	class OutOfBoundsException: public std::exception
	{
	public:
		const char *what( void ) const throw();
	};

	T	operator[]( uint ) const;
	T&	operator[]( uint );

	uint	size( void ) const;

private:
	uint	_len;
	T		*_arr;
};

template <typename T>
std::ostream& operator<<( std::ostream&, const Array<T>& );

#include "Array.tpp"
#endif