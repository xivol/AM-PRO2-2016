//
// Лабораторная работа №1. Двусвязный список
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
        throw "Невозможно открыть файл";

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

void sort(llist *&begin, llist *&end)
{
    llist *current = begin->next;
    while (current != end->next) {        
        llist *insert_after = current->prev;        
        while (insert_after != nullptr && insert_after->data >= current->data) {
            insert_after = insert_after->prev;
        }

        llist *cur_next = current->next;
        if (insert_after != current->prev) {
            
            if (current->prev != nullptr)
                current->prev->next = current->next;
            else
                begin = current->next;
            if (current->next != nullptr)
                current->next->prev = current->prev;
            else
                end = current->prev;

            if (insert_after != nullptr) {
                llist *insert_to = insert_after->next;
                current->next = insert_to;
                current->prev = insert_to->prev;
                if (insert_to->prev != nullptr)
                    insert_to->prev->next = current;
                insert_to->prev = current;
            }
            else {
                current->next = begin;
                current->prev = nullptr;
                begin->prev = current;
                begin = current;
            }
        }
        current = cur_next;
    }
}