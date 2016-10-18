#include <cassert>
#include <iostream>
#include "stack.h"
#include "test_d_stack.h"
using namespace std;

bool test_d_stack::is_empty()
{
#ifdef _DEBUG
    cerr << "test_d_stack::is_empty: ";
#endif

    d_stack stack;
    assert(stack.is_empty());

    stack.push(1);
    stack.pop();
    assert(stack.is_empty());

    int n = 100;
    for (int i = 0; i < n; ++i)
        stack.push(i);
    for (int i = 0; i < n; ++i)
        stack.pop();
    assert(stack.is_empty());

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif 
    return true;
}

bool test_d_stack::push()
{
#ifdef _DEBUG
    cerr << "test_d_stack::push: ";
#endif

    d_stack stack;
    for (int i = 0; i < 1000; ++i) {
        stack.push(i);
        assert(stack.top() == i);
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif 
    return true;
}

bool test_d_stack::pop()
{
#ifdef _DEBUG
    cerr << "test_d_stack::pop: ";
#endif

    d_stack stack;
    try {
        stack.pop();
        assert(true);
    }
    catch (...) {
        assert(false && "Неожиданное исключение при пустом стеке");
    }

    int n = 1000;
    for (int i = 0; i < n; ++i) 
        stack.push(i);
    for (int i = n-1; i > 0; --i) {
        stack.pop();
        assert(stack.top() == i-1);
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif 
    return true;
}

bool test_d_stack::top()
{
#ifdef _DEBUG
    cerr << "test_d_stack::top: ";
#endif

    d_stack stack;
    try {
        stack.top();
        assert(false && "Ожидалось исключение при пустом стеке");
    }
    catch (...) {
        assert(true);
    }

    for (int i = 0; i < 1000; ++i) {
        stack.push(i);
        assert(stack.top() == i);
    }

#ifdef _DEBUG
    cerr << "OK" << endl;
#endif 
    return true;
}

bool test_d_stack::run()
{
    test_d_stack test;
    return test.is_empty() && test.push() &&
        test.pop() && test.top();
}
