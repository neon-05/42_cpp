#include "ScalarConverter.hpp"

static void	print_int(int int_val, double float_val, bool float_from_int);
static void	print_float(int int_val, double float_val, bool float_from_int);

void	ScalarConverter::convert( std::string& s )
{
	double		float_val;
	int			int_val;
	const char	*s1;
	char		*s2;

	s1 = s.c_str();
	float_val = strtod(s1, &s2);
	bool float_from_int = (s1 == s2);
	if (float_from_int)
		int_val = s[0];
	else
		int_val = static_cast<int>(float_val);
	print_int(int_val, float_val, float_from_int);
	print_float(int_val, float_val, float_from_int);
}

static void	print_int(int int_val, double float_val, bool float_from_int)
{
	if (float_from_int)
	{
		if (isprint(int_val & 0xFF))
			std::cout << "char:\t'" << static_cast<char>(int_val) << "'\n";
		else
			std::cout << "char:\tcannot print character\n";
		std::cout << "int:\t" << int_val << std::endl;
	}
	else if (isinf(float_val) || isnan(float_val))
	{
		std::cout << "char:\timpossible\n";
		std::cout << "int:\timpossible\n";
	}
	else
	{
		if (float_val > 2147483647.)
			std::cout << "warning: number is too large for int type and will overflow\n";
		else if (float_val < -2147483648.)
			std::cout << "warning: number is too small for int type and will underflow\n";
		if (isprint(int_val & 0xFF))
			std::cout << "char:\t'" << static_cast<char>(int_val) << "'\n";
		else
			std::cout << "char:\tcannot print character\n";
		std::cout << "int:\t" << int_val << "\n";
	}
}

static void	print_float(int int_val, double float_val, bool float_from_int)
{
	if (float_from_int)
		float_val = static_cast<double>(int_val);
	std::cout << std::fixed << std::setprecision(20);
	std::cout << "float:\t" << static_cast<float>(float_val) << "f\n";
	std::cout << "double:\t" << float_val << std::endl;
}
