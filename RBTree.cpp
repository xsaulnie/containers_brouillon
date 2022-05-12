#include "RBTree.hpp"

template <class T, class V>
void display_node(RBtree<T, V> *n, std::string name)
{
	std::cout << "node " << name << " ";
	std::cout << n->p->first;
	if (n->right == NULL)
	{
		std::cout << " right NULL ";
	}
	else
	{
		std::cout << " right " << n->right->key;
	}
	if (n->left == NULL)
	{
		std::cout << " left NULL ";
	}
	else
	{
		std::cout << " left " << n->left->key;
	}

	if (n->parent == NULL)
	{
		std::cout << " parent NULL ";
	}
	else
	{
		std::cout << " parent " << n->parent->key;
	}
	std::cout << std::endl;
}

template <class T, class V, class C>
RBtree<T, V, C> *stepadd(RBtree<T, V, C> *n, std::allocator<ft::pair<const int, int> > allo)
{

	std::less<int> comp;
	int num1, num2, num3;
	bool err;

	num1 = rand() % 100;
	num2 = rand() % 100;
	num3 = rand() % 100;
	n = n->insert(n, RBpair<T, V, C>(num1, 0, allo), comp);
	n = n->insert(n, RBpair<T, V, C>(num2, 0, allo), comp);
	n = n->insert(n, RBpair<T, V, C>(num3, 0, allo), comp);
	std::cout << "+" << num1 << " "<<num2 << " " << num3<< "-"<< std::endl;
	
	int choice = rand() % 3;

	if (choice == 0)
	{
		n = n->vanish(n, num1, err, comp, allo);
		std::cout << num1 << std::endl;
	}
	if (choice == 1)
	{
		n = n->vanish(n, num2, err, comp, allo);
		std::cout << num2 << std::endl;
	}
	if (choice == 2)
	{
		n = n->vanish(n, num3, err, comp, allo);
		std::cout << num3 << std::endl;
	}
	return (n);
}


void test_RBTree()
{
	std::allocator<ft::pair<const int, int> > allo;
	//std::less<int> comp;



	//RBtree<int, const int> *cst = NULL;

	//cst = cst->insert(cst, const_RBpair(3, 8, allo), comp);


	/*

	RBtree<int, int> *test = NULL;
	bool er;

	test = test->insert(test, RBpair(8, 0, allo), comp);
	test = test->insert(test, RBpair(12, 1, allo), comp);
	test = test->insert(test, RBpair(13, 6, allo), comp);
	test = test->insert(test, RBpair(14, 6, allo), comp);
	test = test->insert(test, RBpair(18, 6, allo), comp);
	disp_tree(test);
	test->rot_right(test->right);
	disp_tree(test);
	return ;
	test = test->insert(test, RBpair(8, 0, allo), comp);

	test = test->insert(test, RBpair(12, 1, allo), comp);
	test = test->insert(test, RBpair(13, 6, allo), comp);
	test = test->insert(test, RBpair(20, 6, allo), comp);
	test = test->insert(test, RBpair(28, 1, allo), comp);
	test = test->insert(test, RBpair(24, 6, allo), comp);
	test = test->insert(test, RBpair(30, 6, allo), comp);
	test = test->insert(test, RBpair(1, 1, allo), comp);
	test = test->insert(test, RBpair(11, 6, allo), comp);
	test = test->insert(test, RBpair(6, 6, allo), comp);
	test = test->insert(test, RBpair(50, 6, allo), comp);
	disp_tree(test);
	test->clear(test, allo);

	RBtree<int, int> *mytree;
	RBtree<int, int> *rac;
	mytree = new RBtree<int, int>(10, 0, allo);

	rac = mytree;

	rac = mytree->insert(rac, RBpair(50, 0, allo), comp);
	disp_tree(rac);

	rac = mytree->insert(rac, RBpair(12, 0, allo), comp);
	disp_tree(rac);

	rac = mytree->insert(rac, RBpair(58, 0, allo), comp);
	disp_tree(rac);

	rac = mytree->insert(rac, RBpair(20, 0, allo), comp);
	disp_tree(rac);

	rac = mytree->insert(rac, RBpair(54, 0, allo), comp);
	disp_tree(rac);

	rac = mytree->insert(rac, RBpair(14, 0, allo), comp);
	disp_tree(rac);

	rac = mytree->insert(rac, RBpair(60, 0, allo), comp);
	disp_tree(rac);

	rac = mytree->insert(rac, RBpair(68, 0, allo), comp);
	disp_tree(rac);

	rac = mytree->vanish(rac, 20, er, comp, allo);
	disp_tree(rac);

	rac = mytree->vanish(rac, 54, er, comp, allo);
	disp_tree(rac);

	rac = mytree->vanish(rac, 12, er, comp, allo);
	disp_tree(rac);

	rac = mytree->vanish(rac, 60, er, comp, allo);
	disp_tree(rac);

	*/

	//std::cout << "vanish" << std::endl;
	//rac = mytree->vanish(rac, 60);
	//disp_tree(rac);
	
	srand(time(NULL));
	RBtree<int, int> *truc = NULL;

	for (int i = 0 ; i < 5 ; i++)
	{
		truc = stepadd(truc, allo);
		disp_tree(truc);
	}
	return ;


 



	
/*
	mytree->rot_right(rac->left->left->left);

	while (mytree->getpar(rac) != NULL)
		rac = mytree->getpar(rac);
		*/

/*
	display_node(rac, "rac");

	display_node(rac->right, "rac right");
	display_node(rac->left, "rac left");
	*/
	
	
/*
	rac = mytree->insert(rac, RBpair(1, 0));

	rac = mytree->insert(rac, RBpair(2, 0));
	rac = mytree->insert(rac, RBpair(-1, 0));

	
	rac = mytree->insert(rac, RBpair(5, 0));

*/
	//rac->clear(rac, allo);
}
