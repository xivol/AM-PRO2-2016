#pragma once

class list {
public:
	typedef int datatype;

    list();
    list(const list &l);
    list &operator=(const list &l);
    ~list();

    bool is_empty() const;
    size_t size() const;

    void push_back(const datatype &x);
    void pop_back();
    datatype back() const;
    
    void push_front(const datatype &x);    
    void pop_front();
    datatype front() const;

private:
    // ���� ������
	struct node {
		datatype data;
		node *prev, *next;
	};

    // ������ � ����� ������
	node *first, *last;

    // ����������� ������
    void copy_list(const node *from_first, const node *from_last, node *&to_first, node *&to_last);
    // �������� ������
    void delete_list(node *&first, node *&last);
public:
//
// ��������
//
	class iterator {
        // ��������� �� ���� ������
		node *current;
    private:
        // �������� �����������,
        // �������� ������ ������ ������
        iterator(const node *list);
	public:
        // �������������
        datatype &operator*();
        // ������������� ������������ ���������
        datatype operator*() const;
        
        iterator &operator--();
        iterator &operator--(int);
        
        iterator &operator++();
        iterator &operator++(int);

        bool operator==(const iterator &it) const;
        bool operator!=(const iterator &it) const;
	};

    iterator begin() const;
    iterator end() const;

    iterator find(const datatype &x) const;
    void insert(const iterator &it, const datatype &x);
    void remove(const iterator &it);
};