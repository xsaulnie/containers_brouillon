#ifndef MAP_HPP
#define MAP_HPP
#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "RBTree.hpp"
#include "map_iterator.hpp"
#include "const_map_iterator.hpp"


namespace ft
{
template <class Key,  class T, class Compare = std::less<Key> >
class map
{
	public:

		class value_compare;
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair <const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef std::allocator<value_type> allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename ft::map_iterator<Key, T, Compare> iterator;
		typedef typename ft::const_map_iterator<Key, T, Compare> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef size_t size_type;
		typedef typename ft::iterator_traits<iterator>::difference_type difference_type;

		//Constructor

		map();
		map(const Compare &comp);
		template<class InputIt>
		map(InputIt first, InputIt last, const Compare &comp = Compare());
		map(const map &other);
		~map();
		map& operator=(const map &x);

		//Insert
		ft::pair<iterator, bool> insert(const value_type &value);
		iterator insert(iterator hint, const value_type& value);
		template <class InputIt>
		void insert(InputIt first, InputIt last);

		//clear
		void clear();

		//erase
		void erase(iterator position);
		size_type erase(const key_type &k);
		void erase(iterator first, iterator last);

		//swap
		void swap(map &x);

		//Iterator
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		//Capacity
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		//Element Access
		mapped_type& operator[](const key_type &k);

		//Observer
		key_compare key_comp() const;
		value_compare value_comp() const;

		//Operation
		iterator find(const key_type &k);
		const_iterator find(const key_type &k) const;
		size_type count (const key_type &k) const;
		iterator lower_bound (const key_type &k);
		const_iterator lower_bound(const key_type &k) const;
		iterator upper_bound(const key_type &k);
		const_iterator upper_bound(const key_type &k) const;
		pair<iterator, iterator> equal_range(const key_type &k);
		pair<const_iterator, const_iterator> equal_range(const key_type &k) const;

		//Allocator
		allocator_type get_allocator() const;


	void disp_map(const map<Key, T, Compare> &m);

	private:
		RBtree<Key, T, Compare> *tree;
		//RBtree<Key, T, Compare> *rac;
		key_compare comp;
		size_t nb;
		allocator_type Alloc;
};

template<class Key, class T, class Compare>
void swap(ft::map<Key, T, Compare> &lhs, ft::map<Key, T, Compare> &rhs);
template<class Key, class T, class Compare>
bool operator==(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs);
template<class Key, class T, class Compare>
bool operator!=(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs);
template<class Key, class T, class Compare>
bool operator<(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs);
template<class Key, class T, class Compare>
bool operator>(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs);
template<class Key, class T, class Compare>
bool operator>=(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs);
template<class Key, class T, class Compare>
bool operator<=(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs);
}

template<class Key, class T, class Compare>
void ft::map<Key, T, Compare>::disp_map(const ft::map<Key, T, Compare> &m)
{
	RBtree<Key, T, Compare> *rac;

	rac = m.tree;
	while (rac->getpar(rac) != NULL)
		rac = rac->getpar(rac);
	std::cout << "----------------------";
	display_tree(rac, 0);
	std::cout << "----------------------" << std::endl;
}

//Constructor

template<class Key, class T, class Compare>
ft::map<Key, T, Compare>::map()
{
	this->tree = NULL;
	this->nb = 0;
}

template<class Key, class T, class Compare>
ft::map<Key, T, Compare>::map(const Compare &comp)
{
	this->tree = NULL;
	this->nb = 0;
	this->cmp = comp;
}

template<class Key, class T, class Compare>
template<class InputIt>
ft::map<Key, T, Compare>::map(InputIt first, InputIt last, const Compare &comp)
{
	size_t cmp;

	this->tree = NULL;
	this->nb = 0;
	cmp = 0;
	while (first != last)
	{
		//std::cout << "copy " << first->second << std::endl;
		this->insert(*first);
		first++;
//		cmp++;
	}
//	this->nb = cmp;
	this->comp = comp;
}

template<class Key, class T, class Compare>
ft::map<Key, T, Compare>::map(const map &other)
{
	size_t cmp;
	ft::map<Key, T, Compare>::const_iterator st = other.begin();
	ft::map<Key, T, Compare>::const_iterator en = other.end();
	ft::pair<Key, T> tmp;

	cmp = 0;
	this->tree = NULL;
	while (st != en)
	{
		tmp = *st;
		this->insert(tmp);
		st++;
		cmp++;
	}
	this->nb = cmp;
	this->comp = other.key_comp();
	this->Alloc = other.get_allocator();
}

template<class Key, class T, class Compare>
ft::map<Key, T, Compare>::~map()
{
	this->clear();
}

template<class Key, class T, class Compare>
ft::map<Key, T, Compare> &ft::map<Key, T, Compare>::operator=(const ft::map<Key, T, Compare> &x)
{
	this->clear();
	ft::map<Key, T, Compare>::const_iterator fs = x.begin();
	ft::map<Key, T, Compare>::const_iterator ls = x.end();


	if (fs == ls)
	{
		this->tree = NULL;
		this->nb = 0;
	}

	while (fs != ls)
	{
		//ft::pair<const Key, T> tmp(fs->first, fs->second);
		this->insert(*fs);
		fs++;
	}
	this->nb = x.size();
	this->Alloc = x.get_allocator();
	this->comp = x.key_comp();
	return (*this);
}

//Iterator

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::iterator ft::map<Key, T, Compare>::begin()
{
	RBtree<Key, T, Compare> *cur;

	cur = this->tree;

	if (this->tree == NULL)
	{
		return(iterator(cur, &(this->tree), true));
	}
	cur = cur->getrac(cur);
	while (cur->left != NULL)
		cur = cur->left;
	return (iterator(cur, &(this->tree)));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::const_iterator ft::map<Key, T, Compare>::begin() const
{
	RBtree<Key, T, Compare> *cur;

	cur = this->tree;

	if (this->tree == NULL)
	{
		return(const_iterator(cur, &(this->tree), true));
	}
	cur = cur->getrac(cur);
	while (cur->left != NULL)
		cur = cur->left;
	return (const_iterator(cur, &(this->tree)));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::iterator ft::map<Key, T, Compare>::end()
{
	return(iterator(this->tree, &(this->tree), true));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::const_iterator ft::map<Key, T, Compare>::end() const
{

	RBtree<Key, T, Compare> *const*tmp = &(this->tree);
	return(const_iterator(this->tree, tmp, true));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::reverse_iterator ft::map<Key, T, Compare>::rbegin()
{
	return (ft::reverse_iterator<typename ft::map<Key, T, Compare>::iterator>(this->end()));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::const_reverse_iterator ft::map<Key, T, Compare>::rbegin() const
{
	return (ft::reverse_iterator<typename ft::map<Key, T, Compare>::const_iterator>(this->end()));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::reverse_iterator ft::map<Key, T, Compare>::rend()
{
	return (ft::reverse_iterator<typename ft::map<Key, T, Compare>::iterator>(this->begin()));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::const_reverse_iterator ft::map<Key, T, Compare>::rend() const
{
	return (ft::reverse_iterator<typename ft::map<Key, T, Compare>::const_iterator>(this->begin()));
}

// insert

template<class Key, class T, class Compare>
typename ft::pair<typename ft::map<Key, T, Compare>::iterator, bool> ft::map<Key, T, Compare>::insert(const ft::map<Key, T, Compare>::value_type &value)
{

	RBtree <Key, T, Compare> *test = this->tree->search(this->tree, value.first, this->comp);
	if (test != NULL)
		return (ft::pair<typename ft::map<Key, T, Compare>::iterator, bool>(iterator(test, &(this->tree)), false));
	RBtree <Key, T, Compare> *n = this->tree->RBpair(value.first, value.second, this->Alloc);
	this->tree = this->tree->insert(this->tree, n, this->comp);
	this->nb++;

	RBtree <Key, T, Compare> *ret = this->tree->search(this->tree, value.first, this->comp);
	return (ft::pair<typename ft::map<Key, T, Compare>::iterator, bool>(iterator(ret, &(this->tree)), true));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::iterator ft::map<Key, T, Compare>::insert(typename ft::map<Key, T, Compare>::iterator hint, const value_type& value)
{
	(void)hint;
	RBtree <Key, T, Compare> *test = this->tree->search(this->tree, value.first, this->comp);
	if (test != NULL)
		return (iterator(this->tree, &(this->tree), true));
	RBtree <Key, T, Compare> *n = this->tree->RBpair(value.first, value.second, this->Alloc);
	this->tree = this->tree->insert(this->tree, n, this->comp);
	this->nb++;

	RBtree <Key, T, Compare> *ret = this->tree->search(this->tree, value.first, this->comp);
	return (iterator(ret, &(this->tree)));
}

template<class Key, class T, class Compare>
template <class InputIt>
void ft::map<Key, T, Compare>::insert(InputIt first, InputIt last)
{

	while (first != last)
	{
		this->insert(*first);
		first++;
	}
}

//Clear

template<class Key, class T, class Compare>
void ft::map<Key, T, Compare>::clear()
{
	if (this->tree == NULL)
		return ;
	this->tree->clear(this->tree, this->Alloc);
	this->nb = 0;
	this->tree = NULL;	
}

// Erase

template<class Key, class T, class Compare>
void ft::map<Key, T, Compare>::erase(ft::map<Key, T, Compare>::iterator position)
{
	bool erased;

	if (this->nb == 0)
		return ;
	if (position.getsen())
		return ;
	this->tree = this->tree->vanish(this->tree, position->first, erased, this->comp, this->Alloc);
	if (erased)
		this->nb--;
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::size_type ft::map<Key, T, Compare>::erase(const ft::map<Key, T, Compare>::key_type &k)
{
	bool erased;

	if (this->nb == 0)
		return (0);
	this->tree = this->tree->vanish(this->tree, k, erased, this->comp, this->Alloc);
	if (erased)
	{
		this->nb--;
		return (1);
	}
	return (0);
}

template<class Key, class T, class Compare>
void ft::map<Key, T, Compare>::erase(ft::map<Key, T, Compare>::iterator first, ft::map<Key, T, Compare>::iterator last)
{
	ft::map<Key, T, Compare> cpy;
	bool erased;

	cpy = *this;

	while (first != last)
	{
		if(!first.getsen())
		{
			cpy.tree = cpy.tree->vanish(cpy.tree, first->first, erased, cpy.comp, cpy.Alloc);
			if (erased)
				cpy.nb--;
		}
		first++;
	}
	*this = cpy;
	cpy.clear();
}

// Swap
template<class Key, class T, class Compare>
void ft::map<Key, T, Compare>::swap(ft::map<Key, T, Compare> &x)
{
	RBtree<Key, T, Compare> *tree_tmp;
	key_compare comp_tmp;
	size_t nb_tmp;
	allocator_type Alloc_tmp;

	tree_tmp = this->tree;
	comp_tmp = this->comp;
	nb_tmp = this->nb;
	Alloc_tmp = this->Alloc;

	this->tree = x.tree;
	this->comp = x.key_comp();
	this->nb = x.size();
	this->Alloc = x.get_allocator();

	x.tree = tree_tmp;
	x.comp = comp_tmp;
	x.nb = nb_tmp;
	x.Alloc = Alloc_tmp;
}

template<class Key, class T, class Compare>
void ft::swap(ft::map<Key, T, Compare> &lhs, ft::map<Key, T, Compare> &rhs)
{
	lhs.swap(rhs);
}

// Capacity

template<class Key, class T, class Compare>
bool ft::map<Key, T, Compare>::empty() const
{
	if (this->nb == 0)
		return (true);
	return (false);
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::size_type ft::map<Key, T, Compare>::size() const
{
	return(this->nb);
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::size_type ft::map<Key, T, Compare>::max_size() const
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

	res = ((p / (sizeof(typename ft::map<Key, T, Compare>::value_type))) - 1);
	return (res);
}

//Access
template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::mapped_type& ft::map<Key, T, Compare>::operator[](const typename ft::map<Key, T, Compare>::key_type &k)
{
	RBtree<Key, T, Compare> *test;

	test = this->tree->search(this->tree, k, this->comp);

	if (test != NULL)
		return (test->p->second);
	return	((this->insert(ft::pair<Key, T>(k, mapped_type())).first)->second);
}

//Observer

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::key_compare ft::map<Key, T, Compare>::key_comp() const
{
	return (this->comp);	
}
template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::value_compare ft::map<Key, T, Compare>::value_comp() const
{
	return (value_compare());
}

template<class Key, class T, class Compare>
class ft::map<Key, T, Compare>::value_compare
{
	friend class map;
protected:
	Compare comp;
	value_compare(Compare c) : comp(c) {}
	value_compare() {}
public:
	typedef bool result_type;
	typedef value_type first_argument_type;
	typedef value_type second_argument_type;
	bool operator() (const value_type &x, const value_type &y) const
	{
		return comp(x.first, y.first);
	}
};

//Operation

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::iterator ft::map<Key, T, Compare>::find(const typename ft::map<Key, T, Compare>::key_type &k)
{
	RBtree<Key, T, Compare> *test = this->tree->search(this->tree, k, this->comp);

	if (test == NULL)
		return (iterator(this->tree, &(this->tree),true));
	return (iterator(test, &(this->tree)));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::const_iterator ft::map<Key, T, Compare>::find(const typename ft::map<Key, T, Compare>::key_type &k) const
{
	//const Compare c_comp;
	RBtree<Key, T, Compare> *test = this->tree->search(this->tree, k, this->comp);

	if (test == NULL)
		return (const_iterator(this->tree, &(this->tree), true));
	return (const_iterator(test, &(this->tree)));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::size_type ft::map<Key, T, Compare>::count(const typename ft::map<Key, T, Compare>::key_type &k) const
{
	RBtree<Key, T, Compare> *test = this->tree->search(this->tree, k, this->comp);

	if (test == NULL)
		return (0);
	return (1);
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::iterator ft::map<Key, T, Compare>::lower_bound(const typename ft::map<Key, T, Compare>::key_type &k)
{
	typename ft::map<Key, T, Compare>::iterator it;
	typename ft::map<Key, T, Compare>::iterator end;
	typename ft::map<Key, T, Compare>::iterator found;

	end = this->end();
	found = this->find(k);
	if (found != end)
		return (found);

	it = this->begin();
	while (it != end)
	{
		if (key_comp()(it->first, k) == false)
			return (it);
		it++;
	}
	return (iterator(this->tree, &(this->tree), true));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::const_iterator ft::map<Key, T, Compare>::lower_bound(const typename ft::map<Key, T, Compare>::key_type &k) const
{
	typename ft::map<Key, T, Compare>::const_iterator it;
	typename ft::map<Key, T, Compare>::const_iterator end;
	typename ft::map<Key, T, Compare>::const_iterator found;

	end = this->end();
	found = this->find(k);
	if (found != end)
		return (found);

	it = this->begin();
	while (it != end)
	{
		if (key_comp()(it->first, k) == false)
			return (it);
		it++;
	}
	return (const_iterator(this->tree, &(this->tree), true));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::iterator ft::map<Key, T, Compare>::upper_bound(const typename ft::map<Key, T, Compare>::key_type &k)
{
	typename ft::map<Key, T, Compare>::iterator it;
	typename ft::map<Key, T, Compare>::iterator end;
	typename ft::map<Key, T, Compare>::iterator found;

	end = this->end();
	found = this->find(k);
	if (found != end)
		return (++found);

	it = this->begin();
	while (it != end)
	{
		if (key_comp()(k, it->first) == true)
			return(it);
		it++;
	}
	return (iterator(this->tree, &(this->tree),true));
}

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::const_iterator ft::map<Key, T, Compare>::upper_bound(const typename ft::map<Key, T, Compare>::key_type &k) const
{
	typename ft::map<Key, T, Compare>::const_iterator it;
	typename ft::map<Key, T, Compare>::const_iterator end;
	typename ft::map<Key, T, Compare>::const_iterator found;

	end = this->end();
	found = this->find(k);
	if (found != end)
		return (++found);
	it = this->begin();
	while (it != end)
	{
		if (key_comp()(k, it->first) == true)
			return(it);
		it++;
	}
	return (const_iterator(this->tree, &(this->tree),true));
}

template<class Key, class T, class Compare>
ft::pair<typename ft::map<Key, T, Compare>::iterator, typename ft::map<Key, T, Compare>::iterator> ft::map<Key, T, Compare>::equal_range(const typename ft::map<Key, T, Compare>::key_type &k)
{
	return(ft::make_pair<typename ft::map<Key, T, Compare>::iterator, typename ft::map<Key, T, Compare>::iterator>(this->lower_bound(k), this->upper_bound(k)));
}

template<class Key, class T, class Compare>
ft::pair<typename ft::map<Key, T, Compare>::const_iterator, typename ft::map<Key, T, Compare>::const_iterator> ft::map<Key, T, Compare>::equal_range(const typename ft::map<Key, T, Compare>::key_type &k) const
{
	return(ft::make_pair<typename ft::map<Key, T, Compare>::const_iterator, typename ft::map<Key, T, Compare>::const_iterator>(this->lower_bound(k), this->upper_bound(k)));
}

//Allocator

template<class Key, class T, class Compare>
typename ft::map<Key, T, Compare>::allocator_type ft::map<Key, T, Compare>::get_allocator() const
{
	return (this->Alloc);
}

//Comparaison Operators

template<class Key, class T, class Compare>
bool ft::operator==(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
		return (true);
	return (false);
}

template<class Key, class T, class Compare>
bool ft::operator!=(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs)
{
	if (lhs == rhs)
		return (false);
	return (true);
}

template<class Key, class T, class Compare>
bool ft::operator<(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs)
{
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return (true);
	return (false);
}

template<class Key, class T, class Compare>
bool ft::operator>(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs)
{
	if (lhs == rhs)
		return (false);
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return (false);
	return (true);
}

template<class Key, class T, class Compare>
bool ft::operator>=(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs)
{
	if (lhs == rhs)
		return (true);
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return (false);
	return (true);
}

template<class Key, class T, class Compare>
bool ft::operator<=(const ft::map<Key, T, Compare> &lhs, const ft::map<Key, T, Compare> &rhs)
{
	if (lhs == rhs)
		return (true);
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return (true);
	return (false);
}

#endif