#include <stdio.h>
#include <string>
#include <iostream>
#include "xlist.cpp"
#include "Figures.h"
#include "Printable.h"
using namespace std;

int main()
{
    XList<Printable*> list;
    Printable* fig;
    // Create randomly filled list of shape
    for(int i = 0; i < 10; i++)
    {
        int index = rand() % 5;
        switch(index)
        {
            case 0:
                fig = new Point();
                break;
            case 1:
                fig = new Circle();
                break;
            case 2:
                fig = new Square();
                break;
            case 3:
                fig = new Rect();
                break;
            case 4:
                fig = new Polyline();
                break;
        }
        list.AddLast(fig);
    }

    cout << Shape::GetCount() << "\n";

    XListIterator<Printable*> end = list.GetEndFWIter();
    for(XListIterator<Printable*> it = list.GetStartFWIter(); it != end; it++)
        cout << it->elem->Print() << "\n";

    for(XListIterator<Printable*> it = list.GetStartFWIter(); it != end; it++)
        delete(it->elem);

//    list.Clear();

    cout << Shape::GetCount() << "\n";

    try
    {
        list.GetFirst();
    }
    catch(EmptyListException)
    {
        EmptyListException::Print();
    }

}
