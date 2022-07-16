#include  <iostream>
#include "Functions.h"
using namespace std;

int checking_func1()
{
	int a;
	cin >> a;
	while (std::cin.fail() || a < 7)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Please, write correct number\n";
		cin >> a;
	}
	return a;
}

int checking_func2()
{
	int a;
	cin >> a;
	while (std::cin.fail())
	{
		std::cin.clear();
		fflush(stdin);
		std::cin.ignore(32767, '\n');
		std::cout << "Please, write correct number\n";
		cin >> a;
	}
	return a;
}


int main()
{
	int num,st,fin,finx,finy,stx,sty;
	cout << "Please, write the number of lines\n";
	num = checking_func1();
	cout << "Please, write the start number\n";
	st = checking_func2();
	cout << "Please, write the finish number\n";
	fin = checking_func2();
	int* coorax= new int[num];
	int* cooraxm = new int[num];
	coorax[0] = 1; coorax[num - 1] = 16 + (num - 7) * 4;
	coorax[1] = 2; coorax[num - 2] = coorax[num - 1] - 2;
	coorax[2] = 4; coorax[num - 3] = coorax[num - 2] - 3;
	coorax[3] = 7;
	cooraxm[0] = 1; cooraxm[num - 1] = 16 + (num - 7) * 4;
	cooraxm[1] = 3; cooraxm[num - 2] = cooraxm[num - 1] - 1;
	cooraxm[2] = 6; cooraxm[num - 3] = cooraxm[num - 2] - 2;
	cooraxm[3] = 10;
	cout << st << "->";
	for (int i = 4; i < (num - 3); i++)
	{
		coorax[i] = coorax[i - 1] + 4;
		cooraxm[i] = cooraxm[i - 1] + 4;
	}

	stx = number2coordinatex(num, coorax, cooraxm, st);
	finx = number2coordinatex(num, coorax, cooraxm,fin);
	sty = number2coordinatey(num, coorax, cooraxm, st);
	finy = number2coordinatey(num, coorax, cooraxm, fin);
	movefunc(st, fin, stx, finx, sty, finy, num, coorax);
	return 0;
}