#pragma once
#include <iostream>

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
    void copy_list(const node *from_first, const node *from_last);
    // Удаление списка
    void delete_list();
public:
//
// Внешний итератор
//
    // Поскольку итератор нельзя создать вне спика,
    // класс будем описывать, как внутренний тип
	class iterator {

        // Указатель на узел списка
		node *current;

        // Указатель на список
        const list *current_list;

        // Закрытый конструктор
        // доступен только внутри класса list
        iterator(const list *collection, const node *current);
	public:
        // Разименование
        datatype &operator*();
        // Разименование константного итератора
        datatype operator*() const;
        
        // Инкремент (префиксный)
        iterator &operator++();
        // Инкремент (постфиксный)
        iterator operator++(int);

        // Сравнение на равенство
        bool operator==(const iterator &it) const;
        // Сравнение на неравенство
        bool operator!=(const iterator &it) const;
	};
//
// Методы для работы с итератором
//
    iterator begin() const;
    iterator end() const;

    iterator find(const datatype &x) const;
    void insert(const iterator &it, const datatype &x);
    void remove(const iterator &it);
};

std::ostream &operator<<(std::ostream &os, const list &l);