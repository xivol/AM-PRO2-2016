#include <cassert>
#include "list.h"
#include "test_list.h"

//list::node *test_list::get_array_list(const list::datatype *array, size_t length)
//{
//    assert(array != nullptr);
//    list::node *arr_list = new list::node[length];
//
//    for (size_t i = 0; i < length; i++) {
//        arr_list[i].data = array[i];
//        arr_list[i].next = &arr_list[i + 1];
//        arr_list[i].prev = &arr_list[i - 1];
//    }
//    arr_list[0].prev = nullptr;
//    arr_list[length - 1].next = nullptr;
//
//    return arr_list;
//}