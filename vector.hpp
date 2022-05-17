#ifndef VEC_HPP
#define VEC_HPP

#include "utils.hpp"
#include "reverse_iterator.hpp"
#include <stdlib.h>


class Awesome {

	public:

		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
		Awesome( int n ) : _n( n ) { std::cout << "Int constructor" << std::endl; (void)n; }
		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
		virtual ~Awesome(void) {}

		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		void operator+=(int rhs){ _n += rhs; }
		int get( void ) const { return this->_n; }

	private:

		int _n;
};

namespace ft
{
template<class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T value_type;
		typedef typename std::allocator<value_type> allocator_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef T* iterator;
		typedef	const T* const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type  difference_type;
		//typedef typename std::ptrdiff_t difference_type;
		typedef size_t size_type; //a changer

		// Constructor
		vector();
		vector(size_type n, const value_type &val = value_type());
		template <class InputIterator>
		vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last);
		vector(const vector &x);
		~vector();

		//Capacity

		size_type size() const;
		size_type capacity() const;
		size_type max_size() const;
		void resize(size_type n, value_type val = value_type());
		bool empty() const;

		//Iterator

		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		void reserve(size_type n);

		//Element access

		reference operator[](size_type n);
		const_reference operator[](size_type n) const;
		reference at(size_type n);
		const_reference at(size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		//Modifiers
		template <class InputIterator>
		void assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last);	
		void assign(size_type n, const value_type &val);
		void push_back(const value_type &val);
		void pop_back();
		void clear();
		iterator insert(iterator position, const value_type &val);
		void insert(iterator position, size_type n, const value_type &val);
		template <class InputIterator>
		void insert(iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);
		void swap (vector &x);

		//Other 
	
		allocator_type get_allocator() const;
		vector &operator=(const vector &x);


	private:
		Allocator Alloc;
		T* tab;
		size_type len;
		size_type alen;
};
template<class T, class Allocator>
bool operator==(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs);

template<class T, class Allocator>
bool operator!=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs);

template<class T, class Allocator>
bool operator<(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs);

template<class T, class Allocator>
bool operator>(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs);

template<class T, class Allocator>
bool operator<=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs);

template<class T, class Allocator>
bool operator>=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs);
}

namespace ft
{
template<class T, class Allocator>
bool operator==(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0 ; i < lhs.size() ; i++)
	{
		if (lhs[i] != rhs[i])
			return (false);
	}
	return (true);
}
template<class T, class Allocator>
bool operator!=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	if (lhs.size() != rhs.size())
		return (true);
	for (size_t i = 0 ; i < lhs.size() ; i++)
	{
		if (lhs[i] != rhs[i])
			return (true); 
	}
	return (false);
}

template<class T, class Allocator>
bool operator<(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<class T, class Allocator>
bool operator>(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	if (lhs == rhs)
		return (false);
	return (!(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())));
}

template<class T, class Allocator>
bool operator>=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	if (lhs == rhs)
		return (true);
	return (!(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())));
}

template<class T, class Allocator>
bool operator<=(const ft::vector<T, Allocator> &lhs, const ft::vector<T, Allocator> &rhs)
{
	if (lhs == rhs)
		return (true);
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

}

template<class T, class Allocator>
ft::vector<T, Allocator> &ft::vector<T, Allocator>::operator=(const ft::vector<T, Allocator> &x)
{
	size_t lenx;
	size_t len;
	size_t new_alen;
	T* res;

	lenx = x.size();
	len = this->len;
	if (lenx <= this->alen)
		new_alen = this->alen;
	else
		new_alen = lenx;
	this->Alloc = x.get_allocator();
	res = (this->Alloc).allocate(new_alen);
	for (size_t i = 0 ; i < lenx ; i++)
		(this->Alloc).construct(res + i, x.at(i));
	for (size_t i = 0 ; i < len ; i++)
		(this->Alloc).destroy(this->tab + i);
	(this->Alloc).deallocate(this->tab, this->alen);
	this->tab = res;
	this->alen = new_alen;
	this->len = lenx;
	return (*this);
}

template<class T, class Allocator>
ft::vector<T, Allocator>::vector()
{
	Allocator(this->Alloc);
	this->tab = NULL;
	this->alen = 0;
	this->len = 0;
	//std::cout <<"constructor 1" << std::endl;
}

template<class T, class Allocator>
ft::vector<T, Allocator>::vector(size_type n, const value_type &val)
{
	Allocator(this->Alloc);
	this->tab = (this->Alloc).allocate(n);
	for (size_t i = 0 ; i < n ; i++)
	{
		(this->Alloc).construct(this->tab + i, val);
	}
	this->alen = n;
	this->len = n;
	//std::cout <<"constructor 2" << std::endl;
}

template<class T, class Allocator>
template<class InputIterator>
ft::vector<T, Allocator>::vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
{
	size_t dist;
	size_t i;
	InputIterator save;

	save = first;
	dist = 0;
	i = 0;
	while (first != last)
	{
		first++;
		dist++;
	}
	first = save;
	Allocator(this->Alloc);
	this->tab = (this->Alloc).allocate(dist);
	while (first != last)
	{
		(this->Alloc).construct(this->tab + i, *first);
		first++;
		i++;
	}
	this->alen = dist;
	this->len = dist;
	//std::cout <<"constructor 3" << std::endl;
}

template<class T, class Allocator>
ft::vector<T, Allocator>::vector(const vector &x)
{
	this->Alloc = x.get_allocator();
	if (x.size() == 0)
	{
		this->tab = NULL;
		this->alen = 0;
		this->len = 0;
		return ;
	}

	this->tab = (this->Alloc).allocate(x.size());
	for (size_t i = 0 ; i < x.size() ; i++)
	{
		(this->Alloc).construct(this->tab + i, x[i]);
	}
	this->alen = x.size();
	this->len = x.size();
	//std::cout <<"constructor 4" << std::endl;
}

namespace ft
{
template<class T, class Allocator>
void swap(ft::vector<T, Allocator> &x, ft::vector<T, Allocator> &y)
{
	x.swap(y);
	return ;
}
}


template<class T, class Allocator>
typename ft::vector<T, Allocator>::allocator_type ft::vector<T, Allocator>::get_allocator() const
{
	return (this->Alloc);
}

template<class T, class Allocator>
void ft::vector<T, Allocator>::swap(typename ft::vector<T, Allocator> &x)
{
		Allocator temp_Alloc;
		T* temp_tab;
		size_t temp_len;
		size_t temp_alen;

		temp_Alloc = this->Alloc;
		temp_tab = this->tab;
		temp_len = this->len;
		temp_alen = this->alen;

		this->Alloc = x.Alloc;
		this->tab = x.tab;
		this->len = x.len;
		this->alen = x.alen;

		x.Alloc = temp_Alloc;
		x.tab = temp_tab;
		x.len = temp_len;
		x.alen = temp_alen; 
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::erase(iterator first, iterator last)
{
	size_t j;
	size_t dist;
	T* save;

	save = first;

	dist = 0;
	while (first != last)
	{
		first++;
		dist++;
	}
	first = save;
	j = 0;
	for (size_t i = 0 ; i < this->len ; i++)
	{
		if (first == this->tab + i)
		{
			while (first != last)
			{
				this->Alloc.destroy(this->tab + i + j);
				first++;
				j++;
			}
			for (size_t k = i ; k < this->len - dist ; k++)
			{
				(this->Alloc).construct(this->tab + k, *(this->tab + k + dist));
				(this->Alloc).destroy(this->tab + k + dist);
			}
			this->len = this->len - dist;
			return (this->tab + i);
		}
	}
	return (last);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::erase(typename ft::vector<T, Allocator>::iterator position)
{
	for (size_t i = 0 ; i < this->len ; i++)
	{
		if (position == this->tab + i)
		{
			(this->Alloc).destroy(this->tab + i);
			for (size_t j = i ; j < this->len - 1 ; j++)
			{
				(this->Alloc).construct(this->tab + j, *(this->tab + j + 1));
				(this->Alloc).destroy(this->tab + j + 1);
			}
			(this->len)--;
			return (this->tab + i);
		}
	}
	return (position);
}

template<class T, class Allocator>
template<class InputIterator>
void ft::vector<T, Allocator>::insert(typename ft::vector<T, Allocator>::iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
{
	size_t dist;
	T* new_tab;
	InputIterator save;
	size_t add;
	size_t new_size;

	dist = 0;
	add = 0;
	save = first;
	while (first != last)
	{
		first++;
		dist++;
	}
	first = save;
	if (dist == 0)
		return ;

	if (this->len == 0)
	{
		if (position == this->begin() || position == this->end())
		{
			this->reserve(dist);
			for (size_t i = 0 ; i < dist ; i++)
			{
				this->push_back(*first);
				first++;
			}
		}
		return ;
	}
	//std::cout << dist << std::endl;
	add = 0;
	if (this->len + dist > this->alen)
	{
		if (this->len * 2 >= this->len + dist)
			new_size = this->len * 2;
		else
			new_size = this->len + dist;
		/*
		while (new_size < this->len + dist)
		{
			new_size *= 2;
		}
		*/
		new_tab = (this->Alloc).allocate(new_size);
		for (size_t i = 0 ; i < this->len + dist ; i++)
		{
			//std::cout << this->tab + i << " " << first << std::endl;
			if (add == 0 && this->tab + i == position)
			{
				for (size_t j = 0 ; j < dist ; j++)
				{
					(this->Alloc).construct(new_tab + i + j, *first);
					first++;
				}
				add = dist;
				i += dist - 1;
			}
			else
			{
				(this->Alloc).construct(new_tab + i, (this->tab)[i - add]);
			}
		}
		add = this->len + dist;
		this->clear();
		(this->Alloc).deallocate(this->tab, this->alen);
		this->tab = new_tab;
		this->alen = new_size;
		this->len = add;
		return ;
	}
	T temp_val; //construction par defaut
	ft::vector<T, Allocator> temp;

	for (size_t i = 0 ; i < this->len + dist ; i++)
	{
		if (this->tab + i == position)
		{
			for (size_t j = 0 ; j < dist ; j++)
			{
				if (i + j < this->len)
				{
					temp.push_back((this->tab)[i + j]);
					(this->Alloc).destroy(this->tab + i + j);
				}
				(this->Alloc).construct(this->tab + i + j, *first);
				first++;
			}
			for (size_t j = this->len - 1 ; j > i + dist - 1 ; j--)
			{
				temp_val = (this->tab)[j];
				if (j < this->len)
					(this->Alloc).destroy(this->tab + j);
				(this->Alloc).construct(this->tab + j + dist, temp_val);
			}
			for (size_t k = 0 ; k < temp.size() ; k++)
				(this->Alloc).construct(this->tab + i + k + dist, temp.at(k));
			this->len = this->len + dist;
			return ;
		}
	}
}

template<class T, class Allocator>
void ft::vector<T, Allocator>::insert(ft::vector<T, Allocator>::iterator position, ft::vector<T, Allocator>::size_type n, const ft::vector<T, Allocator>::value_type &val)
{
	T* new_tab;
	size_t add;
	size_t new_size;

	if (n == 0)
		return ;
	if (this->len == 0)
	{
		if (position == this->begin() || position == this->end())
		{
			this->reserve(n);
			for (size_t i = 0 ; i < n ; i++)
				this->push_back(val);
		}
		return ;
	}
	add = 0;
	if (this->len + n > this->alen) //removed =
	{
		if (this->len * 2 >= this->len + n)
			new_size = this->len * 2;
		else
			new_size = this->len + n;
		/*
		new_size = this->alen;
		while (new_size < this->len + n)
		{
			new_size *= 2;
		}
		*/
		new_tab = (this->Alloc).allocate(new_size);
		for (size_t i = 0 ; i < this->len + n; i++)
		{
			if (add == 0 && this->tab + i == position)
			{
				for (size_t j = 0 ; j < n ; j++)
				{
					(this->Alloc).construct(new_tab + i + j, val);
				}
				add = n;
				i += n - 1;
			}
			else
			{
				(this->Alloc).construct(new_tab + i, (this->tab)[i - add]);
			}
		}
		add = this->len + n;
		this->clear();
		(this->Alloc).deallocate(this->tab, this->alen);
		this->tab = new_tab;
		this->alen = new_size;
		this->len = add;
		return ;
	}

	for (size_t i = this->len + n - 1 ; this->tab + i != position + n; i--)
	{
		(this->Alloc).construct(this->tab + i, this->tab[i - n]);
		(this->Alloc).destroy(this->tab + i - n);
	}
	for (size_t i = 0 ; i < n ; i++)
	{
		//(this->Alloc).destroy(i);
		(this->Alloc).construct(position + i, val);
	}
	return ;
	/*
	T temp_val; // construction par defaut

	ft::vector<T, Allocator> temp;
	for (size_t i = 0 ; i < this->len + n ; i++)
	{
		if (this->tab + i == position)
		{
			for (size_t j = 0 ; j < n ; j++)
			{
				if (i + j < this->len)
				{
					temp.push_back((this->tab)[i + j]);
					(this->Alloc).destroy(this->tab + i + j);
				}
				(this->Alloc).construct(this->tab + i + j, val);
			}
			for (size_t  j = this->len - 1 ; j > i + n - 1 ; j--)
			{
				temp_val = (this->tab)[j];
				if (j < this->len)
					(this->Alloc).destroy(this->tab + j);
				(this->Alloc).construct(this->tab + j + n, temp_val);
			}
			for (size_t k = 0 ; k < temp.size() ; k++)
				(this->Alloc).construct(this->tab + i + k + n, temp.at(k));
			this->len = this->len + n;
			return ;
		}
	}
	*/
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::insert(typename ft::vector<T, Allocator>::iterator position, const typename ft::vector<T, Allocator>::value_type &val)
{
	T* new_tab;
	ft::vector<T, Allocator>::iterator ret;

	if (this->len == 0)
	{
		if (position == this->begin() || position == this->end())
			this->push_back(val);
		return (this->tab);
	}

	if (this->len == this->alen)
	{
		new_tab = (this->Alloc).allocate(2 * this->alen);
		size_t i = 0;

		while (this->tab + i != position)
		{
			(this->Alloc).construct(new_tab + i, (this->tab)[i]);
			i++;
		}
		(this->Alloc).construct(new_tab + i, val);
		ret = new_tab + i;
		i++;
		while (i < this->len + 1)
		{
			this->Alloc.construct(new_tab + i, (this->tab)[i - 1]);
			i++;
		}
		i = this->len + 1;
		this->clear();
		(this->Alloc).deallocate(this->tab, this->alen);
		this->tab = new_tab;
		this->alen = 2 * this->alen;
		this->len = i;
		return (ret);
	}

	for (size_t i = this->len ; this->tab + i != position ; i--)
	{
		(this->Alloc).construct(this->tab + i, this->tab[i - 1]);
		(this->Alloc).destroy(this->tab + i - 1);
	}
	(this->Alloc).construct(position, val);
	return (position);

	/*
	T temp0; // construction par defaut
	T temp1; // construction par defaut


	for (size_t i = 0 ; i < this->len + 1 ; i++)
	{
		if (this->tab + i == position)
		{
			temp0 = (this->tab)[i];
			(this->Alloc).destroy(this->tab + i);
			(this->Alloc).construct(this->tab + i, val);
			for (size_t j = i + 1 ; j < this->len + 1 ; j++)
			{
				temp1 = (this->tab)[j];
				if (j < this->len)
					(this->Alloc).destroy(this->tab + j);
				(this->Alloc).construct(this->tab + j, temp0);
				temp0 = temp1;
			}
			this->len++;
			return (this->tab + i);
		}
	}
	*/
	return (NULL);
}

template<class T, class Allocator>
void ft::vector<T, Allocator>::clear()
{
	size_t i;

	i = 0;
	while (i < this->len)
	{
		(this->Alloc).destroy(this->tab + i);
		i++;
	}
	this->len = 0;
}

template<class T, class Allocator>
void ft::vector<T, Allocator>::assign(size_type n, const value_type &val)
{
	T* new_tab;

	if (n > this->alen)
	{
		new_tab = (this->Alloc).allocate(n);
		for (size_t i = 0 ; i < n ; i++)
			(this->Alloc).construct(new_tab + i, val);
		for (size_t i = 0 ; i < this->len ; i++)
			(this->Alloc).destroy(this->tab + i);
		if (this->tab !=NULL)
			(this->Alloc).deallocate(this->tab, this->alen);
		this->tab = new_tab;
		this->len = n;
		this->alen = n;
		return ;
	}
	this->clear();
	for (size_t i = 0 ; i < n ; i++)
	{
		(this->Alloc).construct(this->tab + i, val);
	}
	this->len = n;
}

template<class T, class Allocator>
template<class InputIterator>
void ft::vector<T, Allocator>::assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
{
	T* new_tab;
	size_t dist;
	InputIterator save;

	save = first;
	dist = 0;
	while (first != last)
	{
		dist++;
		first++;
	}
	first = save;

	if (dist > this->alen)
	{
		new_tab = (this->Alloc).allocate(dist);
		for (size_t i = 0 ; i < dist ; i++)
		{
			(this->Alloc).construct(new_tab + i, *first);
			first++;
		}
		for (size_t i = 0 ; i < this->len ; i++)
			(this->Alloc).destroy(this->tab + i);
		if (this->tab != NULL)
			(this->Alloc).deallocate(this->tab, this->alen);
		this->tab = new_tab;
		this->len = dist;
		this->alen = dist;
		return ;
	}
	this->clear();
	for (size_t i = 0 ; i < dist ; i++)
	{
		(this->Alloc).construct(this->tab + i, *first);
		first++;
	}
	this->len = dist;
}

template<class T, class Allocator>
void ft::vector<T, Allocator>::pop_back()
{
	if (this->len != 0)
	{
		(this->Alloc).destroy(this->tab + this->len - 1);
		(this->len)--;
	}
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::back()
{
	//return(*std::prev(this->end()));
	return (*(this->tab + this->len - 1));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::back() const
{
	//return(*std::prev(this->end()));
	return (*(this->tab + this->len - 1));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::front()
{
	return (*(this->tab));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::front() const
{
	return (*(this->tab));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::at(typename ft::vector<T, Allocator>::size_type n)
{
	if (n >= this->len)
	{
		throw (std::out_of_range("Invalid index"));
	}
	return ((this->tab)[n]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::at(typename ft::vector<T, Allocator>::size_type n) const
{
	if (n >= this->len)
	{
		throw (std::out_of_range("Invalid index"));
	}
	return ((this->tab)[n]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reference ft::vector<T, Allocator>::operator[](typename ft::vector<T, Allocator>::size_type n)
{
	return ((this->tab)[n]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference ft::vector<T, Allocator>::operator[](typename ft::vector<T, Allocator>::size_type n) const
{
	return ((this->tab)[n]);
}

template<class T, class Allocator>
void ft::vector<T, Allocator>::reserve(typename ft::vector<T, Allocator>::size_type n)
{
	T* new_tab;
 
	if (n > this->max_size())
	{
		throw (std::length_error("vector::reserve"));
	}
	if (n > this->alen)
	{
		new_tab = (this->Alloc).allocate(n);
		for (size_t i = 0 ; i < this->len ; i++)
			(this->Alloc).construct(new_tab + i, (this->tab)[i]);
		for (size_t i = 0 ; i < this->len ; i++)
			(this->Alloc).destroy(this->tab + i);
		(this->Alloc).deallocate(this->tab, this->alen);
		this->tab = new_tab;
		this->alen = n;
	}
}

template<class T, class Allocator>
bool ft::vector<T, Allocator>::empty() const
{
	if (this->len == 0)
		return (true);
	return (false); 
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator ft::vector<T, Allocator>::rbegin()
{
	return (ft::reverse_iterator<typename ft::vector<T, Allocator>::iterator>(this->end()));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator ft::vector<T, Allocator>::rbegin() const
{
	return (ft::reverse_iterator<typename ft::vector<T, Allocator>::const_iterator>(this->end()));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator ft::vector<T, Allocator>::rend()
{
	return (ft::reverse_iterator<typename ft::vector<T, Allocator>::iterator>(this->begin()));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator ft::vector<T, Allocator>::rend() const
{
	return (ft::reverse_iterator<typename ft::vector<T, Allocator>::const_iterator>(this->begin()));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::end()
{
	return (this->tab + this->len);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator ft::vector<T, Allocator>::end() const
{
	return (this->tab + this->len);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator ft::vector<T, Allocator>::begin()
{
	return (this->tab);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator ft::vector<T, Allocator>::begin() const
{
	return (this->tab);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::size() const
{
	return (this->len);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::capacity() const
{
	return (this->alen);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::size_type ft::vector<T, Allocator>::max_size() const
{
	size_t res;

		unsigned long long int p;
	size_t n;

	n = 63;
	p = 1;

	while (n)
	{
		p *=2;
		n--;
	}

	res = (p / (sizeof(T))) - 1;
	return (res);
}

template<class T, class Allocator>
ft::vector<T, Allocator>::~vector()
{
	for (size_t i = 0 ; i < (this->len) ; i++)
	{
		(this->Alloc).destroy(this->tab + i);
	}
	(this->Alloc).deallocate(this->tab, this->alen); //len or alen ?
}

template<class T, class Allocator>
void ft::vector<T, Allocator>::resize(ft::vector<T, Allocator>::size_type n, ft::vector<T, Allocator>::value_type val)
{
	T *new_tab;
	size_t new_alen;

	if (n == this->len)
		return ;
	if (n < this->len)
	{
		for (unsigned long i = this->len - 1 ; i != n - 1 ; i--)
		this->Alloc.destroy(this->tab + i);
		this->len = n;
		return ;
	}
	if (n > this->len && n <= this->alen)
	{
		for (size_t i = this->len ; i < n ; i++)
			this->Alloc.construct(this->tab + i, val);
		this->len = n;
		return ;
	}
	if (n > this->alen)
	{
		if (this->len * 2 >= n)
			new_alen = this->len * 2;
		else
			new_alen = n;
		new_tab = (this->Alloc).allocate(new_alen);
		for (size_t i = 0 ; i < this->len ; i++)
			(this->Alloc).construct(new_tab + i, (this->tab)[i]);
		for (size_t i = this->len ; i < n ; i++)
			(this->Alloc).construct(new_tab + i, val);
		for (size_t i = 0 ; i < this->len ; i++) //len or alen, idk
			this->Alloc.destroy(this->tab + i);
		(this->Alloc).deallocate(this->tab, this->alen);
		this->tab = new_tab;
		this->alen = new_alen;
		this->len = n;
		return ;
	}
}

template<class T, class Allocator>
void ft::vector<T, Allocator>::push_back(const value_type &val)
{
	size_t tmp;

	//std::cout << "strange "<< this->tab<< " and " << this->size() << std::endl;
	if (this->len == 0 && this->alen == 0)
	{
		//std::cout << "lol" << std::endl;
		if (this->tab != NULL)
			(this->Alloc).deallocate(this->tab, this->alen);
		this->tab = (this->Alloc).allocate(1);
		(this->Alloc).construct(this->tab, val);
		this->len = 1;
		this->alen = 1;
		return ;
	}

	if (this->len == this->alen)
	{
		tmp = this->len;
		this->reserve(2 * this->len);
		this->len = tmp;
	}
	this->Alloc.construct(this->tab + this->len, val);
	(this->len)++;
	return ;
}
/*
template<class T, class Allocator>
ft::vector<T, Allocator>::vector(const vector &x)
{
}
*/

#endif