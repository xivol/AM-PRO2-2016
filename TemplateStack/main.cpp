#include <iostream>
#include "stack.h"

using namespace std;

bool balanced_braces(const char *str)
{
    stack<char> st;
    while (*str) {
        switch (*str) {
            case '{':
            case '[':
            case '(':
                st.push(*str);
                break;
            case '}':
                if (st.top() != '{')
                    return false;
                st.pop();
                break;
            case ']':
                if (st.top() != '[')
                    return false;
                st.pop();
                break;
            case ')':
                if (st.top() != '(')
                    return false;
                st.pop();
                break;
        }
        str+=1;
    }
    return st.is_empty();
}

int priority(char op)
{
    switch (op) {
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case ')':
            return 3;
    }
}

void RPN(const char *source, char *result)
{
    stack<char> st;
    while (*source) {
        switch (*source) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '(':               
                while (!st.is_empty() && priority(*source) < priority(st.top())) {
                    *result = st.top();
                    result += 1;                    
                    st.pop();
                }
                st.push(*source);
                break;
            case ')':
                while (!st.is_empty() && priority(st.top()) != 0) {
                    *result = st.top();
                    result += 1;
                    st.pop();
                }
                if (st.is_empty()) throw "";
                st.pop();
                break;
            default:
                *result = *source;
                result += 1;
        }
        source += 1;        
    }
    while (!st.is_empty()) {
        *result = st.top();
        st.pop();
        result += 1;
    }
}
double eval(double x, double y, char op)
{
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
    }
}
double calc(const char *source)
{
    stack<double> values;
    stack<char> op;
    while (*source) {
        switch (*source) {
            case '+':
            case '-':
            case '*':
            case '/':
                while (!op.is_empty() && priority(*source) < priority(op.top())) {
                    double x = values.top();
                    values.pop();
                    double y = values.top();
                    values.pop();
                    values.push(eval(x, y, op.top()));
                    op.pop();
                }
            case '(':
                op.push(*source);
                break;
            case ')':
                while (!op.is_empty() && priority(op.top()) != 0) {
                    double y = values.top();
                    values.pop();
                    double x = values.top();
                    values.pop();
                    values.push(eval(x, y, op.top()));
                    op.pop();
                }
                if (op.is_empty()) throw "";
                op.pop();
                break;
            default:
                values.push(*source - '0');
        }
        source += 1;
    }
    while (!op.is_empty()) {
        double x = values.top();
        values.pop();
        double y = values.top();
        values.pop();
        values.push(eval(x, y, op.top()));
        op.pop();
    }
    return values.top();
}

int main()
{    
    const char * str = "((1+2)*(3-4))/5";

    cout << (balanced_braces(str) ? "true" : "false") << endl;
    char rpn[100] = "                ";
    RPN(str, rpn);
    cout << rpn << endl;
    cout << calc(str) << endl;

    system("pause");

}
