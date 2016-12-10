//
// Лабораторная работа №27. STL. Интеллектуальные указатели 
// dyn_array.h
//
#pragma once
#include <iostream>
#include <iomanip>
#include <memory>
using namespace std;

template <typename T>
class dyn_array
{
	// Данные в массиве
	unique_ptr<T[], void(*)(T*)> data;
	//T*data;
	// Размер массива
	size_t _size;

	// функция копирования значений из массива в массив
	void copy(const T *from, T *to, size_t size);

	static T *allocator(size_t size = 0)
	{
		T *ptr = new T[size];
		std::cout << "0x" << std::hex << ptr << " : выделено " << 
			std::dec << sizeof(T) * size << " байт" << std::endl;
		return ptr;
	}

	static void deleter(T *ptr) {
		std::cout << "0x" << std::hex << ptr << " : освобождено" <<
			std::endl << std::dec;
		delete[]ptr;
	}
public:
	// Конструктор по умолчанию
	dyn_array() : data(allocator(0),deleter), _size(0) {}

	// Конструктор от размера
	dyn_array(size_t size) : 
		data(allocator(size),deleter), _size(size){}

	// Деструктор
	~dyn_array() {
		//deleter(data);
	}

	// Конструктор копии
	dyn_array(const dyn_array& d) : 
		data(allocator(size), deleter), _size(d._size) {
		copy(d.data.get(), data.get(), d._size);
	}

	// Операция присваивания
	dyn_array &operator=(const dyn_array& d) {
		if (d._size != _size) {
			//deleter(data);
			data.reset(allocator(d._size));
		}
		copy(d.data.get(), data.get(), d._size);
		_size = d._size;
		return *this;
	}

	// Операция доступа к элементам
	T &operator[](size_t index) {
		return data[index];
	}

	// Операция доступа к элементам для чтения
	const T &operator[](size_t index) const {
		return data[index];
	}

	// Количество элементов в массиве
	size_t size() const {
		return _size;
	}

	//Изменение размера массива
	void resize(size_t new_size);

	// Добавление элемента в конец массива
	// с увеличением размера массива
	void append(const T &x);

	// Вставка элемента по заданному индексу
	void insert(size_t index, const T &x);

	// Удаление элемента по заджанному индексу
	void remove_at(size_t index);
	
	// Поиск заданного элемента
	size_t find(const T &x);
};

template<typename T>
void dyn_array<T>::copy(const T *from, T *to, size_t size) 
{
	for (int i = 0; i < size; ++i)
		to[i] = from[i];
}

template<typename T>
void dyn_array<T>::resize(size_t new_size)
{
	if (new_size == _size) return;
	if (new_size > _size) {		
		//T *ptr = allocator(new_size);
		auto ptr = unique_ptr<T[], void(*)(T*)>(allocator(new_size), deleter);
		copy(data.get(), ptr.get(), _size);
		//deleter(data);
		data.swap(ptr);
		//data = ptr;
	}
	_size = new_size;
}

template<typename T>
void dyn_array<T>::append(const T &x) 
{
	resize(_size + 1);
	data[_size - 1] = x;
}

//template<typename T>
//void dyn_array<T>::insert(size_t index, const T &x)
//{
//	auto ptr = unique_ptr<T[], void(*)(T*)>(allocator(_size + 1),deleter);
//	for (int i = 0; i < index; ++i)
//		ptr[i] = data[i];
//	ptr[index] = x;
//	for (int i = index; i < _size; ++i)
//		ptr[i + 1] = data[i];
//	deleter(data);
//	data = ptr;
//	_size += 1;
//}
//
//template<typename T>
//void dyn_array<T>::remove_at(size_t index)
//{
//	T *ptr = allocator(_size - 1);
//	for (int i = 0; i < index; ++i)
//		ptr[i] = data[i];
//	for (int i = index + 1; i < _size; ++i)
//		ptr[i - 1] = data[i];
//	deleter(data);
//	data = ptr;
//	_size -= 1;
//}