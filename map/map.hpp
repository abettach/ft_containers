#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <string>

namespace ft
{
    typedef pair<const Key, T> value_type;
    template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T>>>
    class map
    { 
        private:
            typedef Key key_type;
            typedef T mapped_type;
            typedef pair<const key_type,mapped_type> value_type;
            typedef Compare key_type;
            // typedef ... value_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            //iterator
            //const_iterator
            //reverse_iterator
            //const_reverse iterator
            typedef ptrdiff_t difference_type;
            typedef size_t size_type;

    };
}

#endif