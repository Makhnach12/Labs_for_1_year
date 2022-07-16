/*Лабораторная работа 1, задание 1.2
Нужно вычислить значение переменной x при введенных значениях а и b для выражения:a*x+b=0
*/
#include <iostream>
using namespace std;
int main()
{
	double a; double b; double x;
	cout << "Write a\n"<<"a=";
	cin >> a;
	while (std::cin.fail())//Исключение ввода данных неверного типа
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please write correct number\n"<<"a=";
		cin >> a;
	}

	cout << "Write b\n"<<"b=";
	cin >> b;
	while (std::cin.fail())//Исключение ввода данных неверного типа
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please write correct number\n"<<"b=";
		cin >> b;
	}

	if ((a == 0) && (b == 0))//При а=0 и b=0 у нас бесконечно много решений
	{
		cout << "INF"<<endl;
	}
	else if ((a == 0) && !(b == 0))//При а=0 и b<>0 у нас нет решений 
	{
		cout << "Wrong" << endl;
	}
	else if (a != 0)// При любом b, если а<>0 то считаем x
	{
		x = -(b / a);
		cout << "x="<< x << endl;
	}
	system("pause");
}
/* 
Test 
a b x
0 0 inf
0 1 NO
1 1 -1
*/