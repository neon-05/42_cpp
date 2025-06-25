#include "Harl.hpp"

Harl::Harl( void ) {}
Harl::~Harl() {}

void Harl::complain ( std::string level )
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functions[])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for(int i = 0; i < _HARL_COMPLAINING_LEVELS; i++)
	{
		if (level != levels[i])
			continue;
		(this->*functions[i])();
		return;
	}
	std::cout << "*mumbling something underr his breath*" << std::endl;
}

void Harl::_debug( void )	{ std::cout << _HARL_DEBUG_TEXT << std::endl; }
void Harl::_info( void )	{ std::cout << _HARL_INFO_TEXT	 << std::endl; }
void Harl::_warning( void )	{ std::cout << _HARL_WARNING_TEXT << std::endl; }
void Harl::_error( void )	{ std::cout << _HARL_ERROR_TEXT << std::endl; }