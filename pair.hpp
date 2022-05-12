#ifndef PAIR_HPP
#define PAIR_HPP
namespace ft
{
template <class T1, class T2>
struct pair
{
	public:

	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;
	
	//Constructor
	pair();
	pair(const T1 &x, const T2 &y);
	template <class U1, class U2>
	pair(const pair<U1, U2> &p);

	pair(const pair<T1, T2> &p);

	pair &operator=(const pair &other);
	pair make_pair(T1 t, T2 u);

};
template <class T1, class T2> 
ft::pair<T1, T2> make_pair(T1 t, T2 u)
{
	return(ft::pair<T1, T2>(t, u));
}
template<class T1, class T2>
bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs);
template<class T1, class T2>
bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs);
template<class T1, class T2>
bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs);
template<class T1, class T2>
bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs);
template<class T1, class T2>
bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs);
template<class T1, class T2>
bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs);
}

template<class T1, class T2>
ft::pair<T1, T2>::pair()
{
	return ;
}

template<class T1, class T2>
ft::pair<T1, T2>::pair(const T1 &x, const T2 &y) : first(x), second(y)
{
	return ;
}

template<class T1, class T2>
template<class U1, class U2>
ft::pair<T1, T2>::pair(const ft::pair<U1, U2> &p) : first(p.first), second(p.second)
{
	return ;
}

template<class T1, class T2>
ft::pair<T1, T2>::pair(const ft::pair<T1, T2> &p) : first(p.first), second(p.second)
{
	return ;
}

template<class T1, class T2>
ft::pair<T1, T2> &ft::pair<T1, T2>::operator=(const ft::pair<T1, T2> &other)
{
	this->first = other.first;
	this->second = other.second;

	return (*this);
}

template<class T1, class T2>
bool ft::operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	if (lhs.first == rhs.first && lhs.second == rhs.second)
		return (true);
	return (false);
}

template<class T1, class T2>
bool ft::operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	if (lhs.first != rhs.first || lhs.second != rhs.second)
		return (true);
	return (false);
}

template<class T1, class T2>
bool ft::operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	if (lhs.first == rhs.first)
	{
		if (lhs.second < rhs.second)
			return (true);
		else
			return (false);
	}
	else
	{
		if (lhs.first < rhs.first)
			return (true);
		else
			return (false);
	}
}

template<class T1, class T2>
bool ft::operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	if (lhs.first == rhs.first)
	{
		if (lhs.second > rhs.second)
			return (true);
		else
			return (false);
	}
	else
	{
		if (lhs.first > rhs.first)
			return (true);
		else
			return (false);
	}
}

template<class T1, class T2>
bool ft::operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	if (lhs.first == rhs.first)
	{
		if (lhs.second >= rhs.second)
			return (true);
		else
			return (false);
	}
	else
	{
		if (lhs.first >= rhs.first)
			return (true);
		else
			return (false);
	}
}

template<class T1, class T2>
bool ft::operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
{
	if (lhs.first == rhs.first)
	{
		if (lhs.second <= rhs.second)
			return (true);
		else
			return (false);
	}
	else
	{
		if (lhs.first <= rhs.first)
			return (true);
		else
			return (false);
	}
}
#endif