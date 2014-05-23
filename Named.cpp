#include "Named.h"
#include <iostream>
#include "Printable.h"
string Printable::Print() const
{
	return name + "\n";
}

string Shape::GetCount()
{
	return "\nCount_of_figures : " + to_string(count) + "\n";
}

int Shape::count = 0;
