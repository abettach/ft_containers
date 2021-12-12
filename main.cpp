#include "vector.hpp"

int main()
{
    ft::vector<int> a;

    // t.a = 10;
    // std::cout << t.a << std::endl;
    // std::cout << "Done " << std::endl;
    a.push_back(5);
    a.push_back(5);
    a.push_back(5);
    a.push_back(4);
    std::cout << a.size() << std::endl;
    return 0;
}