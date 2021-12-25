// #include "vector/vector.hpp"
// #include "stack/stack.hpp"
#include <iostream>
#include "pair.hpp"
#include <map>
// #include <vector>
// #include <string>
int main()
{
    ft::pair<int ,int> pt(5, 6);
    ft::pair<int, int> st(5, 6);
    bool a = (st == pt);
    std::cout << a << std::endl;

    return 0;

}