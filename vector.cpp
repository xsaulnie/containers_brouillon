#include "vector.hpp"
//#define ns ft

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template<typename T>
void displayit_vector(typename ns::vector<T> vec)
{
	typename ns::vector<T>::iterator it;
	for (it = vec.begin() ; it != vec.end() ; it++)
	{
		std::cout << "|" << *it << "|";
	}
	std::cout << std::endl;
}

template<typename T>
void display_reverseit(typename ns::vector<T> vec)
{
	typename ns::vector<T>::reverse_iterator it;
	for (it = vec.rbegin() ; it != vec.rend() ; it++)
	{
		std::cout << "/" << *it << "/";
	}
	std::cout << std::endl;
}

template<typename T>
void display_reverse(typename ns::vector<T> vec)
{
	size_t i;

	typename ns::vector<T>::reverse_iterator it;
	i = vec.size();
	while (i > 0 )
	{
		std::cout << "{" << it[i] << "}";
		i--;
	}
	std::cout << std::endl;
}

template<typename T>
void display_vector(typename ns::vector<T> &vec, const std::string &name = "")
{
	std::cout << name << " ";
	for (size_t i = 0 ; i < vec.size() ; i++)
	{
		std::cout << "[" << vec[i] << "]";
	}
	std::cout << " " << vec.size() << " " << vec.capacity();
	std::cout << std::endl;
}

void test_capacity(bool reserved)
{
	size_t cap;

	ns::vector<int> foo;
	cap = foo.capacity();
	if (reserved)
		foo.reserve(50);
	std::cout << "Capacity test 50 push_back ";
	if (reserved)
		std::cout << "reserved";
	std::cout << std::endl;
	for (int i = 0 ; i < 50 ; i++)
	{
		//std::cout << "{" << i << "-" << foo.size() << "-" << foo.capacity() << "}" << std::endl;
		foo.push_back(i);
		if (cap != foo.capacity())
		{
			cap = foo.capacity();
			std::cout << "capacity changed: " << cap << std::endl;
		}
	}
}

void test_awesome()
{
	ns::vector<Awesome> test(21, 12);
	display_vector(test);
	ns::vector<Awesome> test2;
	display_vector(test2);
	test2.push_back(12);
	test2.push_back(8);
	test2.push_back(16);
	
	display_vector(test2);
	
	test.assign(test2.begin(), test2.end());
	display_vector(test);

	test = test2;
	
	display_vector(test);

	test.insert(test.end(), test2.begin(), test2.end());
	
	display_vector(test);
	/*
	test.insert(test.begin(), test2.begin(), test2.end());
	display_vector(test);
*/


//	ns::vector<Awesome> test2;
//	display_vector(test2);
	//test2.push_back(12);
	//test2.push_back(8);
	//test2.push_back(16);


}

void test_vector()
{
	
	ns::vector<int> insT;

	insT.reserve(100);
	std::cout << "s: " << insT.size() << "c: " << insT.capacity() << std::endl;
	insT.push_back(1);insT.push_back(2);insT.push_back(3);insT.push_back(4);insT.push_back(5);insT.push_back(6);
	std::cout << "s: " << insT.size() << "c: " << insT.capacity() << std::endl;
	insT.insert(insT.begin() + 3, 10, 0);
	display_vector(insT);
	//test_awesome();
    /*
	ns::vector<int>::iterator lul;
	ns::vector<int>::iterator otherlul(lul); --->classe iterateur
	(void)otherlul;
	return ;
	*/
	return ;
	ns::vector<int> resiz(12, 12);
	std::cout << "s: "<< resiz.size() << "c:" << resiz.capacity() << std::endl;
	resiz.resize(26);
		std::cout << "s: "<< resiz.size() << "c:" << resiz.capacity() << std::endl;
	return ;

	resiz.resize(1028);
	std::cout << "s: "<< resiz.size() << "c:" << resiz.capacity() << std::endl;
	return ;
  ns::vector<int> Myvector (3,100);
  ns::vector<int>::iterator mit;

  mit = Myvector.begin();
  mit = Myvector.insert ( mit , 200 );
  std::cout << Myvector.capacity() <<" " << Myvector.size()<<" myvector contains:";
  for (mit=Myvector.begin(); mit<Myvector.end(); mit++)
    std::cout << ' ' << *mit;
  std::cout << '\n';
	return ;

	ns::vector<int> vct(10);
	ns::vector<int> vct2;

	for (unsigned long int i = 0 ; i < vct.size() ; ++i)
		vct[i] = (vct.size() - i) * 3;
	display_vector(vct, "vct");
	vct2.insert(vct2.begin(), vct.begin(), vct.end() - 2);
	display_vector(vct2, "vct2");

	vct.swap(vct2);

	display_vector(vct, "vct");
	display_vector(vct2, "vct2");

/*
	ns::vector<int>::iterator ites;

	ites = vct.begin();
	ns::vector<int>::reverse_iterator rites(ites);

	ns::vector<int>::const_reverse_iterator crites(rites);

	const int * const_it;
	int * n_it;

	int tab[10];
	
	const_it = tab + 6;
	n_it = tab + 6;

	if (const_it == n_it)
		std::cout << "OK" << std::endl;
*/	
	return ;

	ns::vector<int> first;
	display_vector(first, "default constructor");
	first.push_back(12);
	display_vector(first, "push_back 1");
	first.push_back(28);
	display_vector(first, "push_back 2");
	std::cout << "first ";
	displayit_vector(first);
	display_vector(first, "first");
	ns::vector<int> second(10, 8);
	second.push_back(-3);
	std::cout << "second ";
	displayit_vector(second);
	ns::vector<int> third(first.begin(), first.end());
	third.push_back(3);
	display_vector(third, "third");
	ns::vector<int> cpy(third);
	
	if (cpy == third)
		std::cout << "cpy and third are equal" << std::endl;
	
	display_vector(cpy, "cpy");
	std::cout << std::endl;

	ns::vector<int> b(20, 3);
	ns::vector<int> a(10, 8);

	b.push_back(10);
	display_vector(b, "b");
	display_vector(a, "a");
	a = b;
	display_vector(a, "a = b");
	std::cout << "a = b Size and capacity : " << a.size() << " " << a.capacity() << std::endl;

	ns::vector<int> order;
	order.push_back(0); order.push_back(1); order.push_back(2); order.push_back(3); order.push_back(4);
	display_vector(order, "order");
	std::cout << "order ";
	display_reverseit(order);

	//display_reverse(order);
	ns::vector<double> big;
	std::vector<double> bigc;
	std::cout << "Maximum size " << big.max_size() << std::endl;

	ns::vector<int> muta(10, 0);
	display_vector(muta, "muta");
	muta.resize(15, 1);
	display_vector(muta, "muta");

	ns::vector<int> muto(10, 0);
	display_vector(muto, "muto");
	muto.resize(5, 1);
	display_vector(muto, "muto");
	muto.resize(7, 2);
	display_vector(muto, "muto");
	muto.resize(0);
	display_vector(muto, "muto");
	if (muto.empty())
		std::cout << "muto is empty" << std::endl;

	ns::vector<int> place(12);
	place.reserve(15);

	display_vector(place, "place reserved 15");
	place.reserve(100);
	display_vector(place, "place reserved 100");

	test_capacity(false);
	test_capacity(true);

	ns::vector<int> assigned;

	assigned.assign(10, 3);
	display_vector(assigned, "10 3 assigned");
	assigned.assign(6, 1);
	display_vector(assigned, "6 1 assigned");
	assigned.assign(muta.begin(), muta.end());
	display_vector(assigned, "assigned as muta");
	assigned.assign(order.begin(), order.end());
	display_vector(assigned, "assigned as order");
	assigned.pop_back();
	assigned.pop_back();
	display_vector(assigned, "assigned double pop_back");

	ns::vector<int> erased;
	order.push_back(5);order.push_back(6);order.push_back(7);order.push_back(8);order.push_back(9);
	erased.assign(order.begin(), order.end());

	std::cout << std::endl;
	display_vector(erased, "erased");
	erased.erase(erased.begin() + 5);
	display_vector(erased, "5 erased");
	erased.erase(erased.end() - 1);
	display_vector(erased, "last erased");
	erased.erase(erased.begin());
	display_vector(erased, "first erased");

	erased.assign(order.begin(), order.end());
	erased.erase(erased.end() - 2, erased.end());
	display_vector(erased, "last 2 erased");

	erased.assign(order.begin(), order.end());
	erased.erase(erased.begin(), erased.begin() + 2);
	display_vector(erased, "first 2 erased");

	erased.assign(order.begin(), order.end());
	erased.erase(erased.begin() + 2, erased.end() - 2);
	display_vector(erased, "last 2, first 2, not  erased");

	std::cout << std::endl;
	ns::vector<int> inserted;
	inserted.assign(order.begin(), order.end());
	display_vector(inserted, "test");
	inserted.insert(inserted.begin() + 2, 0);
	display_vector(inserted, "0 inserted at pos 2");
	inserted.insert(inserted.end() - 1, 0);
	display_vector(inserted, "0 inserted before last");

	ns::vector<int> minserted;

	minserted.assign(order.begin(), order.end());
	minserted.insert(minserted.begin() + 2, 5, 0);
	display_vector(minserted, "5 0 inserted at pos 2");

	minserted.insert(minserted.begin() + 8, 3, 7);
	display_vector(minserted, "3 7 inserted at pos 8");
	minserted.insert(minserted.end(), 2, 10);
	display_vector(minserted, "2 10 inserted last pos");
	minserted.insert(minserted.end() - 2, 10, -2);
	display_vector(minserted, "10 -2 inserted before the 10");

	std::cout<< std::endl;

	ns::vector<int> iterinserted(8);
	ns::vector<int> little1;
	little1.push_back(1); little1.push_back(2); little1.push_back(3);
	iterinserted.insert(iterinserted.begin() + 2, little1.begin(), little1.end());
	display_vector(iterinserted, "little at pos 2");

	iterinserted.insert(iterinserted.end() - 1, little1.begin(), little1.end());
	display_vector(iterinserted, "little before the end");

	ns::vector<int> lit;
	lit.push_back(10); lit.push_back(11);
	iterinserted.insert(iterinserted.end(), lit.begin(), lit.end());
	display_vector(iterinserted, "10 11 at the end");
	iterinserted.insert(iterinserted.begin() + 5, little1.begin(), little1.end());
	display_vector(iterinserted, "123 pos 5");

	ns::vector<int>::const_iterator cit;

	cit = minserted.begin();

	while (cit != minserted.end())
	{
		std::cout << "|" << *cit << "|";
		cit++;
	}
	std::cout << std::endl;
	return ;
}