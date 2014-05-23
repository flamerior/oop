#ifndef SQUARE_H
#define SQUARE_H

#include "Point.h"
#include "Shape.h"
#include "Printable.h"

class Square : public Shape, public Printable
{
	public:

        Square( ) : Shape("Square")
		{
			height = rand() % 100 + 1;
		}

		virtual ~Square( )
		{ }

		virtual string Print() const
		{
            string str = Shape::name + "\n";
            str += "TopLeft : {" + topleft.Print() + "}" +
                    "Height : " + NumberToString(height) + "}\n";

			return str;
		}

		//friend std::ostream & operator<<(std::ostream & s, Square const & pt);

	protected:

        Point topleft;
		int height;

};


#endif
