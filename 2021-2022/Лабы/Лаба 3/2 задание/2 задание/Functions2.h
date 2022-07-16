#pragma once

double pow(double i, double n);
double func1(double eps, double x);
double func2(double eps, double x);
typedef double(*function_ptr)(double, double);
void tabulator(function_ptr func, double a, double b, double eps, int n);
