#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include "is_integral.hpp"
#include <vector>
#include <list>

//unsigned long long int pow2(int n);

namespace ft
{
	template <class Iter>
	struct iterator_traits;

	template<bool B, class T = void>
	struct enable_if;

	template<class T>
	struct is_integral;
/*
	template<class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2);

        template<class InputIterator1, class InputIterator2, class BinaryPredicate>
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred);

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2);

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp);
	*/
}

namespace ft
{
template<class Iter>
struct iterator_traits
{
	typedef typename Iter::difference_type difference_type;
	typedef typename Iter::value_type value_type;
	typedef typename Iter::pointer pointer;
	typedef typename Iter::reference reference;
	typedef typename Iter::iterator_category iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
	typedef std::ptrdiff_t difference_type;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef typename std::random_access_iterator_tag iterator_category;
};


template<class T>
struct iterator_traits<const T*>
{
	typedef std::ptrdiff_t difference_type;
	typedef T value_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef typename std::random_access_iterator_tag iterator_category;
};
}

namespace ft
{
template <class InputIterator1, class InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1;
		++first2;
	}
	return (true);
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
        while (first1 !=last1)
        {
                if (!(pred(*first1, *first2)))
                        return (false);
                ++first1;
                ++first2;
        }
        return (true);
}
}

namespace ft
{
template <class InputIterator1, class InputIterator2>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2==last2 || *first2 < *first1)
		{
			return (false);
		}
		else if (*first1<*first2)
		{
			return (true);
		}
		++first1;
		++first2;
	}
	return (first2 != last2);
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
        while (first1 != last1)
        {
                if (first2==last2 || comp(*first2, *first1))
                {
                        return (false);
                }
                else if (comp(*first1, *first2))
                {
                        return (true);
                }
                ++first1;
                ++first2;
        }
        return (first2 != last2);
}
}

namespace ft
{
template<bool B, class T>
struct enable_if 
{
};

template<class T>
struct enable_if<true, T>
{
	typedef T type;
};
}
#endif