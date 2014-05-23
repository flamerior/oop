#ifndef POINT_H
#define POINT_H

#include "Shape.h"
#include "Printable.h"
#include <stdlib.h>

class Point : public Shape, public Printable 
{
	public:

        Point() : Shape("Point")
		{
			x = rand() % 100 + 1;
			y = rand() % 100 + 1;
		}

		string Print() const
		{
            string str = Shape::name +
                "(" + NumberToString(x) +
                " ," + NumberToString(y);
            str += ")\n";

			return str;
		}

	private:

		int x;
		int y;
};


#endif
