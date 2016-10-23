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
    void delete_list()
    {
        while (begin != nullptr) {
            node *t = begin;
            begin = begin->next;
            delete t;
        }
    }

    // Копирование списка
    void copy_list(const node * l)
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

public:
    stack() : begin(nullptr) {}

    stack(const stack &s) : begin(nullptr)
    {
        copy_list(s.begin);
    }

    stack &operator=(const stack &s)
    {
        if (!is_empty()) delete_list();
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

    void push(const T &x)
    {
        node *t = new node;
        t->data = x;
        t->next = begin;
        begin = t;
    }

    void pop()
    {
        if (is_empty()) return;
        node *t = begin;
        begin = begin->next;
        delete t;
    }

    T top()
    {
        if (is_empty())
            throw std::out_of_range("Попытка извлечения из пустого стека!");
        return begin->data;
    }

    template <typename P>
    friend std::ostream &operator<<(std::ostream &os, const stack<P> &s);
};
