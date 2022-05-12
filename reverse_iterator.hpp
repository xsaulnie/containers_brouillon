#ifndef REV_ITER
#define REV_ITER
#include <iostream>
#include "utils.hpp"

namespace ft
{
template<class Iter>
class reverse_iterator
{
	protected:
		Iter current;
	public:
		typedef	Iter iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;
		typedef typename ft::iterator_traits<Iter>::reference reference;

		reverse_iterator();
		reverse_iterator(iterator_type x);
		template<class U>
		reverse_iterator(const reverse_iterator<U>& other);
		template<class U>
		reverse_iterator& operator=(const reverse_iterator<U>& other);
		iterator_type base(void) const;
		reference operator*() const;
		pointer operator->() const;
		reference operator[](difference_type n) const;
		reverse_iterator& operator++();
		reverse_iterator& operator--();
		reverse_iterator operator++(int);
		reverse_iterator operator--(int);
		reverse_iterator operator+(difference_type n) const;
		reverse_iterator operator-(difference_type n) const;
		reverse_iterator& operator+=(difference_type n);
		reverse_iterator& operator-=(difference_type n);

		//friend reverse_iterator<Iter> operator+(difference_type n, const reverse_iterator<Iter> &it);
		//template <class Iterator1, class Iterator2>
		//friend difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs); //V2
		//friend difference_type operator-(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs); //V1
};
}

template<class Iterator1, class Iterator2>
bool operator>=(const typename ft::reverse_iterator<Iterator1> &lhs, const typename ft::reverse_iterator<Iterator2> &rhs)
{
	if (lhs.base() <= rhs.base())
		return (true);
	return (false);
}

template<class Iterator1, class Iterator2>
bool operator<=(const typename ft::reverse_iterator<Iterator1> &lhs, const typename ft::reverse_iterator<Iterator2> &rhs)
{
	if (lhs.base() >= rhs.base())
		return (true);
	return (false);
}

template<class Iterator1, class Iterator2>
bool operator>(const typename ft::reverse_iterator<Iterator1> &lhs, const typename ft::reverse_iterator<Iterator2> &rhs)
{
	if (lhs.base() < rhs.base())
		return (true);
	return (false);
}

template<class Iterator1, class Iterator2>
bool operator<(const typename ft::reverse_iterator<Iterator1> &lhs, const typename ft::reverse_iterator<Iterator2> &rhs)
{
	if (lhs.base() > rhs.base())
		return (true);
	return (false);
}

template<class Iterator1, class Iterator2>
bool operator==(const typename ft::reverse_iterator<Iterator1> &lhs, const typename ft::reverse_iterator<Iterator2> &rhs)
{
	if (lhs.base() == rhs.base())
		return (true);
	return (false);
}

template<class Iterator1, class Iterator2>
bool operator!=(const typename ft::reverse_iterator<Iterator1> &lhs, const typename ft::reverse_iterator<Iterator2> &rhs)
{
	if (lhs.base() != rhs.base())
		return (true);
	return (false);
}

template<class Iter>
typename ft::reverse_iterator<Iter> operator+(typename ft::reverse_iterator<Iter>::difference_type n, const ft::reverse_iterator<Iter> &it)
{
	return (ft::reverse_iterator<Iter>(it.base() - n));
}

template<class Iterator1, class Iterator2>
typename ft::reverse_iterator<Iterator1>::difference_type operator-(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
{
	return (rhs.base() - lhs.base());
}


template<class Iter>
ft::reverse_iterator<Iter>::reverse_iterator()
{
}

template<class Iter>
ft::reverse_iterator<Iter>::reverse_iterator(typename ft::reverse_iterator<Iter>::iterator_type x)
{
	this->current = x;
}

template<class Iter>
template<class U>
ft::reverse_iterator<Iter>::reverse_iterator(const typename ft::reverse_iterator<U>& other)
{
	this->current = other.base();
}

template<class Iter>
template<class U>
typename ft::reverse_iterator<Iter> &ft::reverse_iterator<Iter>::operator=(const reverse_iterator<U> &other)
{
	this->current = other.base();
	return (*this);
}

template<class Iter>
typename ft::reverse_iterator<Iter>::iterator_type ft::reverse_iterator<Iter>::base(void) const
{
	return (this->current);
}

template<class Iter>
typename ft::reverse_iterator<Iter>::reference ft::reverse_iterator<Iter>::operator*() const
{
	Iter tmp = current;
	return (*(--tmp));
}

template<class Iter>
typename ft::reverse_iterator<Iter>::pointer ft::reverse_iterator<Iter>::operator->() const
{
	return (std::__addressof(operator*()));
}

template<class Iter>
typename ft::reverse_iterator<Iter>::reference ft::reverse_iterator<Iter>::operator[](difference_type n) const
{
	return (this->base()[-n-1]);
}

////

template<class Iter>
typename ft::reverse_iterator<Iter> &ft::reverse_iterator<Iter>::operator++()
{
	(this->current)--;
	return(*this);
}

template<class Iter>
typename ft::reverse_iterator<Iter> &ft::reverse_iterator<Iter>::operator--()
{
	(this->current)++;
	return(*this);
}

template<class Iter>
typename ft::reverse_iterator<Iter> ft::reverse_iterator<Iter>::operator--(int)
{
	reverse_iterator tmp;

	tmp = *this;
	(this->current)++;
	return (tmp);
}

template<class Iter>
typename ft::reverse_iterator<Iter> ft::reverse_iterator<Iter>::operator++(int)
{
	reverse_iterator tmp;

	tmp = *this;
	(this->current)--;
	return (tmp);
}

template<class Iter>
typename ft::reverse_iterator<Iter> ft::reverse_iterator<Iter>::operator+(difference_type n) const
{
	return (reverse_iterator(this->base() - n));
}

template<class Iter>
typename ft::reverse_iterator<Iter> ft::reverse_iterator<Iter>::operator-(difference_type n) const
{
	return (reverse_iterator(this->base() + n));
}

template<class Iter>
typename ft::reverse_iterator<Iter> &ft::reverse_iterator<Iter>::operator+=(difference_type n)
{
	(this->current) -= n;
	return (*this);
}

template<class Iter>
typename ft::reverse_iterator<Iter> &ft::reverse_iterator<Iter>::operator-=(difference_type n)
{
	(this->current) +=n ;
	return (*this);
}


#endif