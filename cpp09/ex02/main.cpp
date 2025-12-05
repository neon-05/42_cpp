#include "PmergeMe.hpp"

void print_time( clock_t t )
{
	static const char *unit[] = {"μs", "ms", "s", "Ks", "Ms", "Gs"};
	int scale = 1;
	int i = 0;
	while (i < 6 && t / scale > 999)
	{
		i++;
		scale *= 1000;
	}
	std::cout << t / scale << '.' << std::setw(i * 3) << std::setfill('0') << t%scale << ' ' << unit[i];
}

int main( int argc, char *argv[] )
{
	if (argc < 2)
	{
		std::cerr << "please enter at least one number to be sorted" << std::endl;
		return 1;
	}
	std::vector<int>	vec, vec2;
	std::deque<int>		deq;
	for (int i = 1; i < argc; i++)
	{
		int n = atoi(argv[i]);
		vec.push_back(n);
		vec2.push_back(n);
		deq.push_back(n);
	}
	std::cout << "unsorted:\t";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << ((i == 0) ? "{" : ", ") << vec[i];
	std::cout << "}\n";
	
	clock_t begin;
	clock_t end;
	
	begin = clock();
	fordJhonsonSort(vec);
	end = clock();
	clock_t vec_time = end - begin;
	
	begin = clock();
	fordJhonsonSort(deq);
	end = clock();
	clock_t deq_time = end - begin;
	
	begin = clock();
	std::sort(vec2.begin(), vec2.end());
	end = clock();
	clock_t std_time = end - begin;
	
	std::cout << "sorted:\t\t";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << ((i == 0) ? "{" : ", ") << vec[i];
	std::cout << "}" << std::endl;

	std::cout << "vec:\t\t";
	print_time(vec_time);
	std::cout << std::endl;

	std::cout << "deq:\t\t";
	print_time(deq_time);
	std::cout << std::endl;

	std::cout << "vec (std sort):\t";
	print_time(std_time);
	std::cout << std::endl;
	return 0;
}

