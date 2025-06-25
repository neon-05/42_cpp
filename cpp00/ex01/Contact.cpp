#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

static std::string	truncate(std::string str, size_t len)
{
	if (len == 0)
		return str;
	else if (str.length() > len)
		return str.substr(0, len - 1).append(".");
	else
		return std::string (len - str.length(), ' ').append(str);
}

void	Contact::displayLine(size_t id)
{
	std::string line;
	line.append("|").append(truncate(_firstname, MAX_FIELD_LENGTH));
	line.append("|").append(truncate(_lastname, MAX_FIELD_LENGTH));
	line.append("|").append(truncate(_nickname, MAX_FIELD_LENGTH));
	std::cout << id << line << std::endl;
}

void	Contact::displayFull()
{
	std::cout << "First name: " << _firstname << std::endl;
	std::cout << "Last name: " << _lastname << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
}


void Contact::inputContactInfo( void )
{
	while (1)
	{
		std::cout << "First name: ";
		std::getline(std::cin, _firstname);
		std::cout << "Last name: ";
		std::getline(std::cin, _lastname);
		std::cout << "Nickname: ";
		std::getline(std::cin, _nickname);
		std::cout << "Phone number: ";
		std::getline(std::cin, _phone_number);
		std::cout << "Darkest secret: ";
		std::getline(std::cin, _darkest_secret);
		if (_check_fields())
			break;
		else
			std::cout << "one of the fields is invalid, please try again" << std::endl;
	}
	std::cout << "successfully set contact info for " << _firstname << " " << _lastname << std::endl;
}

bool	Contact::_check_fields()
{
	if (_firstname == "")
		return false;
	else if (_lastname == "")
		return false;
	else if (_nickname == "")
		return false;
	else if (_phone_number == "")
		return false;
	else if (_darkest_secret == "")
		return false;
	else
		return true;
}
