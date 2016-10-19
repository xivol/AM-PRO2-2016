//
// Лабораторная работа №15. Абстрактные типы данных. Список с внешним итератором
// test_list.h
//
#pragma once
class test_list
{
    list * generate_list(size_t size);
    bool is_equal(const list::node *l1, const list::node *l2);

	// Тестирующие методы
	bool copy_list();
	bool delete_list();
    bool copy_ctor();
    bool assign();
    bool push_back();
    bool back();
public:
    static bool run();
};

