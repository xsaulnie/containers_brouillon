#ifndef RBpairtree_HPP
#define RBpairtree_HPP
#include <iostream>
#include "stdlib.h"
#include "pair.hpp"


//const T pair
template<class T = int, class V = int, class C = std::less<T>>
class RBtree
{
	public:

	RBtree          *left;
	RBtree          *right;
	RBtree          *parent;
	bool			color;
	ft::pair<T, V> 	p;

	//Constructor
	RBtree<T, V, C>();
	RBtree<T, V, C>(const T &key, const V &val);
	
		RBtree<T, V, C> *getpar(RBtree<T, V, C> *n);
		RBtree<T, V, C> *grandparent(RBtree<T, V, C> *n);
		RBtree<T, V, C> *brother(RBtree<T, V, C> *n);
		RBtree<T, V, C> *oncle(RBtree<T, V, C> *n);

		void rot_left(RBtree<T, V, C> *n);
		void rot_right(RBtree<T, V, C> *n);
		RBtree<T, V, C> *search(RBtree<T, V, C> *rac, const T &key);
		void new_element(RBtree<T, V, C> *rac, RBtree<T, V, C> *n);
		void repare(RBtree<T, V, C>  *n);
		void repareOncleBlack(RBtree<T, V, C> *n);
		bool blackNephews(RBtree<T, V, C> *n);
		RBtree<T, V, C> *insert(RBtree<T, V, C> *rac, RBtree<T, V, C> *n);
		RBtree<T, V, C> *vanish(RBtree<T, V, C> *rac, const T &key);
		RBtree<T, V, C> *tovanish(RBtree<T, V, C> *start);
		RBtree<T, V, C> *reparevanish(RBtree<T, V, C> *rac, RBtree<T, V, C> *n);
		RBtree<T, V, C> *getrac(RBtree<T, V, C> *n);

		void supress(RBtree<T, V, C> *n);
		void clear(RBtree<T, V, C> *rac);

		friend RBtree<T, V, C> *RBpair(const T &key, const V &val);
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
	std::cout << "pair" << std::endl;
	rac = n;
	while (n->getpar(rac) != NULL)
		rac = n->getpar(rac);
	std::cout << "----------------------";
	display_tree(rac, 0);
	std::cout << "----------------------" << std::endl;
}

/*
template<class T, class V, class C>
void display_tree(RBtree<T, V, C> *rac, int sp)
{
	if (rac == NULL)
		return ;
	sp += 5;

	std::cout <<"lol" << std::endl;
	display_tree(rac->right, sp);

	if (sp != 0)
		std::cout << std::endl;

	for (int i = 5 ; i < sp ; i++)
	{
		std::cout << " ";
	}
	if (rac->color == 1)
		std::cout << "|" << rac->p.first << "|" << std::endl;
	else
	{
		std::cout << rac->p.first << std::endl;
	}
	display_tree(rac->left, sp);
}
*/

//key

template<class T, class V, class C = std::less<T>>
RBtree<T, V, C> *RBpair(const T &key, const V &val);

template<class T, class V, class C>
void display_tree(RBtree<T, V, C> *rac, int sp);

template<class T, class V, class C>
RBtree<T, V, C>::RBtree(const T &key, const V &val)
{
	this->p.first = key;
	this->p.second = val;
	this->parent = NULL;
	this->color = 0;
	this->left = NULL;
	this->right = NULL;
}

template <class T, class V, class C> 
RBtree<T, V, C>::RBtree()
{

}

template<class T, class V, class C>
RBtree<T, V, C> *RBpair(const T &key, const V &val)
{
	return new RBtree<T, V, C>(key, val);
}


template<class T, class V, class C>
void RBtree<T, V, C>::clear(RBtree<T, V, C> *rac)
{
	if (rac == NULL)
		return ;
	if (rac->left == NULL && rac->right == NULL)
	{
		//std::cout << "cleared " << rac->p.first << std::endl;
		delete (rac);
		return ;
	}
	if (rac->left != NULL)
		clear(rac->left);
	if (rac->right != NULL)
		clear(rac->right);
	//std::cout << "cleared " << rac->p.first << std::endl;
	delete (rac);
	return ;
}



template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::insert(RBtree<T, V, C> *rac, RBtree<T, V, C> *n)
{
	new_element(rac, n);
	repare(n);
	rac = n;
	while (getpar(rac) != NULL)
		rac = getpar(rac);
	return (rac);
}


template<class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::search(RBtree<T, V, C> *rac, const T &key)
{
	C comp;
	while (1)
	{
		if (rac == NULL)
			return (NULL);
		if (!comp(key, rac->p.first) && !comp(rac->p.first, key))
			return (rac);
		if (comp(key, rac->p.first))
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
	//disp_tree(rac);
	// cas 1

	if (n == rac)
	{
		//std::cout << "case 1" << std::endl;
		n->color = 0;
		return (rac);
	}

	//cas 2

	if (brother(n) && brother(n)->color == 1 && getpar(n)->color == 0 && blackNephews(n))
	{
		//std::cout << "case 2" << std::endl;
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
		//std::cout << "case 3" << std::endl;
		brother(n)->color = 1;
		reparevanish(rac, getpar(n));
	}

	//cas 4

	if (brother(n) && brother(n)->color == 0 && getpar(n)->color == 1 && blackNephews(n))
	{
		//std::cout << "case 4" << std::endl;
		getpar(n)->color = 0;
		brother(n)->color = 1;
		return (rac);
	}

	//cas 5

	if (n == getpar(n)->left)
	{
	if (brother(n) && brother(n)->color == 0 && brother(n)->left && brother(n)->left->color == 1 && (brother(n)->right == NULL || brother(n)->right->color == 0))
	{
		//std::cout << "case 5 left" << std::endl;
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
		//std::cout << "case 5 right" << std::endl;
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
		//std::cout << "case 6 left" << std::endl;
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
		//std::cout << "case 6 right" << std::endl;
		if (rac == getpar(n))
			rac = brother(n);

		brother(n)->left->color = 0;
		brother(n)->color = getpar(n)->color;
		rot_right(brother(n));
		//std::cout << "turn is" << rac->p.first << std::endl;
		//disp_tree(rac);
		return (rac);
	}
	}
	return (rac);
}

template <class T, class V, class C>
void RBtree<T, V, C>::supress(RBtree *n)
{
	if (n->parent && n == n->parent->left)
	{
		n->parent->left = NULL;
	}
	else if (n->parent && n == n->parent->right)
	{
		n->parent->right = NULL;
	}
	delete n;
}

template <class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::tovanish(RBtree<T, V, C> *start)
{
	RBtree<T, V, C> *cur;

	cur = start;
	if (start->right != NULL && start->left == NULL)
	{
		start->p.first = start->right->p.first;
		start->p.second = start->right->p.second;
		return (start->right);
	}
	if (start->right == NULL && start->left != NULL)
	{
		start->p.first = start->left->p.first;
		start->p.second = start->left->p.second;
		return (start->left);
	}
	if (start->right != NULL && start->left != NULL)
	{
		cur = start->right;
		while (cur->left != NULL)
		{
			cur = cur->left;
		}
		start->p.first = cur->p.second;
		start->p.second = cur->p.second;
		return (cur);
	}
	return (start);
}

template <class T, class V, class C>
RBtree<T, V, C> *RBtree<T, V, C>::vanish(RBtree<T, V, C> *rac, const T &key)
{
	RBtree<T, V, C> *res;

	res = rac->search(rac, key);
	if (res == NULL)
		return (rac);
	res = rac->tovanish(res);
	if (res == rac)
	{
		rac->supress(res);
		return (NULL);
	}

	if (res->left == NULL && res->right == NULL)
	{
		if (res->color == 1)
		{
		//	std::cout << "final red case" << std::endl;
			rac->supress(res);
			return (getrac(rac));
		}
		rac = reparevanish(rac, res);
		//std::cout << "after supression " << rac->p.first << std::endl;
		rac->supress(res);
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
		delete res;
		return (getrac(rac));
	}
	return (getrac(rac));
}

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

template<class T, class V, class C>
void RBtree<T, V, C>::new_element(RBtree<T, V, C> *rac, RBtree<T, V, C> *n)
{
	C comp;
	if (rac != NULL && comp(n->p.first, rac->p.first))
	{
		if (rac->left != NULL)
		{
			new_element(rac->left, n);
			return ;
		}
		else
			rac->left = n;
	}
	else if (rac != NULL)
	{
		if (rac->right != NULL)
		{
			new_element(rac->right, n);
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
	RBtree<T, V, C> *p = getpar(n);
	RBtree<T, V, C> *g = grandparent(n);
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
			rot_right(ng);
	}
	else
	{
		if (st)
		{
			rot_left(np);
		}
		else
		{
			rot_left(ng);
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