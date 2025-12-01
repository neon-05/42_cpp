#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	std::stack<int>	s;
	if (argc < 2)
		return 1;
	for (const char *c = argv[1]; *c; c++)
	{
		if (!(c - argv[1]) & 1)
		{
			std::cout << c << std::endl;
			process_token(*c, s);
		}
		else if (*c && *c != ' ')
			return 1;
	}
	std::cout << s.top() << std::endl;
	return 0;
}

