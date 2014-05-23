#ifndef X_LIST_ITERATOR_CPP
#define X_LIST_ITERATOR_CPP

#include "element.cpp"

template <class T>
class XListIterator
{
    public:
        XListIterator();
        XListIterator(Element<T>* value);
        Element<T>* operator->();
        XListIterator<T> operator++();
        XListIterator<T> operator++(int);
        XListIterator<T> operator--();
        XListIterator<T> operator--(int);
        bool operator!=(XListIterator const & value);
    private:
        Element<T>* current;
};

template <class T>
XListIterator<T>::XListIterator()
{
    current = NULL;
}

template <class T>
XListIterator<T>::XListIterator(Element<T>* node)
{
    current = node;
}

template <class T>
Element<T>* XListIterator<T>::operator->()
{
    return current;
}

template <class T>
XListIterator<T> XListIterator<T>::operator++()
{
    current = current->next;
    return XListIterator(current);
}

template <class T>
XListIterator<T> XListIterator<T>::operator++(int)
{
    Element<T>* tmp = current;
    current = current->next;
    return XListIterator(tmp);
}

template <class T>
XListIterator<T> XListIterator<T>::operator--()
{
    current = current->prev;
    return XListIterator(current);
}

template <class T>
XListIterator<T> XListIterator<T>::operator--(int)
{
    Element<T>* tmp = current;
    current = current->prev;
    return XListIterator(tmp);
}

template <class T>
bool XListIterator<T>::operator!=(XListIterator const & value)
{
    return !(current == value.current);
}



#endif
