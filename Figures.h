#include "Point.h"
#include "Square.h"
#include "Rect.h"
#include "Shape.h"
#include "Printable.h"
#include <stdlib.h>


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

