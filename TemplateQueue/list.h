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
    void push_back(const Datatype &x);
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
        iterator(const list *collection, node *current);
    public:
        // �������������
        Datatype &operator*();

        // ��������� (����������)
        iterator &operator++();
        // ��������� (�����������)
        iterator operator++(int);

        // ��������� �� ���������
        bool operator==(const iterator &it) const;
        // ��������� �� �����������
        bool operator!=(const iterator &it) const;

        // ��������� �����, 
        // �������� ����� ��������� ���������
        friend class list<Datatype>;
    };

    //
    // ������ ��� ������ � ����������
    //

    // ��������� ���������� �� ������ ������
    iterator begin();
    // ��������� ��������� �� ������ ������
    iterator end();

    // ����� �������� � �������� ���������� ������
    // � ����������� ���������, ������������ �� ����.
    // � ������, ���� ������� � �������� ��������� �� ������,
    // ������������ �������� list::end()
    iterator find(const Datatype &x) const;

    // ������� ��������, ����� ��������� �� ������� ��������� ��������
    void insert(const iterator &it, const Datatype &x);

    // �������� �������� �� ������� ��������� ��������
    void remove(const iterator &it);

};

template <typename T>
std::ostream &operator<<(std::ostream &os, list<T> &l)
{
    for (list<T>::iterator it = l.begin(); it != l.end(); ++it)
        os << *it << ' ';
}

