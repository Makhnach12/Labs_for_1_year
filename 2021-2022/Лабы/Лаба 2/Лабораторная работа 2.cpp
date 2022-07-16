/*Ћабораторна€ работа 2. ¬ задании дана полседовательность, 
необходимо найти сумму тех членов последовательности, которые,наход€сь под модулем,
меньше чем их пор€дковый номер в последовательности возведенный в квадрат*/
#include <iostream>
#include<math.h>
using namespace std;

int read()
{
	int b;
	cin >> b;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please, write correct number\n";
		cin >> b;
	}
	return b;
}

int main()
	{
	int n; int n1; double a; double s;
	cout << "Write a number of members of the sequence\n" << "n=";
	//n-количество чисел в последовательности
	n=read();
	s = 0;
	n1 = 0;
	while (n > 0)
	{
		//—четчик дл€ пор€дковых номеров
		n1++;
		cout << "Write the a number " << n1 << " of sequense:";
		//вбиваем числа последовательности
		a = read();
		//провер€ем выполнение услови€
		if (abs(a) < n1 * n1)
		s= s+a;
		n=n-1;
	}
	cout<<"The sum is "<<s;
	return 0;
	}
/* Test
 n=3
 a1=1
 a2=2
 a3=3
 s=5

 n=3
 a1=1.1
 a2=1.1
 a3=1.1
 s=2.2

 n=3
 a1=-1
 a2=-2
 a3=-3
 s=-5
 
 n=4
 a1=1.1
 a2=3.7
 a3=8.7
 a4=17
 s=12.4
*/