#ifndef STACK_HPP
#define STACK_HPP
#include <iostream>
#include <string>
#include <deque>

namespace ft
{
    template <class T, class Container = std::deque<T> >
    class stack
    {
        public:
        typedef T value_type;
        typedef Container container_type;
        typedef size_t size_type;
        container_type container;

        explicit stack (const container_type& ctnr = container_type()) : container(ctnr) {};
        bool empty() const { return container.empty(); }
        size_type size() const { return container.size(); }
        void push (const value_type& val) { container.push_back(val); }
        void pop() { container.pop_back(); }
        value_type& top() { return *(--container.end()); }
        const value_type& top() const { return *(--container.end()); }
    };
    template <class T2, class Container2>
    bool operator==(const stack<T2, Container2> &lhs, const stack<T2, Container2> &rhs)
	{
		return lhs.container == rhs.container;
	}
    template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.containter != rhs.containter;
	}
    template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.containter < rhs.containter;
	}
    template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.containter <= rhs.containter;
	}
    template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.containter > rhs.containter;
	}
    template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return lhs.containter >= rhs.containter;
	}
}

#endif