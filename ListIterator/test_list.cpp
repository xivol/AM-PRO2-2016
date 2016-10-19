//
// Лабораторная работа №15. Абстрактные типы данных. Список с внешним итератором
// test_list.cpp
//
#include <cassert>
#include <iostream>
#include "list.h"
#include "test_list.h"

using namespace std;

list * test_list::generate_list(size_t size)
{
    list * l = new list();
    for (size_t i = 0; i < size; i++) {
        l->push_back(rand() % size);
    }
    return l;
}

bool test_list::is_equal(const list::node * l1, const list::node * l2)
{
    while (l1 != nullptr && l2 != nullptr) {
        if (l1->data != l2->data)
            return false;
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1 == l2;
}

bool test_list::copy_list()
{
#ifdef _DEBUG
	cerr << "test_list::copy_list: ";
#endif
	for (int i = 1; i < 100; ++i) {
		list *test1 = generate_list(i);
		list test2;
		test2.copy_list(test1->first, test1->last);
		assert(is_equal(test1->first, test2.first));
		delete test1;
	}
#ifdef _DEBUG
	cerr << "OK" << endl;
#endif
	return true;
}

bool test_list::delete_list()
{
#ifdef _DEBUG
	cerr << "test_list::delete_list: ";
#endif
	for (int i = 0; i < 100; ++i) {
		list *test1 = generate_list(i);
		test1->delete_list();
		assert(test1->first == nullptr && test1->last == nullptr);
		delete test1;
	}
#ifdef _DEBUG
	cerr << "OK" << endl;
#endif
	return true;
}

bool test_list::copy_ctor()
{
#ifdef _DEBUG
    cerr << "test_list::copy_ctor: ";
#endif
    for (int i = 1; i < 100; ++i) {
        list *test1 = generate_list(i);
        list test2(*test1);
        assert(is_equal(test1->first, test2.first));
        delete test1;
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif
    return true;
}

bool test_list::assign()
{
#ifdef _DEBUG
    cerr << "test_list::assign: ";
#endif
    for (int i = 1; i < 100; ++i) {
        list *test1 = generate_list(i);
        list test2;
        test2 = *test1;
        assert(is_equal(test1->first, test2.first));
        delete test1;
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif
    return true;
}

bool test_list::push_back()
{
#ifdef _DEBUG
    cerr << "test_list::push_back: ";
#endif

    list test;
    for (int i = 1; i < 100; ++i) {
        test.push_back(i);
        assert(test.back() == i);
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif
    return true;
}

bool test_list::back()
{
#ifdef _DEBUG
    cerr << "test_list::back: " << endl;
#endif

    list test;
    try {
        test.back();
        assert(false && "Ожидалось исключение при доступе к пустому списку");
    }
    catch (...) {
        assert(true);
    }

    for (int i = 1; i < 100; ++i) {
        test.push_back(i);
        assert(test.back() == i);
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif
    return true;
}

bool test_list::run()
{
    test_list test;
    return test.copy_list() && test.delete_list() && 
		test.copy_ctor() && test.assign() && test.push_back() &&
		test.back();
}
