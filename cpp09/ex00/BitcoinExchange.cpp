#include "BitcoinExchange.hpp"

static bool	check_valid_date( std::string s )
{
	const char *data = s.c_str();
	char *end;

	strtoul(data, &end, 10);
	if (end - data != 4)
		return false;
	strtoul(data + 5, &end, 10);
	if (end - data != 7)
		return false;
	strtoul(data + 8, &end, 10);
	if (end - data != 10)
		return false;
	return ((data[4] & data[7]) == '-');
}
void		read_data( std::map<std::string, float>& map )
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

void		calculate_amounts( std::string line, std::map<std::string, float>& map )
{
	std::string	date = line.substr(0, 10);
	float val = strtof(line.c_str() + 13, NULL);
	float rate;
	std::map<std::string, float>::iterator it;

	if (!check_valid_date(date) || line.substr(10, 3).compare(" | "))
	{
		std::cerr << "bad input => " << line << std::endl;
		return;
	}
	if (val < 0.f)
	{
		std::cerr << "not a postitve number" << std::endl;
		return;
	}
	if (val > 1000.f)
	{
		std::cerr << "number too large, must be less than 1000.f" << std::endl;
		return;
	}
	it = map.upper_bound(date);
	if (it == map.begin())
	{
		std::cerr << date << " is before the first record" << std::endl;
		return;
	}
	it--;
	rate = it->second;
	std::cout << date << " => " << val << " = " << val * rate << std::endl;
}
