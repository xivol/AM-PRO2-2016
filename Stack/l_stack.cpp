#include "crtdynmem.h"
#include "stack.h"

void l_stack::delete_list()
{
    while (begin!= nullptr) {
        node *t = begin;
        begin = begin->next;
        delete t;
    }
}

void l_stack::copy_list(const node * l)
{
    node * p = nullptr;
    while (l != nullptr) {
        node *t = new node;
        t->data = l->data;
        t->next = nullptr;

        if (p != nullptr)
            p->next = t;
        else {
            p = t;
            begin = t;
        }
        p = p->next;
        l = l->next;
    }
}

l_stack::l_stack(): begin(nullptr) {}

l_stack::l_stack(const l_stack & s) : begin(nullptr)
{
    copy_list(s.begin);
}

l_stack & l_stack::operator=(const l_stack & s)
{
    if (! is_empty())
        delete_list();
    copy_list(s.begin);
    return *this;
}

l_stack::~l_stack()
{
    delete_list();
}

bool l_stack::is_empty()
{
    return begin == nullptr;
}

void l_stack::push(const datatype & x)
{
    node *t = new node;
    t->data = x;
    t->next = begin;
    begin = t;
}

void l_stack::pop()
{
    if (is_empty())
        return;
    node *t = begin;    
    begin = begin->next;
    delete t;
}

l_stack::datatype l_stack::top()
{
    if (is_empty())
        throw std::out_of_range("Просмотр пустого стека!");
    return begin->data;
}
