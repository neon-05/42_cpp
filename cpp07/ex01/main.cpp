#include "iter.hpp"
#include <cstring>

static void print( const char& c )
{
	std::cout << c;
}

static void toupper( char& c )
{
	if (islower(c))
		c -= 32;
}

int main( int argc, char *argv[] )
{
	if (argc < 2)
		return 2;

	iter(argv[1], strlen(argv[1]), print);
	std::cout << std::endl;
	iter((char *) argv[1], strlen(argv[1]), toupper);
	std::cout << argv[1] << std::endl;
	return 0;
}
