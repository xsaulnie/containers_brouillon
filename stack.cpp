#include "vector.hpp"
#include "stack.hpp"
#include <stack>

//#define ns ft

void test_stack()
{
	ns::stack<int> c1;

	c1.push(5);
	std::cout << "pushed 5 on c1" << std::endl;
	std::cout << "c1 size : " << c1.size() << " c1 top "<< c1.top() <<std::endl;

	ns::stack<int> c2(c1);
	std::cout << "c2 copied from c1" << std::endl;
	std::cout << "c2 size : " << c2.size() << " c2 top " << c2.top() << std::endl;

	c1.pop();
	std::cout << "pop on c1" << std::endl;
	c2.push(6);
	std::cout << "pushed 6 on c2" << std::endl;
	std::cout << "c1 size : " << c1.size() << std::endl;
	if (c1.empty())
		std::cout << "c1 is empty" << std::endl;
	std::cout << "c2 size : " << c2.size() << " c2 top " << c2.top() << std::endl;

	ns::stack<int> c3(c2);
	std::cout << "c3 copied from c2" << std::endl;
	if (c2 == c3)
		std::cout << "c3 and c2 are equal" << std::endl;
	return ;
}