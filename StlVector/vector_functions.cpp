#include <fstream>
#include "vector_functions.h"

using namespace std;

void vector_capacity(vector<int>& v, size_t count)
{
    size_t cap = v.capacity();
    cout << "\t������" << endl;
    cout << "�������: " << cap << "\t������: " << v.size() << endl;

    for (int i = 0; i < count; ++i) {
        v.push_back(rand());

        if (cap != v.capacity()) {
            cap = v.capacity();
            cout << "�������: " << cap << "\t������: " << v.size() << endl;
        }
    }

    cout << "\t�����" << endl;
    cout << "�������: " << cap << "\t������: " << v.size() << endl;

    v.shrink_to_fit();
    if (cap != v.capacity()) {
        cap = v.capacity();
        cout << "\t��������� �������!" << endl;
        cout << "�������: " << cap << "\t������: " << v.size() << endl;
    }
}

vector<int> max_sum_vector(char *filename)
{
    vector<int> max;
    ifstream fin(filename);
    if (!fin.is_open()) throw exception("���������� ������� ����");
    long sum = LONG_MIN;
    vector<int> v;
    while (!fin.eof()) {
        v.clear();
        fin >> v;
        long s = 0;
        for (int i = 0; i < v.size(); i++)
            s += v[i];
        if (sum < s) {
            sum = s;
            max = v;
        }
    }
    return max;
}
