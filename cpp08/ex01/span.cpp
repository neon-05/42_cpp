#include "Span.hpp"
#include <algorithm>

Span::Span( uint l ) : _nums(0), _vec(l) {}
Span::Span( const Span& other ) : _nums(other._nums), _vec(other._vec) {}
Span::~Span( void ) {}

Span&	Span::operator=( const Span& other )
{
	_nums = other._nums;
	_vec = std::vector<int>(other._vec);
}

void	Span::addNumber( int n )
{
	std::vector<int>::iterator	std::find_if(_vec.begin(), _vec.end(), [n](int i){return i > n;});
	
}
