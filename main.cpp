// #include "vector.hpp"
#include <iostream>
#include <vector>
#include <string>
int main()
{
	std::vector<int> first(3,5);
	// std::vector<int> sec(4,10);

	// first.push_back(77);
	// first.assign(7, 5);
	for (size_t i = 0; i < first.size(); i++)
		std::cout << first[i] << std::endl;
	// std::cout << "Afterr swap " << std::endl;
	// first.swap(sec);
	// for (size_t i = 0; i < first.size(); i++)
	// 	std::cout << first[i] << std::endl;
	// std::cout << "Afterr swap sec" << std::endl;
	// for (size_t i = 0; i < sec.size(); i++)
	// 	std::cout << sec[i] << std::endl;
	// std::cout << "after Clear " << std::endl;
	// std::cout << first.capacity() << ", " << first.size() << std::endl;
	// first.clear();
	std::cout << "after assign" << std::endl;
	first.assign(7, 100);
	for (size_t i = 0; i < first.size(); i++)
		std::cout << first[i] << std::endl;
	// std::cout << first.capacity() << ", " << first.size() << std::endl;

	return 0;
}