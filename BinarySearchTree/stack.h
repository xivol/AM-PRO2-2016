#pragma once
//
// Лабораторная работа №14. Абстрактные типы данных. Стек
// stack.h
//
#pragma once
#include <iostream>

// Стек на базе списка
// T - тип данных в списке
template <typename T>
class stack
{
    // Узел списка
    struct node
    {
        T data;
        node * next;
    };

    // Начало списка
    node *begin;

    // Удаление списка
    void delete_list();
    // Копирование списка
    void copy_list(const node * l);
public:
    stack() : begin(nullptr) {}

    stack(const stack &s) : begin(nullptr)
    {
        copy_list(s.begin);
    }

    stack &operator=(const stack &s)
    {
        delete_list();
        copy_list(s.begin);
    }

    ~stack()
    {
        delete_list();
    }

    bool is_empty()
    {
        return begin == nullptr;
    }

    // Добавление значения в стек
    void push(const T &x);

    // Извлечение с вершины стека
    void pop();

    // Просмотр вершины стека
    T top();

    template <typename P>
    friend std::ostream &operator<<(std::ostream &os, const stack<P> &s);
};

template <typename T>
void stack<T>::delete_list()
{
    while (begin != nullptr) {
        node *t = begin;
        begin = begin->next;
        delete t;
    }
}

template <typename T>
void stack<T>::copy_list(const node * l)
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

template <typename T>
void stack<T>::push(const T &x)
{
    node *t = new node;
    t->data = x;
    t->next = begin;
    begin = t;
}

template <typename T>
void stack<T>::pop()
{
    if (is_empty()) return;
    node *t = begin;
    begin = begin->next;
    delete t;
}

template <typename T>
T stack<T>::top()
{
    if (is_empty())
        throw std::out_of_range("Попытка извлечения из пустого стека!");
    return begin->data;
}

template <typename P>
std::ostream &operator<<(std::ostream &os, const stack<P> &s)
{
    stack<P>::node *t = s.begin;
    while (t != nullptr) {
        os << t->data << ' ';
        t = t->next;
    }
    return os;
}
