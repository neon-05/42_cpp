#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
typedef unsigned int uint;

class Span
{
private:
	uint				_nums;
	std::vector<int>	_vec;

public:
	Span( uint );
	Span( const Span& );
	~Span( void );
	Span&	operator=( const Span& );

	void addNumber( int );

	int shortestSpan() const;
	int longestSpan() const;

	class CannotAddItemException: public std::exception
	{
	public:
		const char *what( void ) const throw();
	};

	class NotEnoughItemsException: public std::exception // is that a mfking minecaft reference ?
	{
	public:
		const char *what( void ) const throw();
	};
};

#endif
