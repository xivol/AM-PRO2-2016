//
// ������������ ������ �13. ������. ����������� �����
// polygon.h
//
#pragma once
#include "point.h"
#include "shape.h"

class polygon: public shape
{
protected:
    // ����� �����
    point *points;
    // ����� �������
    size_t size;

    // ��������������� ������� ����������� ������� �����
    void copy(const point *from, point *to, const size_t size);

    // �������� ����������� ��� ����������
    polygon();
public:
    // ����������� �� ������� �����
    polygon(const point *points, const size_t size);
    polygon::polygon(const polygon &p);
    polygon &operator=(const polygon &p);

    // ����������
    ~polygon();   

    // �����
	void print(std::ostream &os = std::cout) const;

    friend class test_polygon;
};
