/*Лабораторная работа 3.2 */
#include <iostream>
#include <cmath>
#include <ctime> 
using namespace std;

double pow(double i, double n)
{
    double i2;
    i2 = i;
    for (int k = 1; k < n; k++)
        i = i * i2;
    return (i);
}

int CHECKING_FUNC()
{
	int a;
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

int COUNT_OF_NUMBERS(int n,int k, double a, double b, double step)
{
	int n;
	double mean;
		if (n == 0)
			mean = a;
		else if (n == k)
			mean = b;
		else
			mean = a + n * step;
	return mean;
}

double func1()
{
	mem = 1;
	sum = 0;
	while (fabs(mem) > eps)
	{
		mem = ((pow(-1, i) * x * x * x) / ((i + 5) * pow(i, i)));
		if (fabs(mem) > eps)
			sum = sum + mem;
		i += 1;
	}
}

double func2()
{

}

int main()
{
    int i,k;
    double step,eps,mem,x,sum,a,b,i2,t1,t2,t3;
    clock_t st1,st2,en1,en2;
	cout << "Hello, write the numbers of x" << endl;
	k = CHECKING_FUNC();
    double* piece = new double[k];
    mem = 1;
    sum = 0;
	cout << "Write a:" << endl;
	a = CHECKING_FUNC();
	cout << "Write b:" << endl;
	b = CHECKING_FUNC();
	cout << "Write epsilant" << endl;
    eps = CHECKING_FUNC();
    step = fabs(a - b) / k;
    for (int n = 0; n <= k; n++)
    {
        if (n == 0)
            piece[n] = a;
        else if (n == k)
            piece[n] = b;
        else 
            piece[n] = a + n * step;
    }
    for (int n = 0; n <= 9; n++)
    {
        sum = 0;
        x = piece[n];
        i = 1;
        st1 = clock();
        while (fabs(mem) > eps)
        {
            mem = ((pow(-1, i) * x * x * x) / ((i + 5) * pow(i, i)));
            if (fabs(mem)>eps)
                sum = sum + mem;
            i += 1;
        }
        en1 = clock();
        t1 = en1 - st1;
        printf("%.9f", fabs(sum));
        cout << " ";
        sum = 0;
        mem = 1;
        i = 1;
        st2 = clock();
        while (fabs(mem) > eps)
        {
            i2 = 1;
            for (int k = 0; k < i; k++)
                i2 = i2 * i;
            if (i%2==0)
                mem = ((x * x * x) / ((i + 5) * i2));
            else 
                mem = ((-1*x * x * x) / ((i + 5) * i2));
            if (fabs(mem) > eps)
                sum = sum + mem;
            i += 1;
        }
        en2 = clock();
        t2 = en2 - st2;
        printf("%.9f", fabs(sum));
        t3 = t2 - t1;
        cout << " " << "Time difference=";
        printf("%.9f", t3);
        cout << endl;
        mem = 1;
    }

    return 0;
}