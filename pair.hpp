#ifndef PAIR_HPP
#define PAIR_HPP
#include <iostream>
#include <string>

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair(): first(), second() {}
        template<class U, class V>
        pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}
        pair (const first_type& a, const second_type& b) : first(a), second(b) {}

        pair    &operator=(const pair &other)
        {
            if (this != &other)
            {
                first = other.first;
                second = other.second;
            }
            return *this;
        }
    };
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
        if (x.first == y.first && x.second == y.second)
            return true;
        return false;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		if ((x.first != y.first && x.second == y.second) ||
        ((x.first == y.first && x.second != y.second)) ||
        ((x.first != y.first && x.second != y.second)))
            return true;
        return false;
	}
	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return (y < x);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(x < y);
	}
	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
        if (x.first < y.first || ((y.first >= x.first) && x.second < y.second))
            return true;
        return false;
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &x, const pair<T1, T2> &y)
	{
		return !(y < x);
	}

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}

}

#endif