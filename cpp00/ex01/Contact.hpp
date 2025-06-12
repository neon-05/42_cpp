#ifndef CONTACT_HPP
#define CONTACT_HPP
#define MAX_FIELD_LENGTH 10
#include <iostream>

class Contact
{
private:
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

public:
	void	display_line(int id);
	void	display_full();
	bool	check_fields();
	void	input_contact();

	Contact(
		std::string firstname,
		std::string lastname,
		std::string nickname,
		std::string	phone_number,
		std::string	darkest_secret
	);
	Contact();
	~Contact();
};

#endif