#pragma once

// Узел списка:
//     data - значение в узле списка;
//     next - указатель на следующий элемент.
template<typename Datatype>
struct tlist
{
	Datatype data;
	tlist *next;
};

// Функция копирования списка.
// Входные параметры:
//     begin - указатель на начало списка.
// Возвращаемое значение:
//     указатель на копию списка.
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


// Функция удаления списка.
// Входные параметры:
//     begin - указатель на начало списка.
// Выходное значение параметра begin равно nullptr.
template<typename T>
void delete_list(tlist<T> *&begin)
{
	while (begin != nullptr) {
		tlist<T> *t = begin;
		begin = begin->next;
		delete t;
	}
}

// Функция вывода списка на консоль.
// Входные параметры:
//     begin - указатель на начало списка.
template<typename T>
void print_list(const tlist<T> *begin) 
{
	while (begin != nullptr) {
		cout << begin->data << ' ';
		begin = begin->next;
	}
	cout << endl;
}