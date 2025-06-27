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
	friend std::ostream& operator<<( std::ostream&, const Fixed& x );

	bool operator>( const Fixed ) const;
	bool operator<( const Fixed ) const;
	bool operator>=( const Fixed ) const;
	bool operator<=( const Fixed ) const;
	bool operator==( const Fixed ) const;
	bool operator!=( const Fixed ) const;

	Fixed operator+( const Fixed ) const;
	Fixed operator-( const Fixed ) const;
	Fixed operator*( const Fixed ) const;
	Fixed operator/( const Fixed ) const;

	Fixed operator++( void );
	Fixed operator--( void );
	Fixed operator++( int );
	Fixed operator--( int );

	static Fixed& min( Fixed&, Fixed& );
	static Fixed& max( Fixed&, Fixed& );
	static const Fixed& min( const Fixed&, const Fixed& );
	static const Fixed& max( const Fixed&, const Fixed& );

	int getRawBits( void ) const;
	void setRawBits( const int );

	int toInt( void ) const;
	float toFloat( void ) const;

private:
	int _value;
	static const int _fractional_bits;
};


#endif