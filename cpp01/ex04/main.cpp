#include <iostream>
#include <fstream>

std::string *str_replace( std::string str, std::string to_replace, std::string replace_with )
{
	std::string *newstr = new std::string();
	std::size_t start = 0;
	std::size_t i = str.find(to_replace);

	while (i != std::string::npos)
	{
		newstr->append(str, start, i - start);
		if (str.compare(i, to_replace.length(), to_replace) == 0)
		{
			i += to_replace.length();
			newstr->append(replace_with);
		}
		start = i;
		i = str.find(to_replace, start);
	}
	newstr->append(str, start, str.length() - start);
	return newstr;
}

int main(int argc, char const *argv[])
{
	if (argc < 4)
	{
		std::cout << "usage: " << argv[0] << " <filename> <to_replace> <repace_with>" << std::endl;
		return 1;
	}
	std::string content;
	std::string line;
	std::string *replaced;
	std::string filename(argv[1]);
	std::ifstream infile(filename.c_str());
	std::ofstream outfile((filename + ".replace").c_str());
	
	while (getline(infile, line))
		content.append(line + "\n");
	replaced = str_replace(content, argv[2], argv[3]);
	outfile << *replaced;
	infile.close();
	outfile.close();
	delete replaced;
	return 0;
}
