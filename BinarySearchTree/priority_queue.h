#pragma once
#include "bst.h"

template <typename Key, typename Value>
struct pair
{
    Key key;
    Value value;
    bool operator==(const pair &p)
    {
        return key == p.key;
    }
    bool operator<(const pair &p)
    {
        return key < p.key;
    }
};

template <typename Priority, typename Value>
class priority_queue : protected bst<pair<Priority, Value>>
{
    typedef pair<Priority, Value> pair;
    typedef bst<pair>::iterator iterator;

    Priority default;
public:
    priority_queue() {}
    priority_queue(const Priority &default) :default(default) {}

    void push(const Value &v);
    void push(const Value &v, const Priority &p);
    void pop();

    Value top() const;
    bool empty() const;
};
