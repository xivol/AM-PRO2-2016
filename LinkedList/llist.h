//
// ������������ ������ �15. ���������� ������
// llist.h
//
#pragma once

// ���� ����������� ������:
//     llist::datatype - ��� ������ ������;
//     data - �������� � ���� ������;
//     prev - ��������� �� ���������� �������;
//     next - ��������� �� ��������� �������.
struct llist
{
    typedef int datatype;
    datatype data;
    llist *prev;
    llist *next;
};

// ������� �������� ����������� ������ �� ������ ������������.
// ������� ���������:
//     filename - ��� ����� ������.
// �������� ��������:
//     end - ��������� �� ����� ������.
// ���������� ��������� �� ������ ������� ������ ������.
llist *get_list(const char *filename, llist *&end);

// ������� �������� ����������� ������ �� ��������������.
// ������� ���������:
//     begin - ��������� �� ������ ������;
//     end - ��������� �� �����������.
// ���������� true, ���� ������ �����������.
bool is_symmetrical(const llist *begin, const llist *end);

// ��������� ������� �������� ��������� ������.
// ������� ���������:
//     begin - ��������� �� ������ ������.
// �������� �������� ��������� begin ����� nullptr.
template <typename List>
void delete_list(List *&begin)
{
    while (begin != nullptr) {
        List *t = begin;
        begin = begin->next;
        delete t;
    }
}

// ��������� ������� ������ ��������� ������ �� �������.
// ������� ���������:
//     begin - ��������� �� ������ ������.
template <typename List>
void print_list(const List *begin) 
{
    while (begin != nullptr) {
        cout << begin->data << ' ';
        begin = begin->next;
    }
    cout << endl;
}