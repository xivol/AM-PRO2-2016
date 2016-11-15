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
    typedef bst<pair<Priority, Value>>::iterator iterator;

    Priority default;
public:
    priority_queue() {}
    priority_queue(const Priority &default) :default(default) {}
    void push(const Value &v) {
        push(v, default);
    }
    void push(const Value &v, const Priority &p)
    {
        pair p = { p,v };
        insert(p);
    }
    void pop()
    {
        node *t = find_max(root);
        remove_tree(t);
    }
    Value top() const
    {

    }
    bool empty() const;
};
