#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
// #include <string>
// #include <vector>
namespace ft
{
    template < class T, class Alloc = std::allocator<T> > class vector
    {
    private:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference	 const_reference;
        typedef typename allocator_type::pointer	pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef size_t size_type;
    private:
       value_type *arr;
       size_type _size;
       size_type _capacity;
       Alloc _alloc;
    public:
        vector()
        {
            arr = new T[1];
            _size = 0;
            _capacity = 1;
        }
        void push_back (const value_type& val)
        {
            if (_size == _capacity)
            {
                T *tmp = new T[2 * _capacity];
                for (size_t i = 0; i < _capacity; i++)
                    tmp[i] = arr[i];
                delete[] arr;
                arr = tmp;
                _capacity *= 2;
            }
            arr[_size] = val;
            _size++;
        }
        void    pop_back()
        {
            _size--;
        }
        size_type size() const
        {
            return (this->_size);
        }
        int     capacity()
        {
            return (this->_capacity);
        }
        size_type max_size() const
        {
            return ();
        }
        T   operator[](int i)
        {
            return arr[i];
        }
        class iterator : 
    };
}

#endif