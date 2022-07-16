/*Лабораторная работа 1, задание 1.1 
Нужно вычислить значеие выражений А и В, и их разность C(C=0-всегда, т.к выражение А равно выражению B) при подстановке переменной x, которую вводят с клавиатуры*/
#include <iostream>
#include <math.h>
#include <iomanip>
#include<windows.h>
using namespace std;
int main()
{
	double x;
	double s;
	cout << "Please, write x\n" << "x=";
	cin >> x;//Считываем переменную 
	while (std::cin.fail())//Исключение ввода данных неверного типа
	{
		std::cin.clear();
		std::cin.ignore(32767,'\n');
		cout << "Please, write correct number\n";
		cin >> x;
	}

	if ((x == 2) || (x == -2))//Если x=2 или x=-2 то нет решений 
	{
		cout << "NO\n";
		system("pause");
		return 0;
	}
	double b = pow(abs(4 - x * x), 1.0 / 3.0);//Вычисление корня 3-й степени для выражения 4-X*X
	if ((4 - x * x) < 0)
    {
		cout << "A=";//Вывод А и Б, если (4-X*X) меньше 0
		printf("%.6f", -b);
		cout << "\n" << "B=";
		printf("%.6f", -b);
		cout << "\n" << "C=0"<<endl;
	}
	else
	{
		cout << "A=";//Вывод А и Б, если (4-X*X) больше 0
		printf("%.6f", b);
		cout << "\n" << "B=";
		printf("%.6f", b);
		cout << "\n"<< "C=0"<<endl;
	}
	 system("pause");
}

/*
Test 
x A B C
2   no
-2  no
3 -1.7... -1.7... 0
2.6 -1.4... -1.4... 0
-2.6 -1.4... -1.4... 0
0.5 1.5... 1.5... 0`
*/