#include <iostream>
#include <vector>
#include <stack>

int     main()
{
    // std::vector<int> first (3,5);
    std::stack<int> test(5);

    test.push(5);
    test.push(6);
    test.push(8);
    test.push(7);

    while(!(test.empty()))
    {
        std::cout << test.top() << std::endl;
        test.pop();
    }
    return 0;
}