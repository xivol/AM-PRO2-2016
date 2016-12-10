//
// ������������ ������ �27. STL. ���������������� ��������� 
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
	// ������ � �������
	unique_ptr<T[], void(*)(T*)> data;
	//T*data;
	// ������ �������
	size_t _size;

	// ������� ����������� �������� �� ������� � ������
	void copy(const T *from, T *to, size_t size);

	static T *allocator(size_t size = 0)
	{
		T *ptr = new T[size];
		std::cout << "0x" << std::hex << ptr << " : �������� " << 
			std::dec << sizeof(T) * size << " ����" << std::endl;
		return ptr;
	}

	static void deleter(T *ptr) {
		std::cout << "0x" << std::hex << ptr << " : �����������" <<
			std::endl << std::dec;
		delete[]ptr;
	}
public:
	// ����������� �� ���������
	dyn_array() : data(allocator(0),deleter), _size(0) {}

	// ����������� �� �������
	dyn_array(size_t size) : 
		data(allocator(size),deleter), _size(size){}

	// ����������
	~dyn_array() {
		//deleter(data);
	}

	// ����������� �����
	dyn_array(const dyn_array& d) : 
		data(allocator(size), deleter), _size(d._size) {
		copy(d.data.get(), data.get(), d._size);
	}

	// �������� ������������
	dyn_array &operator=(const dyn_array& d) {
		if (d._size != _size) {
			//deleter(data);
			data.reset(allocator(d._size));
		}
		copy(d.data.get(), data.get(), d._size);
		_size = d._size;
		return *this;
	}

	// �������� ������� � ���������
	T &operator[](size_t index) {
		return data[index];
	}

	// �������� ������� � ��������� ��� ������
	const T &operator[](size_t index) const {
		return data[index];
	}

	// ���������� ��������� � �������
	size_t size() const {
		return _size;
	}

	//��������� ������� �������
	void resize(size_t new_size);

	// ���������� �������� � ����� �������
	// � ����������� ������� �������
	void append(const T &x);

	// ������� �������� �� ��������� �������
	void insert(size_t index, const T &x);

	// �������� �������� �� ���������� �������
	void remove_at(size_t index);
	
	// ����� ��������� ��������
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