#ifndef PRINTABLE_H
#define PRINTABLE_H

#include "Named.h"

class Printable : public Named
{
	public:

		Printable() : Named("")
		{ }

		Printable(string const & value) : Named(value)
		{ }

		~Printable()
		{ }

		virtual string Print() const
		{
			return name + "\n";
		}
    private:
		friend std::ostream & operator<<(ostream & s, Printable const & pt);
};

std::ostream & operator<<(std::ostream & s, Printable const & pt)
{
	s << pt.Print();
	return s;
}
#endif
