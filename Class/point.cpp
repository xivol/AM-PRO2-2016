//
// ������������ ������ �4. ������. ���� � v�����
// point.cpp
//
#include <iostream>
#include "point.h"

point get_point()
{
    point p;
    std::cin >> p.x >> p.y;
    if (!std::cin)
        throw std::domain_error("������������ ���������� �����");
    return p;
}

void print(point p)
{
    std::cout << "( " << p.get_x() << ", " << p.get_y() << " )";
}
