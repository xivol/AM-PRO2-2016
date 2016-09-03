//
// ������������ ������ �13. ������������ ��������� ������. ������
// tlist.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include "crtdynmem.h"
#include "tlist.h"

using namespace std;

tlist *get_list(size_t length)
{
    tlist *begin = nullptr;
    tlist *end = nullptr;

    while (length > 0) {
        tlist::datatype data;
        if (cin >> data) {  // ���� ������ ��� ������

            tlist *node = new tlist;
            node->data = data;
            node->next = nullptr;

            if (begin == nullptr)
                begin = node;

            if (end != nullptr)
                end->next = node;
            end = node;
        }
        length--;
    }

    return begin;
}

tlist *get_list(const char *filename)
{
    assert(filename != nullptr);
    tlist *begin = nullptr;
    tlist *end = nullptr;

    ifstream fin(filename);
    if (!fin.is_open())
        throw "���������� ������� ����";

    tlist::datatype data;
    while (fin >> data) {
        tlist *node = new tlist;
        node->data = data;
        node->next = nullptr;

        if (begin == nullptr)
            begin = node;

        if (end != nullptr)
            end->next = node;
        end = node;
    }

    fin.close();
    return begin;
}

void delete_list(tlist *&begin)
{
    while (begin != nullptr) {
        tlist *t = begin;
        begin = begin->next;
        delete t;
    }
}

void print(const tlist *begin)
{
    while (begin != nullptr) {
        cout << begin->data << ' ';
        begin = begin->next;
    }
    cout << endl;
}

// ������� begin ����������, ����� �������� ��� ������ �� ��������
tlist *find(const tlist *begin, tlist::datatype x)
{
    // ������� ������������� ���������
    // �.�. �� �����, ��� ���������� ������ �� ����������� tlist*
    tlist *t = const_cast<tlist *>(begin);
    
    while (t != nullptr) {
        if (t->data == x)
            break;
        t = t->next;
    }
    return t;
}