#include <cmath>
#include <iostream>
#include <ctime> 
#include"Functions.h"

using namespace std;

int CHECKING_FUNC()
{
	double a;
	cin >> a;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please, write correct number\n";
		cin >> a;
	}
	return a;
}

int main()
{
	double a, b, c, eps, step, x, sum;
	int k;
	clock_t st1, st2, en1, en2;
	cout << "Hello, write the numbers of x" << endl;
	cin >> k;
	cout << "Write a:" << endl;
	cin >> a;
	cout << "Write b:" << endl;
	cin >> b;
	cout << "Write epsilant" << endl;
	cin >> eps;
	step = fabs(a - b) / k;
	for (int n = 0; n <= k; n++)
	{
		x = arr(a, b, n, k, step);
		sum = func1(eps, x);
		printf("%.9f", fabs(sum));
		cout << " ";
		sum = func2(eps, x);
		printf("%.9f", fabs(sum));
		cout << endl;
	}
	return 0;
}