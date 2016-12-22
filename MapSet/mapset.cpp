#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;
int main()
{    
    setlocale(LC_ALL, "Rus");

    ifstream fin("mapset.cpp");
    // ������� ��� ������� �� �����
    set<char> chars;
    char c;
    while (fin >> c)
        chars.insert(c);
    fin.close();
    cout << "��� ������ �����" << endl;
    for (char c : chars)
        cout << c << ", ";
    cout << endl;

    // ��������� �� ��������� �������� ��������������� �������
    string delim = " .!?,:;-=+_#()[]{}<>\\\/\'\"";
    set<char> ex(delim.begin(), delim.end());

    set<char> result;
    set_difference(chars.begin(), chars.end(), ex.begin(), ex.end(),
        inserter(result, result.end()));

    cout << "��������� ��� ��������������� ��������" << endl;
    for (char c : result)
        cout << c << ", ";
    cout << endl;

    // ��������� ���������� ���������� ���� � �����
    map<string, int> words;
    fin.open("input.txt");
    string word;
    while (fin >> word) {
        // ������� ����� � ������� ��������
        transform(word.begin(), word.end(), word.begin(), tolower);
        // ������ ����� ���������� �� ����� �����
        if (ex.find(word[word.length()-1]) != ex.end()) {
            word.erase(word.length()-1);
        }
        words[word] += 1;
    }
    fin.close();

    for (pair<string, int> elem : words)
        cout << elem.first << "\t: " << elem.second << endl;

    system("pause");
    return 0;
}