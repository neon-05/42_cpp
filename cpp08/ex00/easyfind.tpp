#include "easyfind.hpp"

const char	*ItemNotFoundException::what( void ) const throw() { return "item not found"; }

template<typename T>
typename T::iterator	easyfind( T& container, int n )
{
	typename T::iterator	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (ItemNotFoundException());
	return (it);
}
