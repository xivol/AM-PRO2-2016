//
// ������������ ������ �27. STL. ���������������� ��������� 
// dyn_array.h
//
#pragma once
#include <memory>
using namespace std;

template <typename T>
class dyn_array
{
	// ������ � �������
	unique_ptr<T[]> data;

	// ������ �������
	size_t size;

	// ������� ����������� �������� �� ������� � ������
	static void copy(const T *from, T *to, size_t count);
public:
	// ����������� �� ���������
	dyn_array() : data(nullptr), size(0) 
    {}

	// ����������� �� �������
	dyn_array(size_t count) : 
		data(new T[count]), size(count) 
    {}

	// ����������
	~dyn_array() 
    {
		// ��� ������ ����� �����������
        // ������������� ����� �����������
	}

	// ����������� �����
	dyn_array(const dyn_array& d) : 
		data(new T[d.size]), size(d.size) 
	{
		copy(d.data.get(), data.get(), d.size);
	}

	// �������� ������������
	dyn_array &operator=(const dyn_array& d) 
	{
		if (d.size != size) {
            // ����������� ������ � 
            // �������� ����� ������
			data.reset(new T[d.size]);
		}
		copy(d.data.get(), data.get(), d.size);
		size = d.size;
		return *this;
	}

	// �������� ������� � ���������
	T &operator[](size_t index) 
	{
        if (index >= size) throw out_of_range("������ ��������� ��� ������ �������.");
		return data[index];
	}

	// �������� ������� � ��������� ��� ������
	const T &operator[](size_t index) const 
	{
        if (index >= size) throw out_of_range("������ ��������� ��� ������ �������.");
		return data[index];
	}

	// ���������� ��������� � �������
	size_t count() const
	{
		return size;
	}

	//��������� ������� �������
	void resize(size_t new_size);

	// ���������� �������� � ����� �������
	// � ����������� ������� �������
	void append(const T &x);

	// ������� �������� �� ��������� �������
	void insert(size_t index, const T &x);

	// �������� �������� �� ��������� �������
	void remove_at(size_t index);
	
	// ����� ��������� ��������
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
        // �������� ����� ������
		auto ptr = unique_ptr<T[]>(new T[new_size]);
        // �������� ��������
		copy(data.get(), ptr.get(), size);

        // ���������� ���������
		data.swap(ptr);
        // ������ ������ ������ � ptr -
        // ������ ����� ����������� ��� ������ �� �����
        
        // ������ �������:
        // data.reset( ptr.release() );
        // ������� ���������� ��� *ptr � data
        // ������ *data ����� ������������� �����������
	}
	size = new_size;
}

template<typename T>
void dyn_array<T>::append(const T &x) 
{
	resize(size + 1);
	data[size - 1] = x;
}