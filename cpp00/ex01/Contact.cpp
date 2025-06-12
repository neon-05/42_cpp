#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(
	std::string firstname,
	std::string lastname,
	std::string nickname,
	std::string phone_number,
	std::string darkest_secret
)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

std::string	display_field(std::string str, size_t len)
{
	if (len == 0)
		return str;
	else if (str.length() > len)
		return str.substr(0, len - 1).append(".");
	else
		return std::string (len - str.length(), ' ').append(str);
}

void	Contact::display_line(int id)
{
	std::string line;
	line.append("|").append(display_field(this->firstname, MAX_FIELD_LENGTH));
	line.append("|").append(display_field(this->lastname, MAX_FIELD_LENGTH));
	line.append("|").append(display_field(this->nickname, MAX_FIELD_LENGTH));
	std::cout << id << line << std::endl;
}



void	Contact::display_full()
{
	std::cout << "First name: " << this->firstname << std::endl;
	std::cout << "Last name: " << this->lastname << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}

bool	Contact::check_fields()
{
	if (this->firstname == "")
		return false;
	else if (this->lastname == "")
		return false;
	else if (this->nickname == "")
		return false;
	else if (this->phone_number == "")
		return false;
	else if (this->darkest_secret == "")
		return false;
	else
		return true;
}
