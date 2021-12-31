#ifndef MAP_UTILS_HPP
#define MAP_UTILS_HPP
#include <iostream>
#include <string>
#include "../pair.hpp"
namespace ft
{
	template <class Key, class T>
	struct Node
	{
		std::pair<Key, T> pair;
		Node *left;
		Node *right;
		Node *parent;
		bool end;
	};
    template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
}

#endif