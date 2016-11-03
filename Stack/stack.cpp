//
// Лабораторная работа №14. Абстрактные типы данных. Стек
// stack.cpp
//
#include "stack.h"

astract_stack::~astract_stack() {}

bool d_stack::is_empty()
{
    return data.count() == 0;
}

void d_stack::push(const datatype & x)
{
    data.append(x);
}

void d_stack::pop()
{
    if (is_empty()) return;    
    data.resize(data.count() - 1);
}

stack::datatype d_stack::top()
{
    if (is_empty()) 
        throw std::out_of_range("Попытка получить элемент из пустого стека");
    return data[data.count() - 1];
}
