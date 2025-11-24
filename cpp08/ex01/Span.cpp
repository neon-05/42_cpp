#include "Span.hpp"

const char	*Span::CannotAddItemException::what( void ) const throw() { return "cannot add any more items in the span"; }
const char	*Span::NotEnoughItemsException::what( void ) const throw() { return "there aren't enough items stored. thre must be more than one"; }

Span::Span( uint l ) : _vec() { _vec.reserve(l); }
Span::Span( const Span& other ) :_vec(other._vec) {}
Span::~Span( void ) {}

Span&	Span::operator=( const Span& other )
{
	std::vector<int> _vec(other._vec);
	return *this;
}

void	Span::addNumber( int n )
{
	if (_vec.size() >= _vec.capacity())
		throw (CannotAddItemException());
	std::vector<int>::iterator	it = std::lower_bound(_vec.begin(), _vec.end(), n);
	_vec.insert(it, n);
}

int		Span::shortestSpan( void ) const
{
	int	tmp, diff = 0x7fffffff; /* max 32bit sint */
	if (_vec.size() < 2)
		throw (NotEnoughItemsException());
	std::vector<int>::const_iterator	it = _vec.begin();
	while(++it != _vec.end())
	{
		tmp = *it;
		tmp -= *(it - 1);
		if (tmp < diff)
			diff = tmp;
	}
	return diff;
}

int		Span::longestSpan( void ) const
{
	if (_vec.size() < 2)
		throw (NotEnoughItemsException());
	return _vec.back() - *_vec.begin();
}

const std::vector<int>&	Span::getVec( void) const { return _vec; }
int						Span::getCapacity( void ) const { return _vec.capacity(); }

std::ostream& operator<<( std::ostream& os, const Span& span )
{
	const std::vector<int>	vec = span.getVec();
	uint max = vec.size();
	for (uint i = 0; i < max; i++)
	{
		os << ((i == 0) ? "{" : ", ") << vec[i];
	}
	os << "} (" << max << '/' << span.getCapacity() << ")";
	return os;
}
