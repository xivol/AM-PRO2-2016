//
// Лабораторная работа №14. Абстрактные типы данных. Стек
// stack.h
//
#pragma once
#include <iostream>
#include "dyn_array.h"

// Абстрактный стек
class stack 
{
public:
    typedef int datatype;
    virtual ~stack() = 0;

    // Проверка на пустоту
    virtual bool is_empty() = 0;

    // Добавление элемента на стек
    virtual void push(const datatype &x) = 0;

    // Изъятие элемента со стека
    virtual void pop() = 0;

    // Просмотр вершины стека
    virtual datatype top() = 0;
};

// Стек на базе массива
class d_stack : public stack
{
    dyn_array data;
public:
    // Т.к. класс dyn_array имеет все необходимые методы,
    // здесь можно оставить конструкторы и деструктор по умолчанию

    bool is_empty();
    void push(const datatype &x);
    void pop();
    datatype top();

    friend std::ostream &operator<<(std::ostream &os, const d_stack &s);
    friend class test_d_stack;
};

// Стек на базе списка
class l_stack : public stack
{
    // Узел списка
    struct node
    {
        datatype data;
        node * next;
    };

    // Начало списка
    node *begin;
public:
    l_stack();

    l_stack(const l_stack &s);
    l_stack &operator=(const l_stack &s);

    ~l_stack();

    bool is_empty();
    void push(const datatype &x);
    void pop();
    datatype top();

    friend std::ostream &operator<<(std::ostream &os, const l_stack &s);
};
