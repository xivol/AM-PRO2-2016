//
// ������������ ������ �22. ����������� ���������� ��������. ��������� �������. ������ � ������������
// algorithms.h
//
#pragma once
#define GET_VALUE_TYPE()
#include <iostream>

// ������ ������� ������
template <typename Container>
void print(Container &container)
{
	// ������ �� ����������.
	// �������� ��� ������ ���� � ��������:
	// begin(), end().
	// � ����� ��� ����������� �������� T[N].
    for (const auto &value : container)
        std::cout << value << " ";
	std::cout << std::endl;
}

// ������ ������� ���������� �������� � ����������
template <typename Iterator>
auto min_value(const Iterator &begin, const Iterator &end)
{
	/*  ��� ������������� �������� 
	����������� ������������� �� ����� ����������.
	��� ��������, �.�. ��� �������� � ����������
	���������� ���������� ��� ������������� ��������.
	*/
	auto min = *begin;
	std::cout << typeid(min).name() << " : ";

    auto it = begin;
    for (++it; it != end; ++it)
        if (min > *it)
            min = *it;
    return min;
}

// ������ ������� ���������� ����� � ����������
template <typename Iterator, typename T = double>
T sum_value(const Iterator &begin, const Iterator &end) 
{
	/*  ��� ������������� �������� 
	�� ����� ���� �������� �������������, �.�.
	���� �������� � ���������� ����� ���� �� ���������� ���
	�������� ����� ��������.
	*/
	T sum = *begin;
	std::cout << typeid(sum).name() << " : ";

	auto it = begin;
	for (++it; it != end; ++it)
		sum += *it;
	return sum;
}