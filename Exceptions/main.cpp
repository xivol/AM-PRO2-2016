#include "dyn_array.h"
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");    
    try {   
        int size = INT32_MAX;
        cout << "������� ���������� ��������� � �������:" << endl;
        
        cin.exceptions(ios_base::failbit);
        cin >> size;
        dyn_array d(size);

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
        cerr << "������������ ����: " << e.what() << endl;
    }
    catch (const domain_error &e) {
        cerr << "�������� �������� ���������: " << e.what() << endl;
    }
    catch (const out_of_range &e) {
        cerr << "������ �������� ��� ������: " << e.what() << endl;
    }
    catch (const exception &e) {
        cerr << "�������������� ������: " << e.what() << endl;
    }


    system("pause");
    return 0;
}
