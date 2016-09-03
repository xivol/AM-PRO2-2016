//
// ������������ ������ �13. ������������ ��������� ������. ������
// test_llist.cpp
//

#include <cassert>
#include <iostream>

#include "crtdynmem.h"
#include "llist.h"
#include "test_llist.h"
#include "test_tlist.h"
#include "tlist.h"

llist *get_array_llist(const llist::datatype *array, size_t length)
{
    assert(array != nullptr);
    llist *arr_list = new llist[length];

    for (size_t i = 0; i < length; i++) {
        arr_list[i].data = array[i];
        arr_list[i].next = &arr_list[i + 1];
        arr_list[i].prev = &arr_list[i - 1];
    }
    arr_list[0].prev = nullptr;
    arr_list[length - 1].next = nullptr;

    return arr_list;
}

bool test_get_llist_from_file()
{
    size_t n = 10;
    const char *tmpname = "list.tmp";
    // �������� �������� ������
    llist::datatype *array = create_test_data(tmpname, n);

    // ������ ������ �� �����
    llist *end;
    llist *list = get_list(tmpname, end);
    
    // ��������� ��������� ������������ � ��������
    is_equal_test(list, array, n);

    // ������� ��������� ������    
    delete[] array;
    remove(tmpname);
    delete_list(list);
#ifdef _DEBUG
    std::cerr << "test get_llist(filename): OK" << std::endl;
#endif
    return true;
}

bool test_get_array_llist()
{
    int n = 5;
    llist::datatype *array = new llist::datatype[n];
    for (int i = 0; i<n; i++) {
        array[i] = rand();
    }
    llist *list = get_array_llist(array, n);

    llist *p = list;
    int i = 0;
    while (p->next!= nullptr && i < n) {
        // ��������� ��������� ������
        assert(p == &list[i]);
        // ��������� �������� � ������
        assert(p->data == array[i]);
        i++;
        p = p->next;
    }

    // ��������� ���������� �������� � ������
    assert(i + 1 == n);

    // �������� ������
    while (p->prev != nullptr && i > 0) {
        // ��������� ��������� ������
        assert(p == &list[i]);
        // ��������� �������� � ������
        assert(p->data == array[i]);
        i--;
        p = p->prev;
    }

    delete[] list;
    delete[] array;
#ifdef _DEBUG
    std::cerr << "test get_array_llist: OK" << std::endl;
#endif
    return true;
}

bool test_is_symmetrical()
{
    // ���������, ��� ������������ ������� ���������
    test_get_array_llist();
    // �������� ��� ������ ������ �����
    size_t  n = 10;
    llist::datatype array[] = { 0, 1, 2, 3, 4, 4, 3, 2, 1, 0 };
    llist *list = get_array_llist(array, n);

    for (size_t i = 0; i < n / 2; i++) {
        assert(is_symmetrical(&list[i], &list[n - i - 1]));
        if (i != n-i-2)
         assert(!is_symmetrical(&list[i], &list[n - i - 2]));
    }
    
    delete[] list;

    // �������� ��� ������ �������� �����
    n = 9;
    llist::datatype array2[] = { 1, 0, 1, 0, 1, 0, 1, 0, 1 };
    list = get_array_llist(array2, n);

    for (size_t i = 0; i < n / 2; i++) {
        assert(is_symmetrical(&list[i], &list[n - i - 1]));        
        assert(is_symmetrical(&list[i], &list[i + 2]));
        assert(is_symmetrical(&list[i], &list[i + 4]));
        assert(!is_symmetrical(&list[i], &list[i + 1]));
        assert(!is_symmetrical(&list[i], &list[i + 3]));
    }

    delete[] list;
#ifdef _DEBUG
    std::cerr << "test is_symmetrical: OK" << std::endl;
#endif
    return true;
}

bool test_llist_full()
{
    return test_get_llist_from_file() &&
        test_is_symmetrical();
}
