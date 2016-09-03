//
// ������������ ������ �1. ���������� ������
// llist.cpp
//
#include <cassert>
#include <iostream>
#include <fstream>
#include "crtdynmem.h"
#include "llist.h"

using namespace std;

llist *get_list(const char *filename, llist *&end)
{
    assert(filename != nullptr);
    llist *begin = nullptr;
    end = nullptr;

    ifstream fin(filename);
    if (!fin.is_open())
        throw "���������� ������� ����";

    llist::datatype data;
    while (fin >> data) {
        llist *node = new llist;
        node->data = data;
        node->next = nullptr;
        node->prev = end;

        if (begin == nullptr)
            begin = node;

        if (end != nullptr)
            end->next = node;
        end = node;
    }

    fin.close();
    return begin;
}


bool is_symmetrical(const llist *begin, const llist *end)
{
    assert(begin != nullptr);
    assert(end != nullptr);

    while (begin != end) {
        if (begin->data != end->data)
            return false;
        if (begin->next == end) 
            break;
        begin = begin->next;
        end = end->prev;
    }
    return true;
}