#include "point.h"
#include "vector.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        cout>>"¬ведите начальную точку:";
        point start;
        cin>>start;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
    system("pause");
    return 0;
}