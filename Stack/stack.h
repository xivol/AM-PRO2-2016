//
// ������������ ������ �14. ����������� ���� ������. ����
// stack.h
//
#pragma once
#include <iostream>
#include "dyn_array.h"

// ����������� ����
class stack 
{
public:
    typedef int datatype;
    virtual ~stack() = 0;

    // �������� �� �������
    virtual bool is_empty() = 0;

    // ���������� �������� �� ����
    virtual void push(const datatype &x) = 0;

    // ������� �������� �� �����
    virtual void pop() = 0;

    // �������� ������� �����
    virtual datatype top() = 0;
};

// ���� �� ���� �������
class d_stack : public stack
{
    dyn_array data;
public:
    // �.�. ����� dyn_array ����� ��� ����������� ������,
    // ����� ����� �������� ������������ � ���������� �� ���������

    bool is_empty();
    void push(const datatype &x);
    void pop();
    datatype top();

    friend std::ostream &operator<<(std::ostream &os, const d_stack &s);
    friend class test_d_stack;
};

// ���� �� ���� ������
class l_stack : public stack
{
    // ���� ������
    struct node
    {
        datatype data;
        node * next;
    };

    // ������ ������
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
