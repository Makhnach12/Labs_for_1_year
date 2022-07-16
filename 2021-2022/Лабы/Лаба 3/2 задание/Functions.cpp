#include <cmath>
#include <iostream>
#include <ctime> 

double pow(double i, double n)
{
    double i2;
    i2 = i;
    for (int k = 1; k < n; k++)
        i = i * i2;
    return i;
}

double arr(double a,double b,int n,int k, double step)
{
    double x=1;
        if (n == 0)
            x = a;
        else if (n == k)
            x = b;
        else
            x= a + n * step;
    return x;
}

double func1(double eps,double x)
{
    int i = 1;
    double sum=0,mem=1;
    while (fabs(mem) > eps)
    {
        mem = ((pow(-1, i) * x * x * x) / ((i + 5) * pow(i, i)));
        if (fabs(mem) > eps)
            sum = sum + mem;
        i += 1;
    }   return sum;
}

double func2(double eps,double x)
{
    double mem, sum;
    mem = 1;
    sum = 0;
    int i = 1;
    while (fabs(mem) > eps)
    {
        int i2 = 1;
        for (int k = 0; k < i; k++)
            i2 = i2 * i;
        if (i % 2 == 0)
            mem = ((x * x * x) / ((i + 5) * i2));
        else
            mem = ((-1 * x * x * x) / ((i + 5) * i2));
        if (fabs(mem) > eps)
            sum = sum + mem;
        i += 1;
    }
    return sum;
}
