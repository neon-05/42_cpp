#include <ctime>
#include <iostream>

int main( void )
{
	std::time_t timestamp;
	time(&timestamp);

// Display the date and time represented by the timestamp
	std::cout << ctime(&timestamp);
	std::cout << timestamp;
	return 0;
}
