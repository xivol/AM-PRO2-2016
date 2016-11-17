#pragma once

// ���� ������:
//     data - �������� � ���� ������;
//     next - ��������� �� ��������� �������.
template<typename Datatype>
struct tlist
{
	Datatype data;
	tlist *next;
	tlist(): next(nullptr) {}
	tlist(const Datatype &data, tlist *next = nullptr):
		data(data), next(next) {}
};

// ������� ����������� ������.
// ������� ���������:
//     begin - ��������� �� ������ ������.
// ������������ ��������:
//     ��������� �� ����� ������.
template<typename T>
tlist<T> copy_list(tlist<T> *begin) 
{
	tlist<T> *new_begin = nullptr;
	tlist<T> *new_end = nullptr;
	while (begin != nullptr) {
		tlist<T> * t = new tlist<T>;
		t->data = begin->data;
		t->next = nullptr;
		if (new_begin == nullptr) {
			new_begin = t;
		}
		else {
			new_end->next = t;
		}
		new_end = t;
		begin = begin->next;
	}
	return new_begin;
}


// ������� �������� ������.
// ������� ���������:
//     begin - ��������� �� ������ ������.
// �������� �������� ��������� begin ����� nullptr.
template<typename T>
void delete_list(tlist<T> *&begin)
{
	while (begin != nullptr) {
		tlist<T> *t = begin;
		begin = begin->next;
		delete t;
	}
}

// ������� ������ ������ �� �������.
// ������� ���������:
//     begin - ��������� �� ������ ������,
//     os - ������� ����� ������.
template<typename T>
void print_list(const tlist<T> *begin, std::ostream &os = std::cout)
{
	while (begin != nullptr) {
		os << begin->data << ' ';
		begin = begin->next;
	}
	os << endl;
}