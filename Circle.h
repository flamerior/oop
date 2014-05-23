#include "Shape.h"
#include "Printable.h"
#include "Point.h"

class Circle : public Shape, public Printable
{
	
	public:

        Circle() : Shape("Circle")
		{
            radius = rand() % 100;
		}

		string Print() const
		{
            string str = Shape::name +
                    "{ Center : "+center.Print()+
                    "Radius : " + NumberToString(radius) + "}\n";

			return str;
		}

    private:

		Point center;
		int radius;

};

