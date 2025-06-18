#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon
{
public:
	Weapon( std::string );
	Weapon();
	~Weapon();
	void setType( std::string );
	std::string& getType( void );

private:
	std::string _type;
};

#endif