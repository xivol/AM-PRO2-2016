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
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
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
            case '^':
                while (!st.is_empty() && priority(*source) < priority(st.top())) {
                    *result = st.top();
                    result += 1;
                    st.pop();
                }
            case '(':               
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
    *result = 0;
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
        case '^':
            return pow(x, y);
    }
    return nan("");
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
            case '^':
                while (!op.is_empty() && priority(*source) < priority(op.top())) {
                    double y = values.pop();
                    double x = values.pop();
                    values.push(eval(x, y, op.pop()));
                }
            case '(':
                op.push(*source);
                break;
            case ')':
                while (!op.is_empty() && priority(op.top()) != 0) {
                    double y = values.pop();
                    double x = values.pop();
                    values.push(eval(x, y, op.pop()));
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
        double y = values.pop();
        double x = values.pop();
        values.push(eval(x, y, op.pop()));
    }
    return values.top();
}

double calc_rpn(const char* source)
{    
    char * rpn = new char[strlen(source) + 1];
    RPN(source, rpn);
    stack<double> values;
    char * i = rpn;
    while (*i) {
        switch (*i) {
            case '+':
            case '-':
            case '*':
            case '/': 
            case '^':
            {
                double y = values.pop();
                double x = values.pop();
                values.push(eval(x, y, *i));
                break;
            }
            default:
                values.push(*i - '0');
        }
        i+=1;
    }
    delete rpn;
    return values.top();
}

int main()
{    
    const char * str = "((1+2)*(3-4)^2)/5";

    cout << (balanced_braces(str) ? "true" : "false") << endl;
    char rpn[100];
    RPN(str, rpn);
    cout << rpn << endl;
    cout << calc(str) << endl;
    cout << calc_rpn(str) << endl;

    system("pause");
    return 0;
}
