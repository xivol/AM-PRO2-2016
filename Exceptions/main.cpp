//
//
//
#include <iostream>
#include <limits>
#include "dyn_array.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");    
    try {   
        int size = 0;
        cout << "Введите количество элементов в массиве:" << endl;
        //
        cin.exceptions(ios_base::failbit);
        cin >> size;
        dyn_array d(size);

        cout << "Введите значения элементов в массиве:" << endl;
        for (int i = 0; i <= d.count(); ++i)
            cin >> d[i];

        cout << "Введите индекс элемента:" << endl;
        int index;
        cin >> index;
        cout << "Элемент с введенным индексом:" << endl;
        cout << d[index] << endl;

        for (int i = 0; i < d.count() - 1; ++i)
            cout << d[i] << ", ";
        cout << d[d.count() - 1] << endl;
    }
    catch (const ios_base::failure &e) {
        cerr << "Некорректный ввод: " << e.what() << endl;
    }
    catch (const domain_error &e) {
        cerr << "Неверное значение параметра: " << e.what() << endl;
    }
    catch (const out_of_range &e) {
        cerr << "Индекс наодится вне границ: " << e.what() << endl;
    }
    catch (const exception &e) {
        cerr << "Непредвиденная ошибка: " << e.what() << endl;
    }
    system("pause");
    return 0;
}
