#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>
#define _HARL_COMPLAINING_LEVELS 4

#define _HARL_DEBUG_TEXT	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!"
#define _HARL_INFO_TEXT		"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
#define _HARL_WARNING_TEXT	"I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
#define _HARL_ERROR_TEXT	"This is unacceptable! I want to speak to the manager now."

class Harl
{
public:
	Harl( void );
	~Harl();
	void complain ( std::string );

private:
	void _debug( void );
	void _info( void );
	void _warning( void );
	void _error( void );
};

#endif