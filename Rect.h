#ifndef RECT_H
#define RECT_H

#include "Square.h"

class Rect : public Square
{
	public:

		Rect( ) : Square( )
		{
            Shape::name = "Rectangle";
			width = rand() % 100 + 1;
		}

		string Print() const
		{
            string str = Shape::name + "\n{\n";
            str += "TopLeft : {" + topleft.Print() + "}" +
                "Height : " + NumberToString(height) +
                " Width : " + NumberToString(width);
            str += "}\n";

			return str;
		}

	private:
   
		int width;
};


#endif
