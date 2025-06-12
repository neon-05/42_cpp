#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	list[8];
	size_t	ccount;

public:
	PhoneBook	*add(Contact	contact);
	Contact		*getContact(unsigned int id);
	size_t		getCCount();
	void		display_list();

	PhoneBook(void);
	~PhoneBook();
};

#endif
