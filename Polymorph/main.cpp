//
// Лабораторная работа №12. Классы. Виртуальные функции
// main.cpp
//
#include "polygon.h"
#include "triangle.h"
#include "rectangle.h"
#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
	try {
		cout << "Введите координаты треугольника:" << endl;
		triangle t = get_triangle();
		cout << "Введите координаты прямоугольника:" << endl;
		rectangle r = get_rectangle();

		cout << endl << "Работа по ссылке:" << endl;
		polygon &ref_p = t;
		ref_p.print();

		cout << "Статическое приведение типа:" << endl;
		static_cast<triangle&>(ref_p).print();
		static_cast<rectangle&>(ref_p).print();

		//cout << "Динамическое приведение типа:" << endl;
		//dynamic_cast<triangle&>(ref_p).print();
		//try {
		//	dynamic_cast<rectangle&>(ref_p).print();
		//}
		//catch (const bad_cast &e) {
		//	cout << "Невозможно привести тип" << endl;
		//}

		cout << endl << "Работа по указателю:" << endl;
        polygon *ptr_p = &r;
        ptr_p->print();

        cout << "Статическое приведение типа:" << endl;
        static_cast<triangle*>(ptr_p)->print();
        static_cast<rectangle*>(ptr_p)->print();

        //cout << "Динамическое приведение типа:" << endl;
        //dynamic_cast<rectangle*>(ptr_p)->print();
		//triangle *ptr_t = dynamic_cast<triangle*>(ptr_p);		
		//if (ptr_t != nullptr)
		//	ptr_t->print();
		//else
		//	cout << "Невозможно привести тип" << endl;

		if (typeid(ref_p) == typeid(*ptr_p))
			cout << endl << "Типы по ссылке и указателю совпадают!" << endl;
		else
			cout << endl << "Типы по ссылке и указателю не совпадают!" << endl;
    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }
    system("pause");
    return 0;
}