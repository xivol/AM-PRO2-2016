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

    // Количество элементов в списке
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

    // Проверка списка на пустоту
    bool is_empty() const
    {
        return first == nullptr && last == nullptr;
    }

    // Добавление элемента в конец
    void push_back(const Datatype &x);
    // Извлечение последнего элемнта
    void pop_back();
    // Получение последнего элемента
    Datatype back() const;

    // Добавление элемента в начало
    void push_front(const Datatype &x);
    // Извлечение первого элемента
    void pop_front();
    // Получение первого элемента
    Datatype front() const;

    // Тестирующий класс
    friend class test_list;
private:
    // Описание узла списка
    struct node
    {
        Datatype data;
        node *prev, *next;
    };

    // Начало и конец списка
    node *first, *last;

    // Метод для копирование элементов из другого списка
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

    // Метод удаления списка
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
    // Внешний итератор
    //

    // Будем описывать итератор, как внутренний тип
    class iterator
    {

        // Указатель на узел списка
        node *current;

        // Указатель на список
        const list *collection;

        // Закрытый конструктор
        // доступен только в дружественных классах 
        iterator(const list *collection, node *current);
    public:
        // Разименование
        Datatype &operator*();

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
        friend class list<Datatype>;
    };

    //
    // Методы для работы с итератором
    //

    // Получение итерартора на начало списка
    iterator begin();
    // Получение итератора за концом списка
    iterator end();

    // Поиск элемента с заданным значениемв списке
    // и возвращение итератора, указывающего на него.
    // В случае, если элемент с заданным значением не найден,
    // Возвращается итератор list::end()
    iterator find(const Datatype &x) const;

    // Вставка элемента, перед элементом на который указывает итератор
    void insert(const iterator &it, const Datatype &x);

    // Удаление элемента на который указывает итератор
    void remove(const iterator &it);

};

template <typename T>
std::ostream &operator<<(std::ostream &os, list<T> &l)
{
    for (list<T>::iterator it = l.begin(); it != l.end(); ++it)
        os << *it << ' ';
}

