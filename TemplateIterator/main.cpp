#include <iostream>
#include <algorithm>
#include "algorithms.h"
#include "list.h"

using namespace std;

int main()
{
    const int n = 10;
    int arr[n] = { 0,-1,2,-3,4,-5,6,-7,8,-9 };
    print(arr);
    cout << min_value( begin(arr), end(arr)) << endl;

    list<int> l;
    for (auto it = begin(arr); it != end(arr); ++it)
        l.push_back(*it);
    print(l);
    cout << min_value(l) << endl;    

    system("pause");
    return 0;
}