#ifndef REVERSE_ITERATOR
#define REVERSE_ITERATOR

namespace ft
{
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
}

#endif