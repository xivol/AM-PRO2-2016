#pragma once
class test_list
{
    bool equals(const list &l1, const list &l2);

	// Тестирующие функции
	bool copy_list();
	bool delete_list()
    bool copy_ctor();
    bool assign();
    bool push_back();
    bool pop_back();
    bool back();
public:
    bool run();
};

