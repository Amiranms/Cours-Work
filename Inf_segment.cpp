#include "Inf_segment.h"
Inf_segment::Inf_segment(): i_hours(0), i_min(0), i_cost(0.0), i_existing('0')
{
	//cout << endl << "Information segment created " << endl;
}

Inf_segment::Inf_segment(unsigned h, unsigned m, double c) : i_hours(h), i_cost(c), i_existing(1)
{
	if (m > 59) {
		i_hours += m / 60;
		i_min = m % 60;
	}
	else
		i_min = m;


	//cout << endl << "Information segment created " << endl;
}

 void Inf_segment::iSetH(unsigned h)
{
	i_hours = h;
}

void Inf_segment::iSetM(unsigned m)
{
	if (m > 59) {
		i_hours += m / 60;
		i_min = m % 60;
	}
	else
		i_min = m;

}

void Inf_segment::iSetC(double c)
{
	if (c >= 0)
		i_cost = c;
	else
		cout << "invalud value" << endl;
}

void Inf_segment::iSetE(char e)
{
	if (e == '0' || e == '1')
		i_existing = e;
	else
		cout << "invalid value" << endl;
}

unsigned Inf_segment::iGetH() const
{
	return i_hours;
}

unsigned Inf_segment::iGetM() const
{
	return i_min;
}

double Inf_segment::iGetC() const
{
	return i_cost;
}
char Inf_segment::iGetE() const
{
	return i_existing;
}

Inf_segment& Inf_segment::operator = (const Inf_segment& right)//перегрузка оператора присваивания инф сегмент
{
	this->iSetE(right.iGetE());
	this->iSetC(right.iGetC());
	this->iSetH(right.iGetH());
	this->iSetM(right.iGetM());
	return *(this);
}

Inf_segment& Inf_segment::operator + (Inf_segment& right) const//операция сложения двух инф сегментов
{//мы надеемся на 'hook' Дениса Васильевича 
	Inf_segment* cur = new Inf_segment;
	cur->iSetE(right.iGetE());
	cur->iSetC(iGetC() + right.iGetC());
	cur->iSetH(iGetH() + right.iGetH());
	cur->iSetM(iGetM() + right.iGetM());
	return *cur;
}

int Inf_segment::iGetT() const
{
	return (iGetH() * 60 + iGetM());
}

Inf_segment::~Inf_segment() {}
