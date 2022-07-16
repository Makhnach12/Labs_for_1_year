/*Лабораторная работа 3.1.11 Треубется найти сумму ряда и значение гиперболической функции arth(x), их разность, а также абсолютную величину последнего члена ряда*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;//знаменатель члена ряда
	double razn, arth, x, sum, chl, x2, eps;//razn-разница функции и ряда, arth-название переменной функции, sum-сумма функции и ряда, chl-член последовательности, x2-х в квадрате,eps - эпсилант
	cout << "Write x and epsilant\n";
	cin >> x>> eps;
	while (std::cin.fail() || abs(x)>1)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please, write correct numbers \n";
		cin >> x>>eps;
	}

	chl = x;
	x2 = x * x;
	n = 1;
	sum = x;
	arth =(log ((1 + x) / (1 - x)))/2;//вычилсение значения функции
	while (chl > eps)
	{
		chl = ((chl * n * x2) / (n + 2));//вычисление значения члена ряда
		n = n + 2;
		sum = sum + chl;
	}
	cout << "x="<< x << " " << "Epsilant=" << eps << "\n";
	cout << "sum=";
	printf("%.6f", sum);
	cout << endl;
	cout << "arth(x)=";
	printf("%.6f", arth);
	cout << endl;
	razn = sum - arth;
	cout << "Difference=";
	printf("%.6f", razn);
	cout << endl;
	cout << "The value of the last member of the sequence=";
	printf("%.6f", abs(chl));
	return 0;
}
/*Test
*x=0.8 Epsilant=0.7
sum=0.970667
arth(x)=1.098612
Difference=-0.127946
The value of the last member of the sequence=0.170667

*x=-0.8 Epsilant=0.5
sum=-0.800000
arth(x)=-1.098612
Difference=0.298612
The value of the last member of the sequence=0.800000

*x=0.4 Epsilant=0.7
sum=0.400000
arth(x)=0.423649
Difference=-0.023649
The value of the last member of the sequence=0.400000

*x=0.8 Epsilant=0.1
sum=1.036203
arth(x)=1.098612
Difference=-0.062410
The value of the last member of the sequence=0.065536
*/