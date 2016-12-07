#include <fstream>
#include "vector_functions.h"

using namespace std;

void vector_capacity(vector<int>& v, size_t count)
{

    size_t cap = v.capacity();
    cout << "\tStart" << endl;
    cout << "Capacity: " << cap << "\tSize: " << v.size() << endl;

    for (int i = 0; i < count; ++i) {
        v.push_back(rand());

        if (cap != v.capacity()) {
            cap = v.capacity();
            cout << "Capacity: " << cap << "\tSize: " << v.size() << endl;
        }
    }

    cout << "\tFinal" << endl;
    cout << "Capacity: " << cap << "\tSize: " << v.size() << endl;

    v.shrink_to_fit();
    if (cap != v.capacity()) {
        cap = v.capacity();
        cout << "\tShrunk to fit!" << endl;
        cout << "Capacity: " << cap << "\tSize: " << v.size() << endl;
    }
}


vector<double> operator-(const vector<double> &v1, const vector<double> &v2)
{
    vector<double> result = v1;
    for (auto i = 0; i < result.size(); ++i)
        result[i] -= v2[i];
    return result;
}

vector<double> operator*(const vector<double> &v1, double d)
{
    vector<double> result = v1;
    for (auto i = 0; i < result.size(); ++i)
        result[i] *= d;
    return result;
}
vector<double> operator/(const vector<double> &v1, double d)
{
    vector<double> result = v1;
    for (auto i = 0; i < result.size(); ++i)
        result[i] /= d;
    return result;
}
void gauss_down(vector<vector<double>> &matrix)
{
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    for (size_t i = 0; i < cols; ++i)
        for (size_t j = i; j < rows; ++j) {
            if (matrix[j][i] == 0.0) continue;
            matrix[j] = matrix[j] / matrix[j][i];
            if (i != j)
                matrix[j] = matrix[j] - matrix[i];
        }
}

void vector_file_gen(char* filename, size_t max_n)
{
    ofstream fout(filename);
    if (!fout.is_open()) return;
    srand(max_n);
    int n = max_n;
    while (n > 0) {
        int m = rand() % max_n;
        while (m-- > 0)
            fout << rand() % max_n << '\t';
        fout << endl;
        n--;
    }
    fout.close();
}

vector<int> max_sum_vector(char *filename)
{
    vector<int> max;
    ifstream fin(filename);
    if (!fin.is_open()) throw exception("Невозможно открыть файл");
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
