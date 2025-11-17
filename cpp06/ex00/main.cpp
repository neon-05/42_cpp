#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	std::string s;
	if (argc < 2)
		return 1;
	s = argv[1];
	ScalarConverter::convert(s);
	return 0;
}
