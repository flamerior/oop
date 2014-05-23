#include <stdio.h>
#include <iostream>

template <class T>
struct Element
{
    Element* prev;
    T elem;
    Element* next;

    Element(T const & value)
    {
        prev = NULL;
        elem = value;
        next = NULL;
    }

    ~Element()
    {
        prev = NULL;
        next = NULL;
    }
};
