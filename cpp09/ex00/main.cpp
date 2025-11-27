#include <map>
#include <ctime>
#include <iostream>
#include <fstream>

/*
for line in data.csv
	read csv line
	put in map

for line in input
split at |
find date
check value
print
*/
void read_data( std::map<std::string, float>& map )
{
	std::ifstream	data("data.csv");
	std::string		line;
	char			sep;
	std::getline(data, line);
	if (line.compare(0, 4, "data"))
		sep = line[4];
	while(std::getline(data, line));
		map.
	(void)map;
}

int main( void )
{
	std::map<std::string, float>	map;
	read_data(map);
	return 0;
}
