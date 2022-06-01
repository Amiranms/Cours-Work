#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <map>

using namespace std;
class Inf_segment//����� ��������������� ������� ���������� �� ����� ���������,��� ����������� ��������� � ������� �������� ����� ����� ��������
{
private:
	char i_existing;//the flight exists or not
	unsigned i_hours;//���������� �����,������� �������� �������� � ������
	unsigned i_min;//������,<60
	double i_cost;//��������� ��������
public:
	Inf_segment();//����������� �� ��������� 

	Inf_segment(unsigned h, unsigned m, double c);

	//����� ����������� ����� ������� � ������� 
	void iSetH(unsigned h);

	void iSetM(unsigned m);

	void iSetC(double c);

	void iSetE(char e);
	unsigned iGetH() const;

	unsigned iGetM() const;

	double iGetC() const;

	char iGetE() const;

	Inf_segment& operator = (const Inf_segment& right);//���������� ��������� ������������ ��� �������;

	Inf_segment& operator + (Inf_segment& right) const;//�������� �������� ���� ��� ���������;

	int iGetT() const;

	~Inf_segment(); 
};
