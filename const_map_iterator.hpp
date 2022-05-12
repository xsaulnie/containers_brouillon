#ifndef C_MAP_ITER
#define C_MAP_ITER

#include "RBTree.hpp"
#include "pair.hpp"
#include "stdlib.h"
namespace ft {template<class T, class V, class C> class map_iterator;}
#include "map_iterator.hpp"

namespace ft
{
template<class T, class V, class C>
class const_map_iterator
{
	private:
		RBtree<T, V, C>		*cur;
		RBtree<T, V, C>		*const*rac;
		bool sentinel;

	public:

		typedef size_t difference_type;
		typedef const ft::pair<const T, V> value_type;
		typedef const ft::pair<const T, V> * pointer;
		typedef const ft::pair<const T, V> & reference;
		typedef std::bidirectional_iterator_tag iterator_category;
	 
		const_map_iterator();
		const_map_iterator(RBtree<T, V, C> *init, RBtree<T, V, C> *const*rac);
		//const_map_iterator(const const_map_iterator<T, V, C> &cpy);
		const_map_iterator(const ft::map_iterator<T, V, C> &cpy);
		const_map_iterator(RBtree<T, const V, C> *init, RBtree<T, V, C> *const*rac);
		const_map_iterator(RBtree<T, V, C> *iend, RBtree<T, V, C> *const*rac, bool sen);
		//const_map_iterator(RBtree<T, const V, C> *iend, bool sen);
		const ft::pair<const T, V> &operator*() const;
		//ft::pair<const T, const V> &operator*() const;
		const_map_iterator &operator++();
		const_map_iterator operator++(int);
		const_map_iterator &operator--();
		const_map_iterator operator--(int);
		const ft::pair<const T, V> *operator->() const;
		RBtree<T, V, C> *getcur() const;
		bool getsen() const;
		class Badoperation : public std::exception // le vrai ne segault pas
		{
			public:
				virtual const char *what() const throw()
				{
						return ("Bad operation on map iterator");
				}
		};
		bool operator==(const ft::map_iterator<T, V, C> &rhs) const;
		bool operator!=(const ft::map_iterator<T, V, C> &rhs) const;
};

template<class T, class V, class C>
bool operator==(ft::const_map_iterator<T, V, C> &lhs, ft::const_map_iterator<T, V, C> &rhs);
template<class T, class V, class C>
bool operator==(const ft::const_map_iterator<T, V, C> &lhs, const ft::const_map_iterator<T, V, C> &rhs);
template<class T, class V, class C>
bool operator!=(ft::const_map_iterator<T, V, C> &lhs, ft::const_map_iterator<T, V, C> &rhs);
template<class T, class V, class C>
bool operator!=(const ft::const_map_iterator<T, V, C> &lhs, const ft::const_map_iterator<T, V, C> &rhs);
}

template<class T, class V, class C>
RBtree<T, V, C> *ft::const_map_iterator<T, V, C>::getcur() const
{
	return (this->cur);
}

template<class T, class V, class C>
bool ft::const_map_iterator<T, V, C>::getsen() const
{
	return (this->sentinel);
}

template<class T, class V, class C>
const ft::pair<const T, V> *ft::const_map_iterator<T, V, C>::operator->() const
{
	return (std::__addressof(operator*()));
}

template<class T, class V, class C>
ft::const_map_iterator<T, V, C>::const_map_iterator(RBtree<T, V, C> *iend, RBtree<T, V, C> *const*rac, bool sen)
{
	this->rac = rac;
	if (sen == false)
	{
		this->cur = NULL;
		this->sentinel = false;
		return ;
	}
	if (sen == true)
	{
		if (iend == NULL)
		{
			this->cur = NULL;
			this->sentinel = true;
			return ; 
		}
		while(iend->parent != NULL)
			iend = iend->parent;
		while (iend->right != NULL)
			iend = iend->right;
		this->cur = iend;
		this->sentinel = true;
	}
}

/*
template<class T, class V, class C>
ft::const_map_iterator<T, V, C>::const_map_iterator(RBtree<T, const V, C> *iend, bool sen)
{
	if (sen == false)
	{
		this->cur = NULL;
		this->sentinel = false;
		return ;
	}
	if (sen == true)
	{
		if (iend == NULL)
		{
			this->cur = NULL;
			this->sentinel = true;
			return ; 
		}
		while(iend->parent != NULL)
			iend = iend->parent;
		while (iend->right != NULL)
			iend = iend->right;
		this->cur = iend;
		this->sentinel = true;
	}
}
*/

template<class T, class V, class C>
ft::const_map_iterator<T, V, C>::const_map_iterator()
{
	this->cur = NULL;
	this->sentinel = false;
	this->rac = NULL;
}

template<class T, class V, class C>
ft::const_map_iterator<T, V, C>::const_map_iterator(const typename ft::map_iterator<T, V, C> &cpy)
{
	RBtree<T, V, C> *tmp;

	this->cur = cpy.getcur();
	this->sentinel = cpy.getsen();

	tmp = this->cur;

	while (tmp->parent != NULL)
		tmp = tmp->parent;
	this->rac = &tmp;
}

template<class T, class V, class C>
ft::const_map_iterator<T, V, C>::const_map_iterator(RBtree<T, V, C> *init, RBtree<T, V, C> *const*rac)
{
	this->cur = init;
	this->sentinel = false;
	this->rac = rac;
}
/*
template<class T, class V, class C>
ft::const_map_iterator<T, V, C>::const_map_iterator(const ft::const_map_iterator<T, V, C> &cpy)
{
	this->cur = cpy.getcur();
	this->sentinel = cpy.getsen();
}
*/

template<class T, class V, class C>
ft::const_map_iterator<T, V, C>::const_map_iterator(RBtree<T, const V, C> *init, RBtree<T, V, C> *const*rac)
{
	this->cur = init;
	this->sentinel = false;
	this->rac = rac;
}


template<class T, class V, class C>
const ft::pair<const T, V> &ft::const_map_iterator<T, V, C>::operator*() const
{
	if (this->sentinel == true)
		throw (Badoperation());
	return (*(this->cur->p));
}

template<class T, class V, class C>
ft::const_map_iterator<T, V, C> &ft::const_map_iterator<T, V, C>::operator++()
{
	RBtree<T, V, C> *res;
	C comp;

	if (this->sentinel == true)
		throw (Badoperation());

	if (this->cur->right != NULL)
	{
		res = this->cur->right;
		while (res->left != NULL)
		{
			res = res->left;
		}
		this->cur = res;
		return (*this);
	}

	if (this->cur->parent == NULL)
	{
		this->sentinel = 1;
		return (*this);
	} 
	res = this->cur->parent;
	while (!comp(this->cur->p->first, res->p->first))
	{
		res = res->parent;
		if (res == NULL)
		{
			this->sentinel = 1;
			return (*this);
		}
	}
	this->cur = res;
	return (*this);
}

template<class T, class V, class C>
ft::const_map_iterator<T, V, C> ft::const_map_iterator<T, V, C>::operator++(int)
{
	RBtree<T, V, C> *res;
	const_map_iterator tmp;
	C comp;

	if (this->sentinel == true)
		throw (Badoperation());

	tmp = *this;
	if (this->cur->right != NULL)
	{
		res = this->cur->right;
		while (res->left != NULL)
			res = res->left;
		this->cur = res;
		return (tmp);
	}

	if (this->cur->parent == NULL)
	{
		this->sentinel = 1;
		return (tmp);
	} 
	res = this->cur->parent;
	while (!comp(this->cur->p->first, res->p->first))
	{
		res = res->parent;
		if (res == NULL)
		{
			this->sentinel = 1;
			return (tmp);
		}
	}
	this->cur = res;
	return (tmp);
}

template<class T, class V, class C>
ft::const_map_iterator<T, V, C> ft::const_map_iterator<T, V, C>::operator--(int)
{
	RBtree<T, V, C> *res;
	const_map_iterator tmp;
	C comp;

	tmp = *this;
	if (this->sentinel == true)
	{
		this->sentinel = false;
		return (tmp);
	}

	if (this->cur->left != NULL)
	{
		res = this->cur->left;
		while (res->right != NULL)
		{
			res = res->right;
		}
		this->cur = res;
		return (tmp);
	}

	if (this->cur->parent == NULL)
		throw (Badoperation());
	res = this->cur->parent;
	while (comp(this->cur->p->first, res->p->first))
	{
		res = res->parent;
		if (res == NULL)
		{
			throw (Badoperation());
		}
	}
	this->cur = res;
	return (tmp);
}

template<class T, class V, class C>
ft::const_map_iterator<T, V, C> &ft::const_map_iterator<T, V, C>::operator--()
{
	RBtree<T, V, C> *res;
	C comp;

	if (this->sentinel == true)
	{
		res = *rac;
		while(res->parent != NULL)
			res = res->parent;
		while (res->right != NULL)
			res = res->right;
		this->cur = res;
		this->sentinel = false;
		return (*this);
	}

	if (this->cur->left != NULL)
	{
		res = this->cur->left;
		while (res->right != NULL)
		{
			res = res->right;
		}
		this->cur = res;
		return (*this);
	}

	if (this->cur->parent == NULL)
		throw (Badoperation());
	res = this->cur->parent;
	while (comp(this->cur->p->first, res->p->first))
	{
		res = res->parent;
		if (res == NULL)
		{
			throw (Badoperation());
		}
	}
	this->cur = res;
	return (*this);
}

template<class T, class V, class C>
bool ft::operator!=(ft::const_map_iterator<T, V, C> &lhs, ft::const_map_iterator<T, V, C> &rhs)
{
		//std::cout << "comp " << lhs.getcur()->p->first << " " << rhs.getcur()->p->first << " " << lhs.getsen() << " " << rhs.getsen() << std::endl;
	if (lhs.getsen() != rhs.getsen())
		return (true);
	if (lhs.getsen() == true)
		return (false);
	if (lhs.getsen() != rhs.getsen())
		return (true);
	return (false);
}

template<class T, class V, class C>
bool ft::operator==(ft::const_map_iterator<T, V, C> &lhs, ft::const_map_iterator<T, V, C> &rhs)
{
	if (lhs.getsen() != rhs.getsen())
		return (false);
	if (lhs.getsen() == true && rhs.getsen() == true)
		return (true);
	if (lhs.getcur() == rhs.getcur())
		return (true);
	return (false);
}

template<class T, class V, class C>
bool ft::operator!=(const ft::const_map_iterator<T, V, C> &lhs, const ft::const_map_iterator<T, V, C> &rhs)
{
		//std::cout << "comp " << lhs.getcur()->p->first << " " << rhs.getcur()->p->first << " " << lhs.getsen() << " " << rhs.getsen() << std::endl;
	if (lhs.getsen() != rhs.getsen())
		return (true);
	if (lhs.getsen() == true)
		return (false);
	if (lhs.getsen() != rhs.getsen())
		return (true);
	return (false);
}

template<class T, class V, class C>
bool ft::operator==(const ft::const_map_iterator<T, V, C> &lhs, const ft::const_map_iterator<T, V, C> &rhs)
{
	if (lhs.getsen() != rhs.getsen())
		return (false);
	if (lhs.getsen() == true && rhs.getsen() == true)
		return (true);
	if (lhs.getcur() == rhs.getcur())
		return (true);
	return (false);
}

template<class T, class V, class C>
bool ft::const_map_iterator<T, V, C>::operator==(const ft::map_iterator<T, V, C> &rhs) const
{
	if (this->getsen() != rhs.getsen())
		return (false);
	if (this->getsen() == true && rhs.getsen() == true)
		return (true);
	if (this->getcur() == rhs.getcur())
		return (true);
	return (false);
}

template<class T, class V, class C>
bool ft::const_map_iterator<T, V, C>::operator!=(const ft::map_iterator<T, V, C> &rhs) const
{
	if (this->getsen() != rhs.getsen())
		return (true);
	if (this->getsen() == true)
		return (false);
	if (this->getsen() != rhs.getsen())
		return (true);
	return (false);
}

#endif