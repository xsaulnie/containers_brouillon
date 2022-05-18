#include "map.hpp"
#include <string>
#include <map>

template <class Key, class T>
void	print(ns::map<Key, T>& lst)
{
	for (typename ns::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << std::endl;
}

template<class T, class V>
void dispriter_map(ns::map<T, V> &m)
{
	typename ns::map<T, V>::reverse_iterator theend = m.rend();

	std::cout << "------------------------------" << std::endl;
	for (typename ns::map<T, V>::reverse_iterator it = m.rbegin(); it != theend ; it++)
	{
		std::cout << "(" << it->first << ")" << " " << "(" << it->second << ")" <<std::endl;
	}
	std::cout << "------------------------------" << std::endl;
}

template<class T, class V>
void dispiter_map(ns::map<T, V> &m)
{
	typename ns::map<T, V>::iterator theend = m.end();
	typename ns::map<T, V>::iterator it = m.begin();

	std::cout << "------------------------------" << std::endl;
	while ( it != theend)
	{
		std::cout << "(" << it->second << ")" <<std::endl;
		it++;
	}
	std::cout << "------------------------------" << std::endl;
}


template<class Key, class T, class Compare>
void disp_m(ns::map<Key, T, Compare> &m)
{
	(void)m;
	//m.disp_map(m);
}





void test_map()
{
	ns::map<char, int> foo, bar;
	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	ns::map<char, int>::const_iterator tmp = foo.begin();
	ns::map<char, int>::const_iterator tmp2 = bar.begin();

	foo.swap(bar);

	//dispiter_map(foo);
	//dispiter_map(bar);

	ns::map<char, int>	other;

  	other['1'] = 73;
  	other['2'] = 173;
  	other['3'] = 763;
  	other['4'] = 73854;
 	other['5'] = 74683;
  	other['6'] = 753;

	ns::map<char, int>::const_iterator tmp3 = other.begin();


	std::cout << "foo contains:\n";
  	for (ns::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	std::cout << "bar contains:\n";
  	for (ns::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    	std::cout << it->first << " => " << it->second << '\n';
	
	std::cout << std::endl;
	
	std::cout << "bar iterator" << std::endl;
	while (tmp != bar.end())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}
	std::cout << std::endl;
	tmp--;

	std::cout << "foo iterator" << std::endl;
	while (tmp2 != foo.end())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}
	tmp2--;

	std::cout << "other swap with foo"<< std::endl;
	other.swap(foo);
	std::cout << "other" << std::endl;
	print(other);
	std::cout << "foo" << std::endl;
	print(foo);
	std::cout << "bar" << std::endl;
	print(bar);
	std::cout << "bar iterator" << std::endl;
	while(tmp != bar.begin())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp--;
	}

	return ;

	ns::map<int, int> poulette;

	poulette.insert(ns::pair<int, int>(0, 0));
	ns::map<int, int>::const_iterator pouend;
	pouend = poulette.end();

	poulette.insert(ns::pair<int, int>(1, 1));
	ns::map<int, int>::const_iterator npouend;
	npouend = poulette.end();

	if (pouend == npouend)
		std::cout << "egality " << (--pouend)->first << " and " <<(--npouend)->first <<std::endl;
	else
		std::cout << "inegality" << std::endl;
	ns::map<int, int>::iterator emptyd;
	ns::map<int, int>::iterator emptye;

	ns::map<int, int> emptyness;
	emptyd = emptyness.begin();
	emptye = emptyness.end();

	if (emptyd == emptye)
		std::cout << "deb is end for empty" << std::endl;
	else
		std::cout << "deb is not end for empty" << std::endl;

	ns::map<char, int> mp1;
	ns::map<char, int> mp2;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	//dispiter_map(mp1);
	//disp_m(mp1);

	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	//dispiter_map(mp2);
	//disp_m(mp2);

	if (mp1 == mp2)
		std::cout << "OK" << std::endl;


/*
	ns::map<int, std::string> mp;

	mp.insert(ns::pair<int, std::string>(42, "lol"));
	mp.insert(ns::pair<int, std::string>(42, "mdr"));
	mp.insert(ns::pair<int, std::string>(50, "mdr"));
	mp.insert(ns::pair<int, std::string>(35, "funny"));
	mp.insert(ns::pair<int, std::string>(45, "bunny"));
	mp.insert(ns::pair<int, std::string>(21, "fizz"));
	mp.insert(ns::pair<int, std::string>(38, "buzz"));
	dispiter_map(mp);
	disp_m(mp);
	mp.insert(mp.begin(), ns::pair<int, std::string>(55, "fuzzy"));

	dispiter_map(mp);
	disp_m(mp);
	
	
	std::list<ns::pair<const int, int>> loust;

	for (int i = 0 ; i < 7 ; i++)
		loust.push_back(ns::pair<const int, int>(7 - i, i));
	ns::map<int, int> mp;

	std::cout << "size : " << mp.size() << std::endl;
	mp.insert(loust.begin(), loust.end());
	dispiter_map(mp);
	std::cout << "size : " << mp.size() << std::endl;
	
	ns::map<int, int> mp(loust.begin(), loust.end());

	dispiter_map(mp);

	

	ns::map<int, int>::iterator it = mp.begin(), ite = mp.end();

	ns::map<int, int> mp_range(it, --(--ite));

	dispiter_map(mp_range);
	*/



	return;

	ns::map <int, int> test;

	test.insert(ns::pair<int, int>(42, 42));
	ns::map<int, int>::const_iterator cti = test.begin();
	ns::map<int, int>::iterator ti = test.begin();

	if (ti == cti)
		std::cout << "OK" << std::endl;
	return ;
	test.erase(42);
	if (test.empty())
		std::cout << "test is empty" << std::endl;

	ns::pair<ns::map<int, int>::iterator, bool> pairtest;


	//ns::map<int, int> truc = {ns::pair<int, int>(1, 8), ns::pair<int, int>(3, 7)};

	pairtest = test.insert(ns::pair<int, int>(8, 8));
	//std::cout << (pairtest.first)->second << "-" << pairtest.second << std::endl;
	pairtest = test.insert(ns::pair<int, int>(12, 12));
	pairtest = test.insert(ns::pair<int, int>(13, 13));
	pairtest = test.insert(ns::pair<int, int>(20, 20));
	pairtest = test.insert(ns::pair<int, int>(28, 28));
	pairtest = test.insert(ns::pair<int, int>(24, 24));
	pairtest = test.insert(ns::pair<int, int>(30, 30));
	pairtest = test.insert(ns::pair<int, int>(1, 1));
	pairtest = test.insert(ns::pair<int, int>(11,11));
	pairtest = test.insert(ns::pair<int, int>(6, 6));
	pairtest = test.insert(ns::pair<int, int>(50, 50));
	pairtest = test.insert(ns::pair<int, int>(50, 52));


	disp_m(test);


	dispiter_map(test);


	std::cout << "reverse iteration" << std::endl;

	dispriter_map(test);

	ns::map <int, int> iteinser;

	ns::map <int, int> citer(test.begin(), test.end());

	dispiter_map(citer);

	iteinser.insert(++test.begin(), --test.end());

	dispiter_map(iteinser);

	dispiter_map(citer);


	std::cout << " value of citer[30] : " << citer[30] << std::endl;

	std::cout << " value of citer[47] : " << citer[47] << std::endl;

	citer[47] =  47;
	std::cout << " value of citer[47] : " << citer[47] << std::endl;

	disp_m(citer);
	citer.insert(ns::pair<int, int>(27, 8));
	disp_m(citer);

	std::cout << "affecting test at citer" << std::endl;
	citer = test;
	disp_m(citer);

	std::cout << "erasing element 6 and element 30" << std::endl;

	citer.erase(++citer.begin());

	citer.erase(--(--citer.end()));

	disp_m(citer);

	std::cout << "erasing all exepted first and last" << std::endl;

	citer.erase(++citer.begin(), --citer.end());
	disp_m(citer);

	ns::map<int, int> mini;

	mini.insert(ns::pair<int, int>(8, 0));
	mini.insert(ns::pair<int, int>(60, 0));

	std::cout << "mini map" << std::endl;

	disp_m(mini);

	ns::swap(citer, mini);

	std::cout << "mini map after swap" << std::endl;

	disp_m(mini);

	std::cout << "citer after swap" << std::endl;

	disp_m(citer);

	ns::map<int, int> map(test.begin(), test.end());

    ns::map<int, int> map_copy(map);

	std::cout << "Copy constryctor of test" << std::endl;
	disp_m(map_copy);

	if (citer.begin() != citer.end())
		std::cout << "They are differents" << std::endl;

	if (citer == mini)
		std::cout << "citer and mini are equal" << std::endl;
	else
		std::cout << "citer and mini are not equal" << std::endl;
	if (citer != mini)
		std::cout << "citer and mini are differents" << std::endl;
	else
		std::cout << "citer and mini are not differents" << std::endl;

	if (mini == mini)
		std::cout << "mini is mini" << std::endl;
	else
		std::cout << "mini is not mini" << std::endl;

	ns::map<int, std::string> dico1;
	ns::map<int, std::string> dico2;

	dico1.insert(ns::pair<int, std::string>(1, "base"));
	dico1.insert(ns::pair<int, std::string>(2, "bonjour"));

	dico2.insert(ns::pair<int, std::string>(1, "base"));
	dico2.insert(ns::pair<int, std::string>(2, "ca va"));


	if (dico1 > dico2)
		std::cout << "dico1 is inferior" << std::endl;
	else
		std::cout << "dico1 is not inferior" << std::endl;
	
	std::cout << "Test bound" << std::endl;

	std::cout << "Lower bound of 15 : " << (map.lower_bound(15))->first << std::endl;
	std::cout << "Lower bound of 30 : " << (map.lower_bound(30))->first << std::endl;
	std::cout << "Upper bound of 15 : " << (map.upper_bound(15))->first << std::endl;
	std::cout << "Upper bound of 30 : " << (map.upper_bound(30))->first << std::endl;

	if (map.upper_bound(100) == map.end())
		std::cout << "Upper bound of 100 return end iterator" << std::endl;

	ns::pair<ns::map<int, int>::iterator, ns::map<int, int>::iterator> prange;

	prange = map.equal_range(28);
	std::cout << "equal range 28 : "<< (prange.first)->first << "-" <<(prange.second)->first << std::endl;

	ns::map<int, int>::const_iterator cit = map.begin();
	cit++;
	std::cout << cit->second << std::endl;

	return ;
}