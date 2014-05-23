#ifndef POLYLINE_H
#define POLYLINE_H

#include "Point.h"
#include "Shape.h"
#include <stdlib.h>

class Polyline : public Shape, public Printable
{
	public:

        Polyline() : Shape("Polyline")
		{
			int numberOfPeaks = rand() % 20 + 1;

			for(int i = 0; i < numberOfPeaks; i++)
			{
				Point pt;
				AddPoint(pt);
			}
		}

		void AddPoint(Point const & pt)
		{
            knots.AddLast(pt);
		}

		string Print() const
		{
			string str;

            str = Shape::name + "\n{  \n";
            XListIterator<Point> itend = knots.GetEndFWIter();
            for(XListIterator<Point> it = knots.GetStartFWIter(); it != itend; it++)
			{
				str += it->elem.Print();
			}
            str += "}\n";

			return str;
		}
	private:

        XList<Point> knots;

};

#endif
