#include <cmath>
#include <iostream>
#include <ctime> 
#include "Functions.h"

//функци€ дл€ возведени€ в степень
double pow(double i, double n)
{
    double i2;
    i2 = i;
    for (int k = 1; k < n; k++)
        i = i * i2;
    return i;
}

//функци€ дл€ вычислени€ занчени€ функции с определенной точностью(использу€ доп. функцию степении)
double func1(double eps,double x)
{
    //i-параметр в функции
    int i = 1;
    //mem-значение функции при определенном i
    //sum-сумма значений функции при определенном x
    double sum=0,mem=1;
    while (fabs(mem) > eps)
    {
        mem = ((pow(-1, i) * x * x * x) / ((i + 5) * pow(i, i)));
        if (fabs(mem) > eps)
            sum = sum + mem;
        i += 1;
    }
    return sum;
}

//функци€ дл€ вычислени€ занчени€ функции с определенной точностью(не использу€ доп. функцию степении)
double func2(double eps,double x)
{
    //mem-значение функции при определенном i
    //sum-сумма значений функции при определенном x
    double mem=1, sum=0;
    //i-параметр в функции
    int i = 1;
    int i2 = 1;
    while (fabs(mem) > eps)
    {
        //i2-вспомогательна€ переменна€ дл€ высчитывани€ степени
        i2 = 1;
        //высчитываем степень числа, использу€ цикл
        for (int st = 0; st < i; st++)
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

//функци€ табул€тора
void tabulator(function_ptr func,double a, double b, double eps, int n)
{
    //вычисл€ем шаг с кторым будем брать числа из отрезка
    double step = (b - a) / n;
    //таймер
    double st1 = clock();
    for (double i = a; fabs(i) <= fabs(b); i += step)
    {
        std::cout<< i << " " << func(eps, i) << std::endl;
    }
    double en1 = clock();
    //выводим врем€
    std::cout << "Working time-" << (double)(en1 - st1) / CLOCKS_PER_SEC << std::endl;
}
