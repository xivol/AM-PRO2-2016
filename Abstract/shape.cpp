//
// ������������ ������ �13. ������. ����������� �����
// shape.cpp
//
#include "shape.h"

shape::~shape() {}

std::ostream & operator<<(std::ostream & os, const shape & s)
{
	s.print(os); // ��������� � ����������� ������� print
	return os;
}
