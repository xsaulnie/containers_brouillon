#ifndef RBTree_HPP
#define RBTree_HPP
#include <iostream>
#include "stdlib.h"
#include "pair.hpp"


//const T pair

template<class T, class V, class C = std::less<T> >
class RBtree
{
	public:

	typedef typename std::allocator<ft::pair<const T, V> > alloc_t;

	RBtree          		*left;
	RBtree          		*right;
	RBtree          		*parent;
	bool					color;
	ft::pair<const T, V> 	*p;


	//Constructor
	RBtree<T, V, C>(alloc_t &Alloc);
	RBtree<T, V, C>(const T &key, const V &val, alloc_t &Alloc);
	
		RBtree<T, V, C> *getpar(RBtree<T, V, C> *n);
		RBtree<T, V, C> *grandparent(RBtree<T, V, C> *n);
		RBtree<T, V, C> *brother(RBtree<T, V, C> *n);
		RBtree<T, V, C> *oncle(RBtree<T, V, C> *n);

		void rot_left(RBtree<T, V, C> *n);
		void rot_right(RBtree<T, V, C> *n);
		RBtree<T, V, C> *search(RBtree<T, V, C> *rac, const T &key, C &comp);
		RBtree<T, V, C> *search(RBtree<T, V, C> *rac, const T &key, const C &comp) const;
		void new_element(RBtree<T, V, C> *rac, RBtree<T, V, C> *n, C &comp);
		void repare(RBtree<T, V, C>  *n);
		void repareOncleBlack(RBtree<T, V, C> *n);
		bool blackNephews(RBtree<T, V, C> *n);
		RBtree<T, V, C> *insert(RBtree<T, V, C> *rac, RBtree<T, V, C> *n, C &comp);
		RBtree<T, V, C> *vanish(RBtree<T, V, C> *rac, const T &key, bool &erased, C &comp, alloc_t &Alloc);
		RBtree<T, V, C> *tovanish(RBtree<T, V, C> *start, alloc_t &Alloc);
		RBtree<T, V, C> *reparevanish(RBtree<T, V, C> *rac, RBtree<T, V, C> *n);
		RBtree<T, V, C> *getrac(RBtree<T, V, C> *n);

		void supress(RBtree<T, V, C> *n, alloc_t &Alloc);
		void clear(RBtree<T, V, C> *rac, alloc_t &Alloc);

		RBtree<T, V, C> *RBpair(const T &key, const V &val, std::allocator<ft::pair<const T, V> > &Alloc);

};

template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::getrac(RBtree<T, V, C> *n)
{
	RBtree<T, V, C> *res;

	res = n;
	while (getpar(res) != NULL)
		res = getpar(res);
	return (res);
}

template <class T, class V, class C>
void display_node(RBtree<T, V, C> *n, std::string name);

template<class T, class V, class C>
void disp_tree(RBtree<T, V, C> *n)
{
	RBtree<T, V, C> *rac;
	std::cout << "enter " << std::endl;
	rac = n;
	while (n->getpar(rac) != NULL)
		rac = n->getpar(rac);
	std::cout << "----------------------";
	display_tree(rac, 0);
	std::cout << "----------------------" << std::endl;
}

template<class T, class V, class C>
void display_tree(RBtree<T, V, C> *rac, int sp)
{
	if (rac == NULL)
		return ;
	sp += 5;

	display_tree(rac->right, sp);

	if (sp != 0)
		std::cout << std::endl;

	for (int i = 5 ; i < sp ; i++)
	{
		std::cout << " ";
	}
	if (rac->color == 1)
		std::cout << "|" << rac->p->first << "|" << std::endl;
	else
	{
		std::cout << rac->p->first << std::endl;
	}
	display_tree(rac->left, sp);
}

template<class T, class V, class C>
RBtree<T, V, C> *RBpair(const T &key, const V &val, std::allocator<ft::pair<const T, V> > &Alloc);

template<class T, class V, class C>
void display_tree(RBtree<T, V, C> *rac, int sp);

template<class T, class V, class C>
RBtree<T, V, C>::RBtree(const T &key, const V &val, alloc_t &Alloc)
{
	this->parent = NULL;
	this->color = 0;
	this->left = NULL;
	this->right = NULL;
	this->p = Alloc.allocate(1);
	Alloc.construct(this->p, ft::make_pair<const T, V>(key, val));
	//std::cout << "()" <<this->p->first << " " << this->p->second << "()" << std::endl;
}

template <class T, class V, class C> 
RBtree<T, V, C>::RBtree(alloc_t &Alloc)
{
	this->color = 0;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
	this->p = Alloc.allocate(1);
	Alloc.construct(this->p, ft::make_pair<const T, V>(T(), V()));
}

template<class T, class V, class C>
RBtree<T, V, C> *RBpair(const T &key, const V &val, std::allocator<ft::pair<const T, V> > &Alloc)
{
	return new RBtree<T, V, C>(key, val, Alloc);
}

template <class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::RBpair(const T &key, const V &val, std::allocator<ft::pair<const T, V> > &Alloc)
{
	return new RBtree<T, V, C>(key, val, Alloc);
}

/*
template<class T, class V, class C>
RBtree<T, const V, C> *const_RBpair(const T &key, const V &val, std::allocator<ft::pair<const T, V>> &Alloc)
{
	return new RBtree<T, const V, C>(key, val, Alloc);
}
*/


template<class T, class V, class C>
void RBtree<T, V, C>::clear(RBtree<T, V, C> *rac, alloc_t &Alloc)
{
	if (rac == NULL)
		return ;
	if (rac->left == NULL && rac->right == NULL)
	{
		//std::cout << "cleared " << rac->p->first << std::endl;
		Alloc.deallocate(rac->p, 1);
		delete (rac);
		return ;
	}
	if (rac->left != NULL)
		clear(rac->left,  Alloc);
	if (rac->right != NULL)
		clear(rac->right, Alloc);
	//std::cout << "cleared " << rac->p->first << std::endl;
	Alloc.deallocate(rac->p, 1);
	delete (rac);
	return ;
}

template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::insert(RBtree<T, V, C> *rac, RBtree<T, V, C> *n, C &comp)
{
	new_element(rac, n, comp);

	//std::cout << "hello" << std::endl;
	//std::cout << "new element inserted" << std::endl;
	//disp_tree(rac);
	
	repare(n);
	
	rac = n;
	while (getpar(rac) != NULL)
		rac = getpar(rac);
	return (rac);
}

template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::search(RBtree<T, V, C> *rac, const T &key, C &comp)
{
	while (1)
	{
		if (rac == NULL)
			return (NULL);
		if (!comp(key, rac->p->first) && !comp(rac->p->first, key))
			return (rac);
		if (comp(key, rac->p->first))
			rac = rac->left;
		else
			rac = rac->right;
	}
}


template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::search(RBtree<T, V, C> *rac, const T &key, const C &comp) const
{
	while (1)
	{
		if (rac == NULL)
			return (NULL);
		if (!comp(key, rac->p->first) && !comp(rac->p->first, key))
			return (rac);
		if (comp(key, rac->p->first))
			rac = rac->left;
		else
			rac = rac->right;
	}
}

template<class T,class V, class C>
bool RBtree<T, V, C>::blackNephews(RBtree<T, V, C> *n)
{
	if (brother(n) == NULL)
		return (true);
	if (brother(n)->left != NULL && brother(n)->left->color == 1)
		return (false);
	if (brother(n)->right != NULL && brother(n)->right->color == 1)
		return (false);
	return (true);
}

template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::reparevanish(RBtree<T, V, C> *rac, RBtree<T, V, C> *n)
{
//	disp_tree(rac);
	// cas 1

	if (n == rac)
	{
//		std::cout << "case 1" << std::endl;
		n->color = 0;
		return (rac);
	}

	//cas 2

	if (brother(n) && brother(n)->color == 1 && getpar(n)->color == 0 && blackNephews(n))
	{
//		std::cout << "case 2" << std::endl;
		if (rac == getpar(n))
			rac = brother(n);
		brother(n)->color = 0;
		getpar(n)->color = 1;
		if (n == getpar(n)->left)
			rot_left(brother(n));
		else
			rot_right(brother(n));
		reparevanish(rac, n);
	}

	//cas 3

	if (brother(n) && brother(n)->color == 0 && getpar(n)->color == 0 && blackNephews(n))
	{
//		std::cout << "case 3" << std::endl;
		brother(n)->color = 1;
		reparevanish(rac, getpar(n));
	}

	//cas 4

	if (brother(n) && brother(n)->color == 0 && getpar(n)->color == 1 && blackNephews(n))
	{
//		std::cout << "case 4" << std::endl;
		getpar(n)->color = 0;
		brother(n)->color = 1;
		return (rac);
	}

	//cas 5

	if (n == getpar(n)->left)
	{
	if (brother(n) && brother(n)->color == 0 && brother(n)->left && brother(n)->left->color == 1 && (brother(n)->right == NULL || brother(n)->right->color == 0))
	{
//		std::cout << "case 5 left" << std::endl;
		brother(n)->left->color = 0;
		brother(n)->color = 1;
		if (brother(n) == rac)
			rac = brother(n)->left;
		rot_right(brother(n)->left);
		reparevanish(rac, n);
	}
	}
	else
	{
	if (brother(n) && brother(n)->color == 0 && brother(n)->right && brother(n)->right->color == 1 && (brother(n)->left == NULL || brother(n)->left->color == 0))
	{
//		std::cout << "case 5 right" << std::endl;
		brother(n)->right->color = 0;
		brother(n)->color = 1;
		if (brother(n) == rac)
			rac = brother(n)->right;
		rot_left(brother(n)->right);
		reparevanish(rac, n);
	}
	}
	//cas 6

	if (n == getpar(n)->left)
	{
	if (brother(n) && brother(n)->color == 0 && brother(n)->right && brother(n)->right->color == 1)
	{
//		std::cout << "case 6 left" << std::endl;
		if (rac == getpar(n))
			rac = brother(n);
		brother(n)->right->color = 0;
		brother(n)->color = getpar(n)->color;
		rot_left(brother(n));
		getpar(n)->color = 0;
		return (rac);
	}
	}
	else
	{
	if (brother(n) && brother(n)->color == 0 && brother(n)->left && brother(n)->left->color == 1)
	{
//		std::cout << "case 6 right" << std::endl;
		if (rac == getpar(n))
			rac = brother(n);

		brother(n)->left->color = 0;
		brother(n)->color = getpar(n)->color;
		rot_right(brother(n));
		//std::cout << "turn is" << rac->p->first << std::endl;
		//disp_tree(rac);
		return (rac);
	}
	}
	return (rac);
}

template <class T, class V, class C>
void RBtree<T, V, C>::supress(RBtree *n, alloc_t &Alloc)
{
	if (n->parent && n == n->parent->left)
	{
		n->parent->left = NULL;
	}
	else if (n->parent && n == n->parent->right)
	{
		n->parent->right = NULL;
	}
	Alloc.deallocate(n->p, 1);
	delete n;
}

template <class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::tovanish(RBtree<T, V, C> *start, alloc_t &Alloc)
{
	RBtree<T, V, C> *cur;

	cur = start;
	if (start->right != NULL && start->left == NULL)
	{
		Alloc.deallocate(start->p, 1);
		start->p = Alloc.allocate(1);
		Alloc.construct(start->p, ft::make_pair<const T, V>(start->right->p->first, start->right->p->second));
		return (start->right);
	}
	if (start->right == NULL && start->left != NULL)
	{
		Alloc.deallocate(start->p, 1);
		start->p = Alloc.allocate(1);
		Alloc.construct(start->p, ft::make_pair<const T, V>(start->left->p->first, start->left->p->second));
		return (start->left);
	}
	if (start->right != NULL && start->left != NULL)
	{
		cur = start->right;
		while (cur->left != NULL)
		{
			cur = cur->left;
		}
		Alloc.deallocate(start->p, 1);
		start->p = Alloc.allocate(1);
		Alloc.construct(start->p, ft::make_pair<const T, V>(cur->p->first, cur->p->second));
		return (cur);
	}
	return (start);
}

template <class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::vanish(RBtree<T, V, C> *rac, const T &key, bool &erased, C &comp, typename RBtree<T, V, C>::alloc_t &Alloc)
{
	RBtree<T, V, C> *res;

	erased = true;
	res = rac->search(rac, key, comp);
	if (res == NULL)
	{
		erased = false;
		return (rac);
	}
	res = rac->tovanish(res, Alloc);
	if (res == rac)
	{
		rac->supress(res, Alloc);
		return (NULL);
	}

	if (res->left == NULL && res->right == NULL)
	{
		if (res->color == 1)
		{
			//std::cout << "final red case" << std::endl;
			rac->supress(res, Alloc);
			return (getrac(rac));
		}
		rac = reparevanish(rac, res);
		//std::cout << "after supression " << rac->p->first << std::endl;
		rac->supress(res, Alloc);
		return (getrac(rac));
	}

	if (res->right != NULL)
	{
		if (res->color == 0)
			rac = reparevanish(rac, res);
		if (res == getpar(res)->right)
			getpar(res)->right = res->right;
		else
			getpar(res)->left = res->right;
		res->right->parent = getpar(res);
		Alloc.deallocate(res->p, 1);
		delete res;
		return (getrac(rac));
	}

	if (res->left != NULL)
	{
		if (res->color == 0)
			rac = reparevanish(rac, res);
		if (res == getpar(res)->right)
			getpar(res)->right = res->left;
		else
			getpar(res)->left = res->left;
		res->left->parent = getpar(res);
		Alloc.deallocate(res->p, 1);
		delete res;
		return (getrac(rac));
	}
	return (getrac(rac));
}
/*
template<class T, class V, class C>
void RBtree<T, V, C>::rot_left(RBtree<T, V, C> *y) //3-4-6
{
	RBtree<T, V, C> *x = getpar(y);

	if (x == NULL)
	{
		rot_left(y->right);
		return ;
	}

	if (y->left != NULL)
	{
		y->left->parent = x;
		x->right = y->left;
		y->left = NULL;
		y->parent = NULL;
	}
	else
	{
		x->right = NULL;
	}
	if (x->parent == NULL)
	{
		y->parent = NULL;
		x->parent = y;
		y->left = x;
		return ;
	}
	if (x->parent != NULL)
	{
		if (x == x->parent->left)
		{
			y->parent = x->parent;
			x->parent->left = y;
			x->parent = y;
			y->left = x;
		}
		else
		{
			y->parent = x->parent;
			x->parent->right = y;
			x->parent = y;
			y->left = x;
		}
	}
}

template<class T, class V, class C>
void RBtree<T, V, C>::rot_right(RBtree *x)
{
	RBtree<T, V, C> *y = getpar(x);

	if (y == NULL)
	{
		rot_right(x->left);
		return ;
	}

	if (x->right != NULL)
	{
		x->right->parent = y;
		y->left = x->right;
		x->right = NULL;
		x->parent = NULL;
	}
	else
	{
		y->left = NULL;
	}

	if (y->parent == NULL)
	{
		x->parent = NULL;
		x->right = y;
		y->parent = x;
		return ;
	}
	if (y == y->parent->right)
	{
		x->parent = y->parent;
		y->parent->right = x;
		y->parent = x;
		x->right = y;
	}
	else
	{
		x->parent = y->parent;
		y->parent->left = x;
		y->parent = x;
		x->right = y;
	}
}
*/

template<class T, class V, class C>
void RBtree<T, V, C>::rot_left(RBtree<T, V, C> *x) //3-4-6
{
	if (getpar(x) == NULL)
	{
		if (x->right)
			rot_left(x->right);
		return ;
	}
	x = getpar(x);
	RBtree<T, V, C> *y = x->right;

	if (y == NULL)
		return ;

	if (y->left != NULL)
	{
		y->left->parent = x;
		x->right = y->left;
		y->left = NULL;
		y->parent = NULL;
	}
	else
	{
		x->right = NULL;
	}
	if (x->parent == NULL)
	{
		y->parent = NULL;
		x->parent = y;
		y->left = x;
		return ;
	}
	if (x->parent != NULL)
	{
		if (x == x->parent->left)
		{
			y->parent = x->parent;
			x->parent->left = y;
			x->parent = y;
			y->left = x;
		}
		else
		{
			y->parent = x->parent;
			x->parent->right = y;
			x->parent = y;
			y->left = x;
		}
	}
}

template<class T, class V, class C>
void RBtree<T, V, C>::rot_right(RBtree *y)
{

	if (getpar(y) == NULL)
	{
		if (y->left)
			rot_right(y->left);
		return ;
	}
	y = getpar(y);
	RBtree<T, V, C> *x = y->left;

	if (x == NULL)
		return ;

	if (x->right != NULL)
	{
		x->right->parent = y;
		y->left = x->right;
		x->right = NULL;
		x->parent = NULL;
	}
	else
	{
		y->left = NULL;
	}

	if (y->parent == NULL)
	{
		x->parent = NULL;
		x->right = y;
		y->parent = x;
		return ;
	}
	if (y == y->parent->right)
	{
		x->parent = y->parent;
		y->parent->right = x;
		y->parent = x;
		x->right = y;
	}
	else
	{
		x->parent = y->parent;
		y->parent->left = x;
		y->parent = x;
		x->right = y;
	}
}

template<class T, class V, class C>
void RBtree<T, V, C>::new_element(RBtree<T, V, C> *rac, RBtree<T, V, C> *n, C &comp)
{
	if (rac != NULL && comp(n->p->first, rac->p->first))
	{
		if (rac->left != NULL)
		{
			new_element(rac->left, n, comp);
			return ;
		}
		else
			rac->left = n;
	}
	else if (rac != NULL)
	{
		if (rac->right != NULL)
		{
			new_element(rac->right, n, comp);
			return ;
		}
		else
			rac->right = n;
	}

	n->parent = rac;
	n->left = NULL;
	n->right = NULL;
	n->color = 1;
	
}

template<class T, class V, class C>
void RBtree<T, V, C>::repareOncleBlack(RBtree<T, V, C> *n)
{
	RBtree<T, V, C> *g = grandparent(n); //13
	bool st = 0;

	if (oncle(n) == NULL)
		st = 1;

	if (g->left && n == g->left->right)
	{
		rot_left(n);
		n = n->left;
	}
	else if (g->right && n == g->right->left)
	{
		rot_right(n);
		n = n->right;
	}

	RBtree<T, V, C> *np = getpar(n);
	RBtree<T, V, C> *ng = grandparent(n);

	if (n == np->left)
	{
		if (st)
			rot_right(np);
		else
			rot_right(np);
	}
	else
	{
		if (st)
		{
			rot_left(np);
		}
		else
		{
			rot_left(np); // p or g
		}
	}
	np->color = 0;
	ng->color = 1;
}

template<class T, class V, class C>
void RBtree<T, V, C>::repare(RBtree<T, V, C> *n)
{
	if (getpar(n) == NULL)
	{
		n->color = 0;
		return ;
	}
	if (getpar(n)->color == 0)
		return ;

	if (oncle(n) && oncle(n)->color == 1)
	{
		getpar(n)->color = 0;
		oncle(n)->color = 0;
		RBtree<T, V, C> *g = grandparent(n);
		if (g != NULL)
		{ 
			g->color = 1;
			if (getpar(g) == NULL)
			{
				g->color = 0;
				return ;
			}
			//std::cout << "ok" << std::endl;
			//disp_tree(g);
			repare(g);
		}
		return ;
	}
	//std::cout << "black" << std::endl;
	repareOncleBlack(n);
}

template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::getpar(RBtree *n)
{
	if (n == NULL)
		return (NULL);
	return (n->parent);
}

template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::grandparent(RBtree *n)
{
	RBtree<T, V, C> *p = getpar(n);

	if (p == NULL)
		return (NULL);
	return(getpar(p));
}

template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::brother(RBtree *n)
{
	RBtree<T, V, C> *p = getpar(n);

	if (p == NULL)
		return (NULL);
	if (n == p->left)
		return (p->right);
	return (p->left);
}

template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::oncle(RBtree *n)
{
	RBtree<T, V, C> *p = getpar(n);
	RBtree<T, V, C> *gp = grandparent(n);

	if (gp == NULL)
		return(NULL);
	return (brother(p));
}


#endif