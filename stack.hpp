#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
namespace ft
{
template<class T, class Container = ft::vector<T> >
class stack
{
	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

	//constructor

		stack(const Container& cont = Container());
		stack(const stack& other);
		~stack();

		stack &operator=(const stack& other);

		//Checker
		reference top();
		const_reference top() const;

		//Capacity
		bool empty() const;
		size_type size() const;

		//Modifier
		void push(const value_type &value);
		void pop();

		//Operator
		friend bool ft::operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
		friend bool ft::operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
		friend bool ft::operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
		friend bool ft::operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
		friend bool ft::operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
		friend bool ft::operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
	protected:
		Container c;
};
template<class T, class Container>
bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
template<class T, class Container>
bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
template<class T, class Container>
bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
template<class T, class Container>
bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
template<class T, class Container>
bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
template<class T, class Container>
bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
}

template<class T, class Container>
bool ft::operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs.c == rhs.c);
}

template<class T, class Container>
bool ft::operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs.c != rhs.c);
}

template<class T, class Container>
bool ft::operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs.c <= rhs.c);
}

template<class T, class Container>
bool ft::operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs.c >= rhs.c);
}

template<class T, class Container>
bool ft::operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs.c < rhs.c);
}

template<class T, class Container>
bool ft::operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
{
	return (lhs.c > rhs.c);
}

template<class T, class Container>
ft::stack<T, Container>::stack(const Container &cont) : c(cont)
{
	//this->c = cont;
}

template<class T, class Container>
ft::stack<T, Container>::stack(const stack &other)
{
	*this = other;
}

template<class T, class Container>
ft::stack<T, Container>::~stack()
{
	
}

template<class T, class Container>
ft::stack<T, Container> &ft::stack<T, Container>::operator=(const stack &other) 
{
	this->c = other.c;
	return (*this);
}

template<class T, class Container>
typename ft::stack<T, Container>::reference ft::stack<T, Container>::top()
{
	return(this->c.back());
}

template<class T, class Container>
typename ft::stack<T, Container>::const_reference ft::stack<T, Container>::top() const
{
	return(this->c.back());
}

template<class T, class Container>
bool ft::stack<T, Container>::empty() const
{
	return(this->c.empty());
}

template<class T, class Container>
void ft::stack<T, Container>::push(const ft::stack<T, Container>::value_type &value)
{
	c.push_back(value);
}

template<class T, class Container>
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size() const
{
	return (this->c.size());
}

template<class T, class Container>
void ft::stack<T, Container>::pop()
{
	this->c.pop_back();
}
#endif