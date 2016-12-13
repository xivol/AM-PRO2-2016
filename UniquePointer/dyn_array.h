//
// Лабораторная работа №27. STL. Интеллектуальные указатели 
// dyn_array.h
//
#pragma once
#include <memory>
using namespace std;

template <typename T>
class dyn_array
{
	// Данные в массиве
	unique_ptr<T[]> data;

	// Размер массива
	size_t size;

	// Функция копирования значений из массива в массив
	static void copy(const T *from, T *to, size_t count);
public:
	// Конструктор по умолчанию
	dyn_array() : data(nullptr), size(0) 
    {}

	// Конструктор от размера
	dyn_array(size_t count) : 
		data(new T[count]), size(count) 
    {}

	// Деструктор
	~dyn_array() 
    {
		// вся память будет освобождена
        // автоматически после деструктора
	}

	// Конструктор копии
	dyn_array(const dyn_array& d) : 
		data(new T[d.size]), size(d.size) 
	{
		copy(d.data.get(), data.get(), d.size);
	}

	// Операция присваивания
	dyn_array &operator=(const dyn_array& d) 
	{
		if (d.size != size) {
            // освобождаем старую и 
            // выделяем новую память
			data.reset(new T[d.size]);
		}
		copy(d.data.get(), data.get(), d.size);
		size = d.size;
		return *this;
	}

	// Операция доступа к элементам
	T &operator[](size_t index) 
	{
        if (index >= size) throw out_of_range("Индекс находится вне границ массива.");
		return data[index];
	}

	// Операция доступа к элементам для чтения
	const T &operator[](size_t index) const 
	{
        if (index >= size) throw out_of_range("Индекс находится вне границ массива.");
		return data[index];
	}

	// Количество элементов в массиве
	size_t count() const
	{
		return size;
	}

	//Изменение размера массива
	void resize(size_t new_size);

	// Добавление элемента в конец массива
	// с увеличением размера массива
	void append(const T &x);

	// Вставка элемента по заданному индексу
	void insert(size_t index, const T &x);

	// Удаление элемента по заданному индексу
	void remove_at(size_t index);
	
	// Поиск заданного элемента
	size_t find(const T &x);
};

template<typename T>
void dyn_array<T>::copy(const T *from, T *to, size_t count) 
{
	for (int i = 0; i < count; ++i)
		to[i] = from[i];
}

template<typename T>
void dyn_array<T>::resize(size_t new_size)
{
	if (new_size == size) return;
	if (new_size > size) {		
        // выделяем новую память
		auto ptr = unique_ptr<T[]>(new T[new_size]);
        // копируем значения
		copy(data.get(), ptr.get(), size);

        // обмениваем указатели
		data.swap(ptr);
        // старый массив теперь в ptr -
        // память будет освобождена при выходе из блока
        
        // другой вариант:
        // data.reset( ptr.release() );
        // передаём управление над *ptr в data
        // память *data будет автоматически освобождена
	}
	size = new_size;
}

template<typename T>
void dyn_array<T>::append(const T &x) 
{
	resize(size + 1);
	data[size - 1] = x;
}