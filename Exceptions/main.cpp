#include "dyn_array.h"
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");    
    try {
        dyn_array d;        
        int size = INT32_MAX;
        cout << "¬ведите количество элементов в массиве:" << endl;

        cin.exceptions(ios_base::failbit);
        cin >> size;
        d.resize(size);
        
        cout << "¬ведите значени€ элементов в массиве:" << endl;
        for (int i = 0; i <= d.count(); ++i)
            cin >> d[i];

        cout << "¬ведите индекс элемента:" << endl;
        int index;
        cin >> index;
        cout << "Ёлемент с введенным индексом:" << endl;
        cout << d[index] << endl;

        for (int i = 0; i < d.count() - 1; ++i)
            cout << d[i] << ", ";
        cout << d[d.count() - 1] << endl;
    }
    catch (const ios_base::failure &e) {
        cerr << "Ќекорректный ввод" << endl;
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }


    system("pause");
    return 0;
}
