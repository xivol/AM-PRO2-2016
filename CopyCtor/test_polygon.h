//
// ������������ ������ �7. ������. ����������� ����� � �������� ������������
// test_polygon.h
//
#pragma once
#include "polygon.h"

class test_polygon
{
    // ������� ��������� ������� ��������� �����
    point *get_points(const size_t length);
    
    //
    // ����������� �������
    //

    // ���� ��� �������
    // polygon::copy(const point *from, point *to, const size_t size)
    bool copy();

    // ���� ��� �������
    // polygon::polygon(const point *points, const size_t size)
    bool points_ctor();
public:
    static bool run();
};