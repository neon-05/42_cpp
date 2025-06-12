#include <iostream>
#include <string>

int	main(int argc, char *argv[])
{
	int i = 1;
	std::string str;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		str = argv[i];
		for (size_t j = 0; j < str.length(); ++j)
			std::cout << (char) toupper(str[j]);
		i++;
	}
	std::cout << std::endl;
	return 0;
}
