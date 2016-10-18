#include <iostream>
#include "list.h"

using namespace std;

void print(const list &l)
{
    for (list::iterator i = l.begin(); i != l.end(); ++i) {
        *i += 1;
        cout << *i << endl;
    }
}
int main()
{
    list l;
    int n = 10;
    while (n--)
        l.push_back(n);
    for (list::iterator i = l.begin(); i != l.end(); ++i) {     
        cout << *i << endl;
    }
    print(l);
    system("pause");
    return 0;
}