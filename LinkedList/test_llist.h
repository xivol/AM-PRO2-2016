//
// ������������ ������ �15. ���������� ������
// test_llist.h
//
#pragma once
#include "llist.h"

// ���� ������� ������ ������ �� �����
bool test_get_llist_from_file();

// ������� ��������� �������-������ ��� ����������� ������
// ������� ���������:
//     array - ������ �������� ��������� ������;
//     length - ���������� ��������.
// ���������� ������ ��������� llist.
llist *get_array_llist(const llist::datatype *array, size_t length);

// ���� �������
// llist *get_array_llist(const llist::datatype *array, size_t length)
// �������� ��������� ����������� ������ � ��������.
bool test_get_array_llist();

// ���� �������
// bool is_symmetrical(const llist *begin, const llist *end)
// �������� ��� ������� ������ � �������� �����.
bool test_is_symmetrical();

// ������������ ���� ������� �� llist
bool test_llist_full();

// ��������� ������� ������������ ��������� ����������� ��������� ������ � ��������
// ������� ���������:
//     begin -  ��������� �� ������ ������;
//     array - ������ �������� ��������� ������;
//     length - ���������� ��������.
// ���������� true, ���� �������� � ������ ����� ��������� � �������.
template <typename List, typename List_Data>
bool is_equal_test(const List *begin, List_Data *array, size_t length)
{
    size_t count = 0;
    while (begin != nullptr && count < length) {
        // ���������� ���������� � ��������� �������
        assert(begin->data == array[count]);
        begin = begin->next;
        count++;
    }
    // ���������� ���������� ����������� � �������� �����������
    assert(count == length);
    return true;
}