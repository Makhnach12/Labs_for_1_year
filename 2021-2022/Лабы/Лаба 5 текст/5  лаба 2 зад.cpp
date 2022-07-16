//Лабораторная работа 5.2.7 
//Требуется найти и вывести самые часто встречающийся и редко встречающийся символы в конце слова
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include "Functions.h"
using namespace std; 

int main(int argc, const char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//массив для строчных букв
	int symbs[64] = {0};
	//переменные для символов
	char symb1, symb2 = '0';
	/*переменные для хранения числового значения 
	самых часто и редко встречающихся букв в конце слова*/
	int maxn = 0, minn = 0;
	//проверка на количество введенных текстовых файлов
	if (argc == 1 || argc > 2)
	{
		printf("Вы не ввели имя тесктового файла или напсиали слишком много тесктовых файлов");
		return 0;
	}

	FILE* f_in = fopen(argv[1], "r");
	 
	if (f_in == NULL)
	{
		printf("Файл не найден");
		return 0;
	}

	//посимвольно идем по тексту и считываем символы
	while (1)
	{
		//проверка на конец файла и присваивание переменной значения прочитанного символа
		if (fscanf(f_in, "%c", &symb1) != 1)
			break;
		//если после символа стоит не буква то прибавляем к значению этого символа в массиве +1
		if ((int)symb2 <= -1 && (int)symb1 >= 0)
			symbs[abs((int)(symb2))-1] += 1;
		symb2 = symb1;
	}

	//функция для подсчета максимального и минимального значений массива
	couter_max_min(maxn, minn, symbs);
	//переводим букву из int в char
	couter_letters(maxn, minn);

	fclose(f_in);
	return 0;
}
 