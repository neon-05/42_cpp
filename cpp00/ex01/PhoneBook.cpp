#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->ccount = 0;
}

PhoneBook::~PhoneBook() {}

PhoneBook	*PhoneBook::add(Contact contact)
{
	this->list[ccount & 7] = contact;
	if (ccount < 8)
		this->ccount++;
	return this;
}

void	PhoneBook::display_list()
{
	if (this->ccount == 0)
		std::cout << "no entries." << std::endl;
	else if (this->ccount == 1)
		std::cout << "1 entry:" << std::endl;
	else
		std::cout << this->ccount << " entries:" << std::endl;
	for (size_t i = 0; i < this->ccount; i++)
		this->list[i].display_line(i);
}

size_t	PhoneBook::getCCount()
{
	return	this->ccount;
}

Contact	*PhoneBook::getContact(unsigned int id)
{
	if (this->ccount > id)
		return (&this->list[id]);
	else
		return NULL;
}

/*
int main()
{
	PhoneBook p;

	p.add(Contact("yohann", "labussiere", "neon_05"));
	p.add(Contact("mae", "lllllllllllllllllll", "Loufok0"));
	p.add(Contact("yohann", "labussiere", "neon_05"));
	p.add(Contact("mae", "lllllllllllllllllll", "Loufok0"));
	p.add(Contact("yohann", "labussiere", "neon_05"));
	p.add(Contact("mae", "lllllllllllllllllll", "Loufok0"));
	p.add(Contact("yohann", "labussiere", "neon_05"));
	p.add(Contact("mae", "lllllllllllllllllll", "Loufok0"));
	p.add(Contact("mae", "849551", "Loufok0"));
	p.display_list();
	return 0;
}*/
