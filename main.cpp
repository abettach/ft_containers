#include "vector/vector.hpp"
#include "stack/stack.hpp"
#include <iostream>
// #include <vector>
// #include <string>
int main()
{
    // ft::vector<int> vec;
    ft::stack<int> test;

    test.push(5);
    // test.push(6);
    // test.push(7);

    // std::cout << vec[0] << std::endl;
    std::cout << test.top() << std::endl;

    
    return 0;

}