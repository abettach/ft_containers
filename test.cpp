#include <iostream>
#include <vector>
int     main()
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(9);
    vec.push_back(8);

    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
    vec.resize(2,8);
    std::cout << "After Resize" << std::endl;
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
}