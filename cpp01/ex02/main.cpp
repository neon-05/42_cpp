#include <iostream>

int main( void )
{
	std::string string = "HAIII DIS IZ BRAINZ";
	std::string *stringptr = &string;
	std::string &stringref = string;

	std::cout << "&string		: " << &string << std::endl;	 // memory address of string
	std::cout << "stringptr	: " << stringptr << std::endl;		 // address held by stringptr
	std::cout << "&stringref	: " << &stringref << std::endl;	 // address held by stringref

	std::cout << "string		: " << string << std::endl;		 // value of the string
	std::cout << "*stringptr	: " << *stringptr << std::endl;	 // value pointed to by stringptr
	std::cout << "stringref	: " << stringref << std::endl;		 // value pointed to by stringref
	return 0;
}
