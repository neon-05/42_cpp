#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
public:
	Fixed( void );
	Fixed( const Fixed& );
	Fixed& operator=( const Fixed& );
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( const int );

private:
	int _value;
	static const int _fractional_bits;
};

#endif