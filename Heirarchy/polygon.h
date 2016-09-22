//
// ������������ ������ �8. ������. ������������
// polygon.h
//
#pragma once
#include "point.h"

class polygon
{
protected:
    // ����� �����
    point *points;
    // ����� �������
    size_t size;

    // ��������������� ������� ����������� ������� �����
    void copy(const point *from, point *to, const size_t size);

    // �������� ����������� ��� ����������
    // ����� ���� ����������� � ������������� ������� � ��������
    // � ����� � �����������
    polygon();
public:
    // ����������� �� ������� �����
    polygon(const point *points, const size_t size);

    // ����������
    ~polygon();

    double area() const;

    friend class test_polygon;
};