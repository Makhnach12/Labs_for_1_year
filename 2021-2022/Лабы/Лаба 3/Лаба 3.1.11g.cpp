/*Лабораторная работа 3.1.11 Треубется найти сумму ряда и значение гиперболической 
функции arth(x), их разность, а также абсолютную величину последнего члена ряда*/
#include <iostream>
#include <cmath>
#include<windows.h>
using namespace std;

int main()
{
	int n;//знаменатель члена ряда
	double dif, arth, x, sum, mem, x2, eps,mem2;
	/*dif-разница функции и ряда, 
	arth-название переменной функции, sum-сумма функции и ряда, 
	mem,mem2-обозначения члена ряда, x2-х в квадрате,eps - эпсилант*/
	cout << "Write x and epsilant\n";
	cin >> x>> eps;
	while (std::cin.fail() || abs(x)>1)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please, write correct numbers \n";
		cin >> x>>eps;
	}

	mem = x;
	mem2 = x;
	x2 = x * x;
	n = 1;
	sum = x;
	while (fabs(mem) > eps)
	{
		//вычисление значения члена ряда
		mem = (mem * n * x2) / (n + 2);
		n = n + 2;
		if (fabs(mem) > eps)
		{
			sum = sum + mem;
			mem2 = mem;
		}
	}
	// вычилсение значения функции
	arth = (log((1 + x) / (1 - x))) / 2;

	cout << "x="<< x << " " << "Epsilant=" << eps << "\n";
	cout << "Sum=";
	printf("%.6f", sum);
	cout << endl;
	cout << "Arth(x)=";
	printf("%.6f", arth);
	cout << endl;
	dif = sum - arth;
	cout << "Difference=";
	printf("%.6f", fabs(dif));
	cout << endl;
	cout << "The value of the last member of the sequence=";
	printf("%.6f", fabs(mem2));
	cout << endl;
	system("pause");
	return 0;
}
/*Test
*x=0.8 Epsilant=0.001
Sum=1.096783
Arth(x)=1.098612
Difference=0.001829
The value of the last member of the sequence=0.001325

*x=-0.8 Epsilant=0.001
Sum=-1.096783
Arth(x)=-1.098612
Difference=0.001829
The value of the last member of the sequence=0.001325

*x=0.2 Epsilant=0.1
Sum=0.200000
Arth(x)=0.202733
Difference=0.002733
The value of the last member of the sequence=0.200000

*x=-0.123457 Epsilant=1e-11
Sum=-0.124090
Arth(x)=-0.124090
Difference=0.000000
The value of the last member of the sequence=0.000000

*x=0.11 Epsilant=1
Sum=0.110000
Arth(x)=0.110447
Difference=0.000447
The value of the last member of the sequence=0.110000

*x=0.6 Epsilant=0.001
Sum=0.692671
Arth(x)=0.693147
Difference=0.000476
The value of the last member of the sequence=0.001120

*/