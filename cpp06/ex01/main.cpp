#include "Serializer.hpp"

static void	init_data( Data *ptr )
{
	ptr->i = rand();
	ptr->ptr = ptr;
	ptr->s = "this is an awesome string";
}

static void	print_data( Data *ptr )
{
	std::cout << "---/ printing struct at " << ptr << " /---" << std::endl;
	std::cout << "int:\t" << ptr->i << std::endl;
	std::cout << "ptr:\t" << ptr->ptr << std::endl;
	std::cout << "str:\t" << ptr->s << std::endl;
}

int main( void )
{
	srand(time(NULL));
	Data *ptr = new Data;
	Data *nptr;
	uintptr_t s;

	init_data(ptr);
	print_data(ptr);

	s = Serializer::serialize(ptr);
	nptr = Serializer::deserialize(s);

	print_data(nptr);


	delete ptr;
	return 0;
}
