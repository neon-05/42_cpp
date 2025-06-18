#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact	input_contact()
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "First name :";
	std::getline(std::cin, firstname);
	std::cout << "Last name :";
	std::getline(std::cin, lastname);
	std::cout << "Nickname :";
	std::getline(std::cin, nickname);
	std::cout << "Phone number :";
	std::getline(std::cin, phone_number);
	std::cout << "Darkest secret :";
	std::getline(std::cin, darkest_secret);

	return Contact(firstname, lastname, nickname, phone_number, darkest_secret);
}

void	add_contact(PhoneBook *phoneBook)
{
	Contact		newContact;

	while (!newContact.check_fields())
		newContact = input_contact();
	phoneBook->add(newContact);
}

void	search_contact(PhoneBook *phoneBook)
{
	std::string		in;
	unsigned int	i;

	phoneBook->display_list();
	if (phoneBook->getCCount() == 0)
		return;
	std::cout << "display contact at index (0-" << phoneBook->getCCount() << "):";
	std::getline(std::cin, in);
	i = in[0] - '0';
	if (i < phoneBook->getCCount())
		phoneBook->getContact(i)->display_full();
	else
		std::cout << "invalid index" << std::endl;
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (std::getline(std::cin, cmd))
	{
		if (cmd == "EXIT")
			break;
		else if (cmd == "SEARCH")
			search_contact(&phoneBook);
		else if (cmd == "ADD")
			add_contact(&phoneBook);
		else
			std::cout << "invalid action" << std::endl;
	}
	return 0;
}

