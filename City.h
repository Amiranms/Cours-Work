#pragma once
#include "Inf_segment.h"

class City//класс,необходимый исключительно дл€ хранени€ названи€ городов.
{//он потребуетс€ нам впоследствии,когда необходимо будет узнать,в какие города способна летать наша авиакомпани€ 
private:
	string c_name;
public:
	City();

	City(const string& name);

	void cSetN(const string& name);

	string cGetN() const;
};