#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>

template<typename T>
typename T::iterator	easyfind( T& container, int n );

class ItemNotFoundException: public std::exception
	{
	public:
		const char *what( void ) const throw();
	};

#include "easyfind.tpp"
#endif