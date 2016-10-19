//
// Лабораторная работа №15. Абстрактные типы данных. Список с внешним итератором
// list.cpp
//
#include "list.h"

void list::copy_list(const node * from_first, const node * from_last)
{
    first = nullptr;
    last = nullptr;
    node **to = &first;
    const node *from = from_first;
    while (from != from_last->next) {
        node *prev = *to;
        *to = new node;
        (*to)->prev = prev;
        (*to)->data = from->data;
        to = &(*to)->next;
        from = from->next;
    }
    *to = nullptr;
    last = *to;
}

void list::delete_list()
{
    while (first != last) {
        node *t = first;
        first = first->next;
        delete t;
    }
    delete last;
    first = nullptr;
    last = nullptr;
}

list::list()
{
    first = last = nullptr;
}

list::list(const list & l)
{
    copy_list(l.first, l.last);
}

list & list::operator=(const list & l)
{
    delete_list();
    copy_list(l.first, l.last);
    return *this;
}

list::~list()
{
    delete_list();
}

size_t list::size() const
{
    size_t sz = 0;
    node *t = first;
    while (t) {
        sz++;
        t = t->next;
    }
    return sz;
}

void list::push_back(const datatype & x)
{
    if (last == nullptr) {
        last = new node;
        last->prev = nullptr;
        first = last;
    }
    else {
        last->next = new node;
        last->next->prev = last;        
        last = last->next;
    }
    last->data = x;    
    last->next = nullptr;
}

list::datatype list::back() const
{
    if (is_empty())
        throw std::out_of_range("Попытка доступа к элементу пустого списка");
    return last->data;
}

std::ostream &operator<<(std::ostream &os, list &l)
{
    for (list::iterator i = l.begin(); i != l.end(); ++i) {
		os << *i << std::endl;
    }
    return os;
}