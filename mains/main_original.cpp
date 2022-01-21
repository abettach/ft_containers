#include "main.hpp"

void    original_test()
{
    std::cout << std::endl << "\e[1;34m";
    std::cout << "__________________________________________________________________________________________________________" << std::endl;
    std::cout <<"  /$$$$$$  /$$$$$$$  /$$$$$$  /$$$$$$  /$$$$$$ /$$   /$$  /$$$$$$  /$$             /$$$$$$$$ /$$$$$$$$  /$$$$$$  /$$$$$$$$" << std::endl;
    std::cout <<" /$$__  $$| $$__  $$|_  $$_/ /$$__  $$|_  $$_/| $$$ | $$ /$$__  $$| $$            |__  $$__/| $$_____/ /$$__  $$|__  $$__/" << std::endl;
    std::cout <<"| $$  \\ $$| $$  \\ $$  | $$  | $$  \\__/  | $$  | $$$$| $$| $$  \\ $$| $$               | $$   | $$      | $$  \\__/   | $$" << std::endl;
    std::cout <<"| $$  | $$| $$$$$$$/  | $$  | $$ /$$$$  | $$  | $$ $$ $$| $$$$$$$$| $$               | $$   | $$$$$   |  $$$$$$    | $$" << std::endl;
    std::cout <<"| $$  | $$| $$__  $$  | $$  | $$|_  $$  | $$  | $$  $$$$| $$__  $$| $$               | $$   | $$__/    \\____  $$   | $$" << std::endl;
    std::cout <<"| $$  | $$| $$  \\ $$  | $$  | $$  \\ $$  | $$  | $$\\  $$$| $$  | $$| $$               | $$   | $$       /$$  \\ $$   | $$" << std::endl;
    std::cout <<"|  $$$$$$/| $$  | $$ /$$$$$$|  $$$$$$/ /$$$$$$| $$ \\  $$| $$  | $$| $$$$$$$$         | $$   | $$$$$$$$|  $$$$$$/   | $$" << std::endl;
    std::cout <<" \\______/ |__/  |__/|______/ \\______/ |______/|__/  \\__/|__/  |__/|________/         |__/   |________/ \\______/    |__/" << std::endl;
    std::cout << "|_________________________________________________________________________________________________________";
    std::cout << "\e[1;37m" << std::endl << std::endl;
}

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->container = rhs.container;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->container.begin(); }
	iterator end() { return this->container.end(); }
};

void original_test(int argc, char** argv)
{
    original_test();
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		exit(1);
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;
	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
}