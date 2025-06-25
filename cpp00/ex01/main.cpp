#include "PhoneBook.hpp"
#include "Contact.hpp"

void	search_contact(PhoneBook& phoneBook)
{
	std::string		in;
	unsigned int	i;

	phoneBook.displayList();
	if (phoneBook.getContactCount() == 0)
		return;
	std::cout << "display contact at index (0-" << phoneBook.getContactCount()-1 << "): ";
	getline(std::cin, in);
	i = in[0]-'0';
	if (i < phoneBook.getContactCount())
		phoneBook.getContact(i).displayFull();
	else
		std::cout << "invalid index" << std::endl;
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (getline(std::cin, cmd))
	{
		if (cmd == "EXIT")
			break;
		else if (cmd == "SEARCH")
			search_contact(phoneBook);
		else if (cmd == "ADD")
			phoneBook.addContact();
		else
			std::cout << "invalid action" << std::endl;
	}
	return 0;
}

