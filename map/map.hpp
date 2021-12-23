#ifndef MAP_HPP
#define MAP_HPP

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
            
    };
}

#endif