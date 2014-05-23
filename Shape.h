#ifndef SHAPE_H
#define SHAPE_H

#include "Named.h"

class Shape : public Named
{
	public:

        Shape(string const & value) : Named(value)
		{
			count++;
		}

		virtual ~Shape()
		{
			count--;
		}

		static string GetCount()
		{
            return "\nCount_of_figures : " + NumberToString(count) + "\n";
		}

	private:

		static int count;

};

int Shape::count = 0;

#endif
