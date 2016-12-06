//
// ������������ ������ �25. ����������� ���������� ��������. ������-���������
// main.cpp
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    char *a = "Hello";
    char *b = "World";
    cout << a << ", " << b << "!" << endl;

    // ������-��������� - ���������� �������,
    // ����������� � ����

    // ����� ��������

    // ������ � �����������
    auto swap1 = [](char *&i, char *&j) { char *t = i; i = j; j = t; };
    swap1(a, b);
    cout << "Lambda 1:\t" << a << ", " << b << "!" << endl;
    
    // ������ � �������� ������� ���������� �� ������
    auto swap2 = [&a,&b]() { auto t = a; a = b; b = t; };
    swap2();
    cout << "Lambda 2:\t" << a << ", " << b << "!" << endl;

    // ������ � �������� �� ������ ���� ���������� ���������    
    auto swap3 = [&]() { auto t = a; a = b; b = t; };
    swap3();
    cout << "Lambda 3:\t" << a << ", " << b << "!" << endl;

    // ������ � �������� �� �������� � ������������ �������� �����
    auto swap4 = [=]() mutable { auto t = a; a = b; b = t; }; // ������!
    // mutable ������� �����������, ��� ������� ���������� ����������� �� ��������
    // ����� ����������� ����� ��������
    swap4();
    cout << "Lambda 4:\t" << a << ", " << b << "!" << endl;

    // ��������� ������ ���������� ����������,
    // �� �������������� ������� �������
    vector<int> v(5);
    generate(v.begin(), v.end(), [&v]() { return rand() % v.size(); });

    // ��������� ����� �������� �������
    int sum = 0;
    for_each(v.begin(), v.end(), [&sum](const auto &a) { sum += a; });
    
    // ����� � ������� for_each
    for_each(v.begin(), v.end() - 1, [](const auto &a) { cout << a << " + "; });
    cout << v.back() << " = " << sum << endl;

    system("pause");
    return 0;
}