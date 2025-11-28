#include <map>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

bool check_valid_date( std::string s )
{
	(void)s;
	return true;
}

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
	std::ifstream					data("data.csv");
	std::string						line;
	std::pair<std::string, float>	p;
	std::getline(data, line);
	while(std::getline(data, line))
	{
		p.first = line.substr(0, 10);
		p.second = strtof(line.c_str() + 11, NULL);
		if (!check_valid_date(p.first) || isinf(p.second) || isnan(p.second))
			continue;
		if (map.count(p.first) > 0)
			std::cerr << "WARNING: duplicate date record. may result in undefined behavior" << std::endl;
		map.insert(map.end(), p);
	}
}

int main( void )
{
	std::map<std::string, float>	map;
	std::string						key = "2009-01-01";
	std::map<std::string, float>::iterator it;
	read_data(map);
	it = map.upper_bound(key);
	if (it == map.begin())
		return 1;
	it--;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << it->first << "," << it->second << std::endl;
	return 0;
}
