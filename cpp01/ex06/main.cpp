#include "Harl.hpp"

int main(int argc, char const *argv[])
{
	if (argc < 2)
	{
		std::cout << "*not complaining for once*" << std::endl;
		return 0;
	}
	Harl harl;
	harl.complain(argv[1]);
	return 0;
}
