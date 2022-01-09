#include "main.hpp"

void	stack_test_print()
{
    std::cout << std::endl << "\e[1;34m";
    std::cout << "___________________________________________________________________________________________" << std::endl;
	std::cout <<"  /$$$$$$  /$$$$$$$$ /$$$$$$   /$$$$$$  /$$   /$$       /$$$$$$$$ /$$$$$$$$  /$$$$$$  /$$$$$$$$" << std::endl;
	std::cout <<" /$$__  $$|__  $$__//$$__  $$ /$$__  $$| $$  /$$/      |__  $$__/| $$_____/ /$$__  $$|__  $$__/" << std::endl;
	std::cout <<"| $$  \\__/   | $$  | $$  \\ $$| $$  \\__/| $$ /$$/          | $$   | $$      | $$  \\__/   | $$" << std::endl;
	std::cout <<"|  $$$$$$    | $$  | $$$$$$$$| $$      | $$$$$/           | $$   | $$$$$   |  $$$$$$    | $$" << std::endl;
	std::cout <<" \\____  $$   | $$  | $$__  $$| $$      | $$  $$           | $$   | $$__/    \\____  $$   | $$" << std::endl;
	std::cout <<" /$$  \\ $$   | $$  | $$  | $$| $$    $$| $$\\  $$          | $$   | $$       /$$  \\ $$   | $$" << std::endl;
	std::cout <<"|  $$$$$$/   | $$  | $$  | $$|  $$$$$$/| $$ \\  $$         | $$   | $$$$$$$$|  $$$$$$/   | $$" << std::endl;
	std::cout <<" \\______/    |__/  |__/  |__/ \\______/ |__/  \\__/         |__/   |________/ \\______/    |__/" << std::endl;
	std::cout << "|__________________________________________________________________________________________";
    std::cout << "\e[1;37m" << std::endl << std::endl;
}

void   stack_test()
{
	stack_test_print();

    ft::stack<int> mystack;

	std::cout << "\e[1;31mpush Test:\e[1;37m" << std::endl;
    for (int i = 0; i < 5; ++i)
	{
		std::cout << "Pushing --> |\e[1;32m" << i << "\e[1;37m|" << " to mystack..." << std::endl;
		mystack.push(i);  
	}
	std::cout << "\e[1;31mSize Test:\e[1;37m" << std::endl;
	std::cout << "size: |\e[1;32m" << mystack.size() << "\e[1;37m|" << '\n';
	std::cout << "\e[1;31mPop Test:\e[1;37m" << std::endl;
	while (!mystack.empty())
	{
		std::cout << "Popping --> |\e[1;32m" << mystack.top() << "\e[1;37m|" << std::endl;
		mystack.pop();
	}
	std::cout << "\e[1;31mSize after Pop :\e[1;37m" << std::endl;
	std::cout << "size: |\e[1;32m" << mystack.size() << "\e[1;37m|" << std::endl;
}

















