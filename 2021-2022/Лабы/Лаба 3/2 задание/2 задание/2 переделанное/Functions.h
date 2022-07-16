#ifndef FUNCTIONS_H
#define FUNCTIONS_H
//функци€ дл€ вычислени€ степени 
double pow(double i, double n);

//функци€ дл€ вычислени€ занчени€ функции с определенной точностью(использу€ доп. функцию степении)
double func1(double eps, double x);

//функци€ дл€ вычислени€ занчени€ функции с определенной точностью(не использу€ доп. функцию степении)
double func2(double eps, double x);

typedef double(*function_ptr)(double, double);

//функци€ дл€ табулировани€
void tabulator(function_ptr func, double a, double b, double eps, int n);

#endif //FUNCTIONS_H
