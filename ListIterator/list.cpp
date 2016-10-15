#include "list.h"

list::list()
{
    first = last = nullptr;
}

list::list(const list & l)
{
    copy_list(first, last, l.first, l.last);
}

list & list::operator=(const list & l)
{
    delete_list(first);
    copy_list(first, last, l.first, l.last);
    return *this;
}

list::~list()
{
    delete_list(first, last);
}

bool list::is_empty() const
{
    return first == nullptr &&last == nullptr;
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
        last->next = nullptr;
        last->prev = nullptr;
        first = last;
    }
    else {
        last->next = new node;
        last->next->prev = last;
        last = last->next;
    }
    last->data = x;    
}

void list::pop_back()
{
    if (last == nullptr) return;
    if (last->prev == nullptr) {
        delete last;
        last = nullptr;
        first = nullptr;
    }
    else {
        last = last->prev;
        delete last->next;
        last->next = nullptr;
    }
}

list::datatype list::back() const
{
    return last->data;
}

void list::push_front(const datatype & x)
{
    if (first == nullptr) {
        first = new node;
        first->next = nullptr;
        first->prev = nullptr;
        last = first;
    }
    else {
        first->prev = new node;
        first->prev->next = first;
        first = first->prev;
    }
    first->data = x;
}

void list::pop_front()
{
    if (first == nullptr)return;
    if (first->next == nullptr) {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else {
        first = first->next;
        delete first->prev;
        first->prev = nullptr;
    }
}

list::datatype list::front() const
{
    return first->data;
}

void list::copy_list(const node * from_first, const node * from_last, node *& to_first, node *& to_last)
{    
    to_first = nullptr;
    to_last = nullptr;
    node **to = &to_first;
    const node *from = from_first;
    while (from != from_last->next) {
        node *prev = *to;
        *to = new node;
        (*to)->prev = prev;
        (*to)->data = from->data;
        to = &(*to)->next;
        from = from->next;
    }
    (*to)->next = nullptr;
    to_last = *to;
}

void list::delete_list(node *& first, node *& last)
{
    while (first != last->next) {
        node *t = first;
        first = first->next;
        delete t;
    }
    first = nullptr;
    last = nullptr;
}
