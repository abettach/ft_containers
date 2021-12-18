#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
namespace ft
{   
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
    {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };
    template < class T >
    class MyIterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
    		typedef T pointer;
    		typedef typename iterator_traits<pointer>::iterator_category iterator_category;
    		typedef typename iterator_traits<pointer>::value_type value_type;
    		typedef typename iterator_traits<pointer>::difference_type difference_type;
    		typedef typename iterator_traits<pointer>::reference reference;
    	private:
    		pointer iter;
    	public:
            MyIterator() : iter(nullptr) {}
    		MyIterator(pointer it) : iter(it) {}                                    
            pointer base() const
    		{
    			return (iter);
    		}
    
    		reference operator*()
    		{
    			return (*iter);
    		}
    
    		MyIterator &operator++()
    		{
    			++iter;
    			return (*this);
    		}
    
    		MyIterator operator+(ptrdiff_t n)
    		{
    			iter += n;
    			return (*this);
    		}
    
    		MyIterator operator++(int)
    		{
    			MyIterator tmp(*this);
    			operator++();
    			return (tmp);
    		}
    
    		MyIterator operator+=(ptrdiff_t n)
    		{
    			iter += n;
    			return (*this);
    		}
    
    		MyIterator &operator-(ptrdiff_t n)
    		{
    			iter -= n;
    			return (*this);
    		}
    
    		MyIterator operator--()
    		{
    			iter--;
    			return iter;
    		}
    
    		MyIterator operator--(int)
    		{
    			MyIterator tmp(*this);
    			operator--();
    			return tmp;
    		}
    
    		MyIterator operator-=(ptrdiff_t n)
    		{
    			iter -= n;
    			return (*this);
    		}
    
    		reference operator[](ptrdiff_t n)
    		{
    			return (iter[n]);
    		}
    
    		bool operator==(const MyIterator &other) const
    		{
    			return (iter == other.iter);
    		}
    
    		bool operator!=(const MyIterator &other) const
    		{
    			return (this->iter != other.iter);
    		}
    };
}

#endif