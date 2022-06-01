#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <map>

using namespace std;
class Inf_segment//класс предоставляющий сегмент информации он будет необходим,для определения стоимости и времени перелета между двумя городами
{
private:
	char i_existing;//the flight exists or not
	unsigned i_hours;//количество часов,которое пассажир проведет в полете
	unsigned i_min;//минуты,<60
	double i_cost;//стоимость перелета
public:
	Inf_segment();//конструктор по умолчанию 

	Inf_segment(unsigned h, unsigned m, double c);

	//далее стандартный набор сетеров и гетеров 
	void iSetH(unsigned h);

	void iSetM(unsigned m);

	void iSetC(double c);

	void iSetE(char e);
	unsigned iGetH() const;

	unsigned iGetM() const;

	double iGetC() const;

	char iGetE() const;

	Inf_segment& operator = (const Inf_segment& right);//перегрузка оператора присваивания инф сегмент;

	Inf_segment& operator + (Inf_segment& right) const;//операция сложения двух инф сегментов;

	int iGetT() const;

	~Inf_segment(); 
};
