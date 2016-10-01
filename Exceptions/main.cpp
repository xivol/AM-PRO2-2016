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
        cout << "������� ���������� ��������� � �������:" << endl;

        cin.exceptions(ios_base::failbit);
        cin >> size;
        d.resize(size);
        
        cout << "������� �������� ��������� � �������:" << endl;
        for (int i = 0; i <= d.count(); ++i)
            cin >> d[i];

        cout << "������� ������ ��������:" << endl;
        int index;
        cin >> index;
        cout << "������� � ��������� ��������:" << endl;
        cout << d[index] << endl;

        for (int i = 0; i < d.count() - 1; ++i)
            cout << d[i] << ", ";
        cout << d[d.count() - 1] << endl;
    }
    catch (const ios_base::failure &e) {
        cerr << "������������ ����" << endl;
    }
    catch (const exception &e) {
        cerr << e.what() << endl;
    }


    system("pause");
    return 0;
}
