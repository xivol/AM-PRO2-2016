#pragma once
#include "list.h"

template <typename Datatype>
class queue
{
    list<Datatype> list;
public:
    void push(const Datatype &x)
    {
        list.push_back(x);
    }
    Datatype pop()
    {
        Datatype x = list.front();
        list.pop_front();
        return x;
    }
    Datatype top()
    {
        return list.front();
    }
};
