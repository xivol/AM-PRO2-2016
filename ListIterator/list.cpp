#include "list.h"

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
        last = first;
    }
    else {
        first->prev = new node;
        first->prev->next = first;
        first = first->prev;
    }
    first->data = x;
    first->prev = nullptr;
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
    (*to)->next = nullptr;
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

list::iterator list::begin()
{
    return iterator(this, first);
}

//list::const_iterator list::begin() const
//{
//    return const_iterator(this, first);
//}

list::iterator list::end()
{
    return iterator(this, nullptr);
}

//list::const_iterator list::end() const
//{
//    return const_iterator(this, nullptr);
//}

list::iterator::iterator(const list * collection, node * current) :
    current(current), collection(collection) 
{}

list::datatype & list::iterator::operator*()
{
    return current->data;
}

list::iterator & list::iterator::operator++()
{
    if (current == nullptr)
        throw std::out_of_range("Инкремент пустого итератора");
    current = current->next;
    return *this;
}

list::iterator list::iterator::operator++(int)
{
    if (current == nullptr)
        throw std::out_of_range("Инкремент пустого итератора");
    list::iterator it = *this;
    current = current->next;
    return it;
}

bool list::iterator::operator==(const iterator & it) const
{
    return it.collection == this->collection && it.current == this->current;
}

bool list::iterator::operator!=(const iterator & it) const
{
    return !(*this == it);
}


std::ostream &operator<<(std::ostream &os, list &l)
{
    for (list::iterator i = l.begin(); i != l.end(); ++i) {
        std::cout << *i << std::endl;
    }
}