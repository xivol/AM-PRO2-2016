//
// Лабораторная работа №10. Классы. Обработка исключений
// dyn_array.h
//
#pragma once
#include <exception>
#include <iostream>
#include "crtdynmem.h"

class dyn_array
{
public:    
    // Конструктор по умолчанию
    dyn_array();

    // Конструктор от размера
    dyn_array(int size);

    // Конструктор из файла
    dyn_array(const char *filename, bool is_text = true);

    // Деструктор
    ~dyn_array();

    // Конструктор копии
    dyn_array(const dyn_array& d);    

    // Операция присваивания
    dyn_array &operator=(const dyn_array& d);

    // Тип данных, хранящийся в массиве
    typedef int datatype;

    // Операция доступа к элементам
    datatype &operator[](int index);

    // Операция доступа к элементам для чтения
    datatype operator[](int index) const;

    // Количество элементов в массиве
    int count() const;

    //Изменение размера массива
    void resize(int new_size);

    // Добавление элемента в конец массива
    // с увеличением размера массива
    void append(const datatype &x);

    // Вставка элемента по заданному индексу
	void insert(int index, const datatype &x);

    // Удаление элемента по заджанному индексу
	void remove_at(int index);

    // Удаление заданного элемента
	void remove(const datatype &x);

    // Поиск заданного элемента
	bool contains(const datatype &x);
private:
    datatype *data;
    int size;
    // функция копирования знасений из массива в массив
    void copy(const datatype *from, datatype* to, int size);

    // Функция считывания данных из двоичного файла
    void file_init(const char *filename);

    // Функция чтения данных из текстового файла
    void text_init(const char *filename);

public:
	class array_exception : public std::exception {
	};
	class size_exception : public array_exception {
	};
	class index_exception : public array_exception {
	};
	class file_exception :public array_exception {
	};
};

