#include "City.h"

City::City()
{
	c_name = "default city";
	//cout << "New city constructed";
}

City::City(const string& name) : c_name(name)
{
	//cout << "New city constructed";
}

void City::cSetN(const string& name)
{
	c_name = name;

}
string City::cGetN() const
{
	return c_name;
}