#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <deque>
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "../map/map.hpp"
	#include "../stack/stack.hpp"
	#include "../vector/vector.hpp"
#endif
#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

void original_test(int argc, char** argv);
void vector_test();
void   stack_test();
void     map_test();



#endif