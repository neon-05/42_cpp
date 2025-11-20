#include "Base.hpp"
#include "colors.h"
#define REPS 20

Base::~Base( void ) {}

static Base	*generate( void )
{
	int r = rand() % 3;
	std::cout << "generating obj of class ";
	switch (r)
	{
	case 0:
		std::cout << RED "A" RESET << std::endl;
		return new A;
	case 1:
		std::cout << GREEN "B" RESET << std::endl;
		return new B;
	case 2:
		std::cout << BLUE "C" RESET << std::endl;
		return new C;
	default:
		return NULL;
	}
}

static void identify( Base *obj )
{
	std::cout << "(ptr) object is of the class ";
	if (dynamic_cast<A*>(obj))
		std::cout << RED "A" RESET << std::endl;
	if (dynamic_cast<B*>(obj))
		std::cout << GREEN "B" RESET << std::endl;
	if (dynamic_cast<C*>(obj))
		std::cout << BLUE "C" RESET << std::endl;
}

static void identify( Base& obj )
{
	std::cout << "(ref) object is of the class ";
	try
	{
		dynamic_cast<A&>(obj);
		std::cout << RED "A" RESET << std::endl;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		dynamic_cast<B&>(obj);
		std::cout << GREEN "B" RESET << std::endl;
		return;
	}
	catch(const std::exception& e)
	{}
	try
	{
		dynamic_cast<C&>(obj);
		std::cout << BLUE "C" RESET << std::endl;
		return;
	}
	catch(const std::exception& e)
	{}
}

int main( void )
{
	srand(time(NULL));
	Base *ptr;
	for (int i = 0; i < REPS; i++)
	{
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
	}
	return 0;
}

