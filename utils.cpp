#include "utils.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include <list>
#include <string>
#include <complex>

/*
unsigned long long int pow2(int n)
{
	unsigned long long int res;

	res = 1;

	while (n)
	{
		res *=2;
		n--;
	}
	return (res);
}
*/

class A
{
	private:
		std::string truc;
};

bool mypredicate(int i, int j)
{
	return(i == j);
}

bool comparestr(char c1, char c2)
{
	return (c1 < c2);
}

typedef std::vector<int>::iterator iter;
void test_utils()
{
	std::cout << "ok" << std::endl;
	if (ft::is_integral<A>::value)
	{
		std::cout << "A is integral" << std::endl;
	}
	else
	{
		std::cout << "A is not integral" << std::endl;
	}

	if (ft::is_integral<int>::value)
        {
                std::cout << "int is integral" << std::endl;
        }
        else
        {
                std::cout << "int is not integral" << std::endl;
        }

	std::vector<int> vec(10, 0);

	vec.back()+=22;

	std::vector<int>::iterator it1 = vec.begin();
	std::vector<int>::iterator it2 = vec.end();
	std::vector<int>::iterator it3 = vec.begin();

	if (ft::equal<iter, iter>(it1, it2, it3))
	{
		std::cout << "egality of iterators" << std::endl;
	}

	if (ft::equal<iter, iter>(it1, it2, it3, mypredicate))
	{
		std::cout << "egality of iterators throught predicate" << std::endl;
	}

	std::string mot1("Teleportation");
	std::string mot2("Cheval");

	std::cout << ft::lexicographical_compare(mot1.begin(), mot1.end(), mot2.begin(), mot2.end()) << std::endl;
	std::cout << ft::lexicographical_compare(mot2.begin(), mot2.end(), mot1.begin(), mot1.end()) << std::endl;
	std::cout << ft::lexicographical_compare(mot1.begin(), mot1.end(), mot2.begin(), mot2.end(), comparestr) << std::endl;
	std::cout << ft::lexicographical_compare(mot2.begin(), mot2.end(), mot1.begin(), mot1.end(), comparestr) << std::endl;

	std::cout << std::endl;

	std::cout << "---reverse iterator test---" << std::endl;
	
	std::list<int> lst;
	lst.push_back(1); lst.push_back(2); lst.push_back(3); lst.push_back(4);
	std::list<int>::iterator it = lst.begin();
	ns::reverse_iterator<std::list<int>::iterator> rev(lst.end());

	while (it != lst.end())
	{
		std::cout << "*it = " << *it << " *rev = " << *rev << " *rev.base() = " << *rev.base() << std::endl;
		
		rev++;
		it++;
	}

	int a[] = {1, 2, 3, 4};
	
	ns::reverse_iterator<int *> rev2(std::end(a));
	for (int i = 0; i < 4 ; i++)
	{
		std::cout << "a[i] = " << a[i] << " rev[i] = " << rev2[i] << " *(rev + i) = " << *(rev2 + i) << std::endl;
	}

	std::vector<std::complex<double>> vc { {1,2}, {3,4}, {5,6}, {7,8} };
    ns::reverse_iterator<std::vector<std::complex<double> >::iterator> r2 (vc.end() - 1);
    std::cout << "vc[2] = " << "(" << r2->real() << "," << r2->imag() << ")\n";


	ns::reverse_iterator<int *> revcp(rev2);
	ns::reverse_iterator<int *> revunder(rev2 - 2);

	if (revcp != revunder)
		std::cout << "revcp is different than revunder" << std::endl;
	if (rev2 > revunder)
		std::cout << "revcp is greater than revunder" << std::endl;

	std::cout << std::endl;

	std::cout << "-----pair test-----" << std::endl;

	ns::pair<int, std::string> p;
	ns::pair<int, std::string> tx(3, "trois");
	p = ns::make_pair<int, std::string>(7, "sept");
	ns::pair<int, std::string> cpy(p);

	std::cout << tx.first << " is " << tx.second << " in french" <<std::endl;
	std::cout << cpy.first << " is " << cpy.second << " in french" <<std::endl;
	
	ns::pair<int, std::string> engp(7, "seven");

	if (cpy < engp)
		std::cout << cpy.second << " is lower than " << engp.second << std::endl;
	else
		std::cout << cpy.second << " is greater than " << engp.second << std::endl;
	return ;
}
