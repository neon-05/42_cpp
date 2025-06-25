#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#define MAX_CONTACTS 8
#define MIN(a, b) ((a < b) ? a : b)
#include "Contact.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

class PhoneBook
{
public:
	PhoneBook( void );
	~PhoneBook();

	void addContact();
	Contact& getContact( size_t );
	size_t getContactCount();
	void displayList();

private:
	std::vector<Contact> _contacts;
	size_t _totalContactsAdded;
};

#endif
