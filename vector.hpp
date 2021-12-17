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

    template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;

	private:
		iterator_type it;

	public:
		reverse_iterator() : it(nullptr){}
		explicit reverse_iterator(iterator_type it) { this->it = it; }

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : it(rev_it.base()){};

		iterator_type base() const
		{
			return (it);
		}

		reference operator*() const
		{
			iterator_type _tmp = it;
			return *--_tmp;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(base() - n);
		}

		reverse_iterator &operator++()
		{
			it--;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		}

		reverse_iterator& operator+= (difference_type n)
		{
			it -= n;
			return *this;
		}

		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(base() + n);
		}

		reverse_iterator &operator--()
		{
			++it;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}

		reverse_iterator &operator-=(difference_type n)
		{
			it += n;
			return *this;
		}

		bool operator!=(const reverse_iterator &other)
		{
			return (this->it != other.it);
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}
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
        typedef ft::MyIterator<pointer> iterator;
		typedef ft::MyIterator<const_pointer> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
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
			for (size_type i = 0; i < n; i++)
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
			if (n > _capacity)
			{
				_capacity *= 2;
				_capacity = _capacity == 0 ? 1 : _capacity;
				_capacity = n > _capacity ? n : _capacity;
			}
			_size = _size > n ? n : _size;
			new_arr = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				new_arr[i] = _arr[i];
			for (; _size < n; _size++)
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

        iterator begin()
        {
            return (iterator(&_arr[0]));
        }
        const_iterator begin() const
        {
            return (const_iterator(&_arr[0]));
        }
        iterator end()
        {
            return (iterator(&_arr[_size]));
        }
        const_iterator end() const
        {
            return(const_iterator(_arr[&_size]));
        }
        reverse_iterator rbegin()
        {
            return(reverse_iterator(iterator(&_arr[_size])));
        }
        const_reverse_iterator rbegin() const
        {
            return (const_iterator(&_arr[_size]));
        }
        reverse_iterator rend()
        {
            return (iterator(&_arr[0]));
        }
        const_reverse_iterator rend() const
        {
            return (const_iterator(&_arr[0]));
        }
		bool empty() const
		{
			if (_size == 0)
				return 1;
			return 0;
		}
		void swap (vector& x)
		{
       		allocator_type _alloc_tmp = _alloc;
       		value_type *_arr_tmp = _arr;
       		size_type _size_tmp = _size;
       		size_type _capacity_tmp = _capacity;
			
			_alloc = x._alloc;
			_arr = x._arr;
			_size = x._size;
			_capacity = x._capacity;

			x._alloc = _alloc_tmp;
			x._arr = _arr_tmp;
			x._size = _size_tmp;
			x._capacity = _capacity_tmp;
		}
		void clear()
		{
			for (size_t i = 0; i < _capacity; i++)
				_alloc.destroy(&_arr[i]);
				_size = 0;
		}
		template <class InputIterator>
		size_t	InputIteratorLen(InputIterator first, InputIterator last)
		{
			size_t i = 0;
			while (first != last)
			{
				i++;
				first++;
			}
			return i;
		}

		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last)

		{
			size_t len = 0;

			len = InputIteratorLen(first, last);
			if (len > 0)
			{
				if (len > _capacity)
					resize(len);
				_size = 0;
				while (first != last)
				{
					_arr[_size] = *first;
					_size++;
					first++;
				}
			}
		}
		
		void assign(size_type n, const value_type &val)
		{
			if (n > 0)
			{
				if (n > _capacity)
					resize(n);
				_size = 0;
				for (size_type i = 0; i < n; i++)
					_arr[_size++] = val;
			}
		}
		iterator erase(iterator position)
		{
			size_t i = 0;
			iterator it = this->begin();
			for (;it != position; it++)
				i++;
			_alloc.destroy(&_arr[i]);
			for (;i < _size - 1; i++)
			{
				value_type tmp = _arr[i];
				_arr[i] = _arr[i + 1];
			}
			_size--;
			return (it);
		}

		iterator erase(iterator first, iterator last)
		{
			iterator it;
			int i = 0;
			int n = InputIteratorLen(first, last);

			while (i != n)
			{
				erase(first);
				i++;
			}
			return it;
		}

		iterator insert(iterator position, const value_type &val)
		{
			value_type tmp;
			value_type tmp2;
			iterator it;
			iterator ite;
			size_t i = 0;
			tmp = *position;
			it = this->begin();

			for (;it != position;it++)
				i++;
			if (_size == _capacity)
				resize(_capacity);
			it = iterator(_arr + i);
			_size++;
			_arr[i++] = val;
			while (i < _size)
			{
				tmp2 = _arr[i];
				_arr[i++] = tmp;
				tmp = _arr[i];
				_arr[i++] = tmp2;
			}
			return (it);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_type i = 0;
			for (;i < n;i++)
			{
				position = insert(position, val);
				position++;
			}
		}
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			T val;
			while (first != last)
			{
				val = *first;
				position = insert(position, val);
				position++;
				first++;
			}
		}
		vector &operator=(const vector &other)
		{
			_alloc = other._alloc;
			_arr = other._arr;
			_size = other._size;
			_capacity = other._capacity;
			return (*this);
		}
		~vector(){};
    };
}
 
#endif