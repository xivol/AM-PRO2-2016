#pragma once
#include <iostream>
template <typename Datatype>
class list
{
public:

    list()
    {
        first = last = nullptr;
    }

    list(const list &l)
    {
        copy_list(l.first, l.last);
    }
    list &operator=(const list &l)
    {
        delete_list();
        copy_list(l.first, l.last);
        return *this;
    }
    ~list()
    {
        delete_list();
    }

    // ���������� ��������� � ������
    size_t size() const
    {
        size_t sz = 0;
        node *t = first;
        while (t) {
            sz++;
            t = t->next;
        }
        return sz;
    }

    // �������� ������ �� �������
    bool is_empty() const
    {
        return first == nullptr && last == nullptr;
    }

    // ���������� �������� � �����
    void push_back(const Datatype &x)
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
    // ���������� ���������� �������
    void pop_back();
    // ��������� ���������� ��������
    Datatype back() const;

    // ���������� �������� � ������
    void push_front(const Datatype &x);
    // ���������� ������� ��������
    void pop_front();
    // ��������� ������� ��������
    Datatype front() const;

    // ����������� �����
    friend class test_list;
private:
    // �������� ���� ������
    struct node
    {
        Datatype data;
        node *prev, *next;
    };

    // ������ � ����� ������
    node *first, *last;

    // ����� ��� ����������� ��������� �� ������� ������
    void copy_list(const node *from_first, const node *from_last)
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

    // ����� �������� ������
    void delete_list()
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
public:
    //
    // ������� ��������
    //

    // ����� ��������� ��������, ��� ���������� ���
    class iterator
    {

        // ��������� �� ���� ������
        node *current;

        // ��������� �� ������
        const list *collection;

        // �������� �����������
        // �������� ������ � ������������� ������� 
        iterator(const list *collection, node *current):
            collection(collection), current(current)
        { }
    public:
        // �������������
        const Datatype &operator*() const
        {
            return current->data;
        }

        // ��������� (����������)
        iterator &operator++()
        {
            current = current->next;
            return *this;
        }
        // ��������� (�����������)
        iterator operator++(int)
        {
            iterator it = *this;
            current = current->next;
            return it;
        }

        // ��������� �� ���������
        bool operator==(const iterator &it) const;
        // ��������� �� �����������
        bool operator!=(const iterator &it) const
        {
            return current != it.current || collection != it.collection;
        }

        // ��������� �����, 
        // �������� ����� ��������� ���������
        friend class list<Datatype>;
    };

    //
    // ������ ��� ������ � ����������
    //

    // ��������� ���������� �� ������ ������
    iterator begin()
    {
        return iterator(this, first);
    }
    // ��������� ��������� �� ������ ������
    iterator end()
    {
        return iterator(this, nullptr);
    }
};