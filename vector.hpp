#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
// #include <string>
// #include <vector>
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
    template< class Iterator >
    struct iterator_traits
    {
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
    };
    template< class T >
    struct iterator_traits<T*>
    {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef typename std::random_access_iterator_tag iterator_category;
    };
    template< class T >
    struct iterator_traits<const T*>
    {
        typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef typename std::random_access_iterator_tag iterator_category;
    };

    template < class T >
    class MyIterator : public std::iterator<std::random_access_iterator_tag, typename iterator_traits<T>::value_type>
    {
        public:

    };
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
    private:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef size_t size_type;
    private:
       allocator_type _alloc;
       value_type *_arr;
       size_type _size;
       size_type _capacity;
    public:
		vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _arr(nullptr), _size(0), _capacity(0)
		{
		}

		vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _arr(nullptr), _size(n), _capacity(n)
		{
			_arr = _alloc.allocate(n);
			for (unsigned long i = 0; i < n; i++)
				_arr[i] = val;
		}
        void push_back (const value_type& val)
        {
            if (_size == _capacity)
                resize(_capacity);
            _arr[_size] = val;
            _size++;
        }
        void    pop_back()
        {
            _alloc.destroy(&_arr[_size - 1]);
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
        void resize (size_type n, value_type val = value_type())
        {
            T *new_arr;
            if (n > this->_capacity)
            {
                _capacity *= 2;
                _capacity = _capacity == 0 ? 1 : _capacity;
                _capacity = n > _capacity ? n : _capacity;
            }
            _size = _size > n ? n : _size;
            new_arr = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
                new_arr[i] = _arr[i];
            while (_size++ < n)
                new_arr[_size] = val;
            delete[] _arr;
            _arr = new_arr;
        }
        size_type max_size() const
        {
            return (_alloc.max_size());
        }
        reference operator[] (size_type n)
        {
            return (this->_arr[n]);
        }
        const_reference operator[] (size_type n) const
        {
            return (_arr[n]);
        }
        reference at (size_type n)
        {
            if (n < 0 || n > _size)
                throw std::out_of_range("index out of bounds");
            else
                return (this->_arr[n]);
        }
        const_reference at (size_type n) const
        {
            if (n < 0 || n > _size)
                throw std::out_of_range("index out of bounds");
            else
                return (this->_arr[n]);
        }
        reference front()
        {
            return (this->_arr[0]);
        }
        const_reference front() const
        {
            return (this->_arr[0]);
        }
        reference back()
        {
            return (this->_arr[this->_size - 1]);
        }
        const_reference back() const
        {
            return (this->_arr[this->_size - 1]);
        }
    };
}

#endif