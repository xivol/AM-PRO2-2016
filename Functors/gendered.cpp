#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "gendered.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("snames.txt");

	vector<string> names;
	string fio;
	while (getline(fin, fio, ';')) {
		names.push_back(fio);
}
	fin.close();

	// ��������� ����������� ���������� ��������� �������� � �������� ����
	is_gender is_male(gender::Male);
	is_gender is_female(gender::Female);
	size_t males = count_if(names.begin(), names.end(), is_male);
	size_t females = count_if(names.begin(), names.end(), is_female);
	cout << females * 1.0 / males << endl;

	// ��������� ����������� ��������� � �� �������� ����������
	is_gender is_foreign(gender::Unrecognised);
	size_t foreign = count_if(names.begin(), names.end(), is_foreign);
	cout << foreign << endl;

	// ������� �� ������� ����� � ����� ������
	vector<string> foreign_names(foreign);
	copy_if(names.begin(), names.end(), foreign_names.begin(), is_foreign);

	for (string name : foreign_names)
		cout << name << endl;

	system("pause");
	return 0;
}
