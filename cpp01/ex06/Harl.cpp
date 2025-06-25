#include "Harl.hpp"

Harl::Harl( void ) {}
Harl::~Harl() {}

void Harl::complain ( std::string level )
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (i < _HARL_COMPLAINING_LEVELS && level != levels[i]) i++;

	switch (i)
	{
	case 0:
		_debug();
		__attribute__((fallthrough)) ;
	case 1:
		_info();
		__attribute__((fallthrough)) ;
	case 2:
		_warning();
		__attribute__((fallthrough)) ;
	case 3:
		_error();
		break;
	default:
		std::cout << "*mumbling something underr his breath*" << std::endl;
		break;
	}
}

void Harl::_debug( void )	{ std::cout << _HARL_DEBUG_TEXT << std::endl; }
void Harl::_info( void )	{ std::cout << _HARL_INFO_TEXT	 << std::endl; }
void Harl::_warning( void )	{ std::cout << _HARL_WARNING_TEXT << std::endl; }
void Harl::_error( void )	{ std::cout << _HARL_ERROR_TEXT << std::endl; }