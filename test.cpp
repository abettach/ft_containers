#include <iostream>
#include <vector>
int     main()
{
    std::vector <int> test;

    test.push_back(9);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);

    try
    {
    test.at(6);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // std::vector<int> vec;
    // vec.push_back(5);
    // vec.push_back(4);
    // vec.push_back(9);
    // vec.push_back(8);

    // for (size_t i = 0; i < vec.size(); i++)
    //     std::cout << vec[i] << std::endl;
    // vec.resize(2,8);
    // std::cout << "After Resize" << std::endl;
    // for (size_t i = 0; i < vec.size(); i++)
    //     std::cout << vec[i] << std::endl;
}