#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2)
		return 2;

	Harl harl;
	harl.complain(argv[1]);
	return 0;
}
