#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	std::stack<int>	stack;
	if (argc < 2)
		return std::cerr << "no expression provided" << std::endl, 1;
	for (const char *c = argv[1]; *c; c++)
	{
		if (*c != ' ' && process_token(*c, stack))
			return 1;
	}

	if (stack.size() > 0)
		std::cout << stack.top() << std::endl;
	else
		std::cerr << "no element in the stack" << std::endl;
	return 0;
}
