//
// Лабораторная работа №13. Классы. Абстрактный класс
// main.cpp
//
#include "shape.h"
#include "triangle.h"
#include "rectangle.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	try {
		const int n = 2;
		shape *shapes[n];
		cout << "Введите координаты треугольника:" << endl;
		shapes[0] = new triangle(get_triangle());
		cout << "Введите координаты прямоугольника:" << endl;
		shapes[1] = new rectangle(get_rectangle());

		for (int i = 0; i < n; ++i)
			cout << *shapes[i] << endl;

		for (int i = 0; i < n; ++i)
			delete shapes[i];
	}
	catch (const exception &e) {
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}