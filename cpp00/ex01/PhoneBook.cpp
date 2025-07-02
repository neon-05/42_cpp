#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _totalContactsAdded(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact()
{
	_contacts[_totalContactsAdded % MAX_CONTACTS].inputContactInfo();
	_totalContactsAdded++;
}

void	PhoneBook::displayList()
{
	if (_totalContactsAdded == 0)
		std::cout << "no entries." << std::endl;
	else if (_totalContactsAdded == 1)
		std::cout << "1 entry:" << std::endl;
	else
		std::cout << MIN(MAX_CONTACTS, _totalContactsAdded) << " entries:" << std::endl;
	for (size_t i = 0; i < MIN(MAX_CONTACTS, _totalContactsAdded); i++)
		_contacts[i].displayLine(i);
}

size_t PhoneBook::getContactCount() { return MIN(MAX_CONTACTS, _totalContactsAdded); }

Contact& PhoneBook::getContact(size_t i) { return (_contacts[i]); }
