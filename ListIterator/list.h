//
// Лабораторная работа №15. Абстрактные типы данных. Список с внешним итератором
// list.h
//
#pragma once
#include <iostream>
#include "crtdynmem.h"

// Список с внешним итератором
class list {
public:
    // Тип данных в списке
	typedef int datatype;

    list();
    list(const list &l);
    list &operator=(const list &l);
    ~list();
    
    // Количество элементов в списке
    size_t size() const;

    // Проверка списка на пустоту
    bool is_empty() const
    {
        // функция определенная в теле класса
        // становится встраеваемой
        return first == nullptr && last == nullptr;
    }

    // Добавление элемента в конец
    void push_back(const datatype &x);
    // Извлечение последнего элемнта
    void pop_back();
    // Получение последнего элемента
    datatype back() const;
    
    // Добавление элемента в начало
    void push_front(const datatype &x);    
    // Извлечение первого элемента
    void pop_front();
    // Получение первого элемента
    datatype front() const;

    // Тестирующий класс
    friend class test_list;
private:
    // Описание узла списка
	struct node {
		datatype data;
		node *prev, *next;
	};

    // Начало и конец списка
	node *first, *last;

    // Метод для копирование элементов из другого списка
    void copy_list(const node *from_first, const node *from_last);
    // Метод удаления списка
    void delete_list();

public:
//
// Внешний итератор
//

    // Будем описывать итератор, как внутренний тип
	class iterator {

        // Указатель на узел списка
		node *current;

        // Указатель на список
        const list *collection;

        // Закрытый конструктор
        // доступен только в дружественных классах 
        iterator(const list *collection, node *current);
	public:
        // Разименование
        datatype &operator*();

        // Инкремент (префиксный)
        iterator &operator++();
        // Инкремент (постфиксный)
        iterator operator++(int);

        // Сравнение на равенство
        bool operator==(const iterator &it) const;
        // Сравнение на неравенство
        bool operator!=(const iterator &it) const;

        // Объявляем класс, 
        // которому можно создавать итераторы
        friend class list;
	};

//
// Методы для работы с итератором
//

    // Получение итерартора на начало списка
    iterator begin();
    // Получение итератора за концом списка
    iterator end();

    // Поиск элемента с заданным значением в списке
    // и возвращение итератора, указывающего на него.
    // В случае, если элемент с заданным значением не найден,
    // Возвращается итератор list::end()
    iterator find(const datatype &x) const;

    // Вставка элемента, перед элементом на который указывает итератор
    void insert(const iterator &it, const datatype &x);

    // Удаление элемента на который указывает итератор
    void remove(const iterator &it);

};

std::ostream &operator<<(std::ostream &os, list &l);