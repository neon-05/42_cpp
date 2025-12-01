#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

void	read_data( std::map<std::string, float>& map );
void	calculate_amounts( std::string line, std::map<std::string, float>& map );

#endif
