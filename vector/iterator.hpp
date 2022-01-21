#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

namespace ft
{   
	template <typename T>
	class MyIterator : public ft::iterator<std::random_access_iterator_tag, typename iterator_traits<T>::value_type>
	{
	public:
		typedef T pointer;
		typedef typename iterator_traits<pointer>::iterator_category iterator_category;
		typedef typename iterator_traits<pointer>::value_type value_type;
		typedef typename iterator_traits<pointer>::difference_type difference_type;
		typedef typename iterator_traits<pointer>::reference reference;
	private:
		pointer ptr;
	public:
		MyIterator() : ptr(nullptr) {}
		MyIterator(pointer it) : ptr(it) {}
		template <typename Iter>
		MyIterator(const MyIterator<Iter> &mit) : ptr(mit.base()) {}
		pointer base() const
		{
			return (ptr);
		}
		reference operator*()
		{
			return *ptr;
		}
		MyIterator &operator++()
		{
			++ptr;
			return *this;
		}
		MyIterator operator+(difference_type __n)
		{
			ptr += __n;
			return (*this);
		}
		MyIterator operator++(int)
		{
			MyIterator tmp(*this);
			operator++();
			return tmp;
		}
		MyIterator operator+=(difference_type __n)
		{
			ptr += __n;
			return (*this);
		}
		MyIterator &operator-(difference_type __n)
		{
			ptr -= __n;
			return (*this);
		}
		MyIterator operator--()
		{
			ptr--;
			return ptr;
		}
		MyIterator operator--(int)
		{
			MyIterator tmp(*this);
			operator--();
			return tmp;
		}
		MyIterator operator-=(difference_type __n)
		{
			ptr -= __n;
			return (*this);
		}
		reference operator[](difference_type __n)
		{
			return (ptr[__n]);
		}
		bool operator==(const MyIterator &rhs) const
		{
			return ptr == rhs.ptr;
		}
		bool operator!=(const MyIterator &rhs) const
		{
			return (this->ptr != rhs.ptr);
		}
		bool operator<(const MyIterator &rhs) const
		{
			return (this->ptr < rhs.ptr);
		}
	};
}

#endif