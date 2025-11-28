#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <algorithm>
#include <iostream>
typedef unsigned int uint;

class Span
{
private:
	std::vector<int>	_vec;

public:
	Span( uint );
	Span( const Span& );
	~Span( void );
	Span&	operator=( const Span& );

	void	addNumber( int );
	template<typename It>
	void	addNumbers( It, It );

	int		shortestSpan( void ) const;
	int		longestSpan( void ) const;

	const std::vector<int>&	getVec( void ) const;
	int						getCapacity( void ) const;

	class CannotAddItemException: public std::exception
	{
	public:
		const char	*what( void ) const throw();
	};

	class NotEnoughItemsException: public std::exception
	{
	public:
		const char	*what( void ) const throw();
	};
};

std::ostream& operator<<( std::ostream& os, const Span& span );

template<typename It>
void	Span::addNumbers( It begin, It end )
{
	while (begin < end)
		addNumber(*(begin++));
}

#endif
