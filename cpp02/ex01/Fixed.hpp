#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
public:
	Fixed( void );
	Fixed( const int );
	Fixed( const float );
	Fixed( const Fixed& );
	~Fixed();

	Fixed& operator=( const Fixed& );

	int getRawBits( void ) const;
	void setRawBits( const int );
	int toInt( void ) const;
	float toFloat( void ) const;

private:
	int _value;
	static const int _fractional_bits;
};

std::ostream& operator<<( std::ostream&, const Fixed& x );

#endif