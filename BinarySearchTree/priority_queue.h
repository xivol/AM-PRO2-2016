//
// ������������ ������ �21. ����������� ���� ������. ������� � �����������
// priority_queue.h
//
#pragma once
#include "bst.h"

// ������ �������� ��� ������� � �����������
template <typename Key, typename Value>
struct qpair
{
	Key key;
	Value value;

	// ������������
	qpair() {}
	qpair(const Key&k, const Value &v) : key(k), value(v) {}

	// ��������� �� ���������
	bool operator==(const qpair &p) const
	{
		// ����� ���� ��������� � ���� � ��������
		return key == p.key && value == p.value;
	}
	// �������� �� �����������
	bool operator<(const qpair &p) const
	{
		// ��������� �� �����
		return key < p.key;
	}
};

// ������ ������� � �����������
template <typename Priority, typename Value>
class priority_queue : protected bst<qpair<Priority, Value>>
{
	/* �� ���������� �������� ������������, 
	   �.�. ������� �� �������� �������, 
	   � ���� ���������� ��� ��� �������� ���������.
	   
	   ��� ����, �� �� ����� ������������ ������ 
	   ��� ���� ������, �.�. ��� ����� ������ 
	   � ��� �������� ������� ��� ����������� ������ � ���.
	   
	   �� ���������� ����������� ������ bst! 
	   ����� ������ ��������� ��������� �������� ���������� 
	   ��� ������� � �������� ����� � �������.
	*/
protected:
	// �������� ��� ����
	typedef qpair<Priority, Value> qpair;

	// ��������� �� ���������
	Priority default;
public:
	// �����������
	priority_queue() {}
	priority_queue(const Priority &default) : default(default) {}

	// �����������
	priority_queue(const priority_queue &q) : bst<qpair>(q) {}
	priority_queue& operator=(const priority_queue &q)
	{
		bst<qpair>::operator=(q);
		return *this;
	}

	// ���������� � �������
	void push(const Value &v) { push(v, default); }
	void push(const Value &v, const Priority &p);
	
	// ���������� �� �������
	void pop();
	
	// �������� ������� ��������
	Value top() const;

	// �������� ������� �� �������
	bool empty() const;

	// �������� ���������� �������� � �������
	priority_queue &operator<<(const Value &v);
	// �������� ���������� �������� �� �������
	priority_queue &operator>>(Value &v);

	// ������� ���� �������� - ����� �������
	priority_queue operator+(const priority_queue &q) const;

	// ������������� �������� ������
	template <typename P, typename V>
	friend std::ostream &operator<<(std::ostream &os, const priority_queue<P, V> &q);
	// ����������� �����
	template <typename P, typename V>
	friend class test_priority_queue<P, V>;
};

// �������� ����� ��������� � �������
template<typename P, typename V>
std::istream &operator>>(std::istream & is, priority_queue<P, V>& q);

template<typename P, typename V>
inline std::ostream & operator<<(std::ostream & os, const priority_queue<P, V>& q)
{
	for (bst<qpair<P, V>>::iterator i = q.begin(); i != q.end(); ++i)
		os << "{" << i->key << " " << i->value << "} ";
	return os;
}