#include "xlistiterator.cpp"
#include <iostream>

class EmptyListException
{
    public:

        static void Print()
        {
            std::cout << "Exception : empty list";
        }
};

template <class T>
class XList
{
    public:
        XList();
        ~XList();
        void Clear();
        void AddFirst(T const & value);
        void AddLast(T const & value);
        void DeleteFirst();
        void DeleteLast();
        T & GetFirst() const;
        T & GetLast() const;
        int GetCount() const;
        bool IsEmpty() const;
        XListIterator<T> GetStartFWIter() const;
        XListIterator<T> GetEndFWIter() const;
        XListIterator<T> GetStartBWIter() const;
        XListIterator<T> GetEndBWIter() const;
    private:
        Element<T>* head;
        Element<T>* tail;
        int count;

};


template <class T>
XList<T>::XList()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template <class T>
XList<T>::~XList()
{
    Clear();
}

template <class T>
void XList<T>::Clear()
{
    while(head != NULL || tail != NULL)
        DeleteFirst();
}

template <class T>
void XList<T>::AddFirst(T const & value)
{
    Element<T>* node = new Element<T>(value);
    count++;

    if(head == NULL)
    {
        node->next = NULL;
        node->prev = NULL;
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        node->prev = NULL;
        head->prev = node;
        head = node;

    }
}

template <class T>
void XList<T>::AddLast(T const & value)
{
    Element<T>* node = new Element<T>(value);
    count++;

    if(head == NULL)
    {
        node->next = NULL;
        node->prev = NULL;
        head = node;
        tail = node;
    }
    else
    {
        node->next = NULL;
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

template <class T>
void XList<T>::DeleteFirst()
{
    if(head != NULL)
    {
        count--;

        if(head != tail)
        {
            Element<T>* help = head;
            head = head->next;
            head->prev = NULL;
            delete help;
        }
        else
        {
            delete head;
            tail = NULL;
            head = NULL;
        }
    }
}

template <class T>
void XList<T>::DeleteLast()
{
    if(head != NULL)
    {
        count--;

        if(head != tail)
        {
            Element<T>* help = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete help;
        }
        else
        {
            delete head;
            tail = NULL;
            head = NULL;
        }
    }
}

template <class T>
T & XList<T>::GetFirst() const
{
    if(IsEmpty())
        throw EmptyListException();
    else
        return head->elem;
}

template <class T>
T & XList<T>::GetLast() const
{
    if(IsEmpty())
        throw EmptyListException();
    else
        return tail->elem;
}

template <class T>
int XList<T>::GetCount() const
{
    return count;
}

template <class T>
bool XList<T>::IsEmpty() const
{
    bool is = false;
    if(head == NULL && tail == NULL)
        is = true;

    return is;
}

template <class T>
XListIterator<T> XList<T>::GetStartFWIter() const
{
    return XListIterator<T>(head);
}

template <class T>
XListIterator<T> XList<T>::GetEndFWIter() const
{
    return XListIterator<T>(NULL);
}

template <class T>
XListIterator<T> XList<T>::GetStartBWIter() const
{
    return XListIterator<T>(tail);
}

template <class T>
XListIterator<T> XList<T>::GetEndBWIter() const
{
    return XListIterator<T>(NULL);
}



