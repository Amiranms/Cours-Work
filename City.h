#pragma once
#include "Inf_segment.h"

class City//�����,����������� ������������� ��� �������� �������� �������.
{//�� ����������� ��� ������������,����� ���������� ����� ������,� ����� ������ �������� ������ ���� ������������ 
private:
	string c_name;
public:
	City();

	City(const string& name);

	void cSetN(const string& name);

	string cGetN() const;
};