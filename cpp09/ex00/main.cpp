#include "BitcoinExchange.hpp"

int main( int argc, const char *argv[] )
{
	if (argc < 2)
	{
		std::cerr << "no input file specified" << std::endl;
		return 1;
	}
	std::ifstream					input(argv[1]);
	std::map<std::string, float>	map;
	std::string						line;
	read_data(map);
	std::getline(input, line);
	while (std::getline(input, line))
		calculate_amounts(line, map);
	return 0;
}
