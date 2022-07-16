#include <cmath>
#include <iostream>
#include <ctime> 
#include "Functions.h"

//������� ��� ���������� � �������
double pow(double i, double n)
{
    double i2;
    i2 = i;
    for (int k = 1; k < n; k++)
        i = i * i2;
    return i;
}

//������� ��� ���������� �������� ������� � ������������ ���������(��������� ���. ������� ��������)
double func1(double eps,double x)
{
    //i-�������� � �������
    int i = 1;
    //mem-�������� ������� ��� ������������ i
    //sum-����� �������� ������� ��� ������������ x
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

//������� ��� ���������� �������� ������� � ������������ ���������(�� ��������� ���. ������� ��������)
double func2(double eps,double x)
{
    //mem-�������� ������� ��� ������������ i
    //sum-����� �������� ������� ��� ������������ x
    double mem=1, sum=0;
    //i-�������� � �������
    int i = 1;
    int i2 = 1;
    while (fabs(mem) > eps)
    {
        //i2-��������������� ���������� ��� ������������ �������
        i2 = 1;
        //����������� ������� �����, ��������� ����
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

//������� ����������
void tabulator(function_ptr func,double a, double b, double eps, int n)
{
    //��������� ��� � ������ ����� ����� ����� �� �������
    double step = (b - a) / n;
    //������
    double st1 = clock();
    for (double i = a; fabs(i) <= fabs(b); i += step)
    {
        std::cout<< i << " " << func(eps, i) << std::endl;
    }
    double en1 = clock();
    //������� �����
    std::cout << "Working time-" << (double)(en1 - st1) / CLOCKS_PER_SEC << std::endl;
}
