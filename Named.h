#ifndef NAMED_H
#define NAMED_H

#include <string>
using namespace std;
#include <sstream>

template <typename T>
  string NumberToString ( T Number )
  {
     ostringstream ss;
     ss << Number;
     return ss.str();
  }class Named
{
	public:

		Named(string const & value) : name(value)
		{ }

		virtual ~Named()
		{ }

	protected:

		string name;	

};

#endif
