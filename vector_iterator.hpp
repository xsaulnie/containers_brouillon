#ifndef VEC_ITER
#define VEC_ITER

namespace ft
{
template<class T>
class vector_iterator
{
    protected:
        T*  ptr;
    public:
        typedef size_t difference_type;
        typedef T       value_type;
        typedef T*      pointer;
        typedef T&      reference;
        typedef std::random_access_iterator_tag iterator_category iterator_category;

        vector_iterator();
        vector_iterator(pointer ptr);
        vector_iterator(const vector_iterator &cpy);
        vector_iterator &operator=(const vector_iterator &rhs);

        vector_iterator &operator++();
        vector_iterator operator++(int);
        vector_iterator &operator--();
        vector_iterator operator--(int);

        pointer getptr() const;


};
}

template<class T>
ft::vector_iterator<T>::vector_iterator()
{
    this->ptr = NULL;
}

template<class T>
ft::vector_iterator<T>::vector_iterator(vector_iterator<T>::pointer ptr)
{
    this->ptr = ptr;
}

ft::vector_iterator<T>::vector_iterator(const vector_iterator<T> &cpy)
{
    *this = cpy;
    return ;
}

template<class T>
ft::vector_iterator<T> &vector_iterator<T>::operator=(const vector_iterator<T> &rhs)
{
    this->ptr = rhs.getptr();
    return (*this);
}

template<class T>
ft::vector_iterator<T> &ft::vector_iterator<T>::operator++()
{
    (this->ptr)++;
    return (*this);
}

template<class T>
ft::vector_iterator<T> ft::vector_iterator<T>::operator++(int)
{
    vector_iterator tmp;

    tmp = *this;
    (this->ptr)++;
    return (tmp);
}

template<class T>
ft::vector_iterator<T> &ft::vector_iterator<T>::operator--()
{
    (this->ptr)--;
    return (*this);
}

template<class T>
ft::vector_iterator<T> ft::vector_iterator<T>::operator--(int)
{
    vector_iterator tmp;

    tmp = *this;
    (this->ptr)--;
    return (tmp);
}

template<class T>
ft::vector_iterator<T> ft::vector_iterator<T>::getptr() const
{
    return (this->ptr);
}

#endif