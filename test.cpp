#include <iostream>
#include <vector>
int     main()
{
    std::vector<int> first;
    std::vector<int> sec (10, 5);
	// ft::MyIterator<int> it = *sec.begin();
	std::cout << "size = " << first.size() << ", capacity = " << first.capacity() << std::endl;
    first.push_back(1);
	std::cout << "size = " << first.size() << ", capacity = " << first.capacity() << std::endl;
    first.push_back(2);
	std::cout << "size = " << first.size() << ", capacity = " << first.capacity() << std::endl;
    first.push_back(3);
	std::cout << "size = " << first.size() << ", capacity = " << first.capacity() << std::endl;
    first.push_back(4);
	std::cout << "size = " << first.size() << ", capacity = " << first.capacity() << std::endl;
    first.push_back(5);
	std::cout << "size = " << first.size() << ", capacity = " << first.capacity() << std::endl;
    // first.erase(first.begin() + 3);
	// std::cout << *it << std::endl;
    for (size_t i = 0; i < first.size(); i++)
        std::cout << first[0] << std::endl;
    return 0;
}