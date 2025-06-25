#ifndef CONTACT_HPP
#define CONTACT_HPP
#define MAX_FIELD_LENGTH 10
#include <iostream>

class Contact
{
public:
	void displayLine( size_t );
	void displayFull( void );
	void inputContactInfo( void );

	Contact( void );
	~Contact();

private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;

	bool _check_fields();
};

#endif