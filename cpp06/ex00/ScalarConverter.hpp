#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
public:
	static void	convert( std::string& );

private:
	ScalarConverter();
	ScalarConverter( const ScalarConverter& );
	~ScalarConverter();
	ScalarConverter& operator=( const ScalarConverter& );
};

#endif
