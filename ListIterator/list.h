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
    // Узел списка
	struct node {
		datatype data;
		node *prev, *next;
	};

    // Начало и конец списка
	node *first, *last;

    // Копирование списка
    void copy_list(const node *from_first, const node *from_last, node *&to_first, node *&to_last);
    // Удаление списка
    void delete_list(node *&first, node *&last);
public:
//
// Итератор
//
	class iterator {
        // Указатель на узел списка
		node *current;
    private:
        // Закрытый конструктор,
        // доступен только внутри класса
        iterator(const node *list);
	public:
        // Разименование
        datatype &operator*();
        // Разименование константного итератора
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