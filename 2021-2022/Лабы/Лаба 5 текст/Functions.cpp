#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;

//функция декодирования и сравнения исходного текста с декодированным
int decoder_func(const char* fname_orig, const char* fname_code)
{
	//пременная для декодированных символов в цифровом значении
	int cod;
	//переменные для сиволов в первом и втором файле соответственно
	char symb1, symb2;

	FILE* f_or = fopen(fname_orig, "r");
	FILE* f_code = fopen(fname_code, "r");

	while (1)
	{
		if (fscanf(f_or, "%c", &symb1) != 1)
		{
			fclose(f_code);
			fclose(f_or);
			return 0;
		}
		if (fscanf(f_code, "%c", &symb2) != 1)
		{
			fclose(f_code);
			fclose(f_or);
			return 0;
		}
		//для знаков пунктуации и буквы Ё(ё)
		if (symb1 == symb2)
			cod = symb1;
		//декодирование букв с ш по я(и с Ш по Я)
		else if ((int)symb1 >= -40 && (int)symb1 < -32 || (int)symb1 >= -8)
			cod = ((int)symb2 + 24);
		else
		//декодирование остальных букв
			cod = ((int)symb2 - 8);
		//если есть несовпадение выходим
		if (cod != symb1)
		{
			fclose(f_code);
			fclose(f_or);
			return 1;
		}
	}
}

//функция кодирования и записи полученного кода в текстовый документ
bool coding_and_writing_func(const char* fname_orig, const char* fname_code)
{
	//пременная для считываемых символов
	char symb = '0';

	FILE* f_in = fopen(fname_orig, "r");
	FILE* f_out = fopen(fname_code, "w");

	while (1)
	{
		//считываю символ и одновременно проверяю на конец файла
		if (fscanf(f_in, "%c", &symb) != 1)
		{
			fclose(f_in);
			fclose(f_out);
			return 0;
		}
		//если это конец строки то переходим записывать код на новую строку
		if (symb == '\n')
		    fprintf(f_out, "%s\n", "");
		//если это знак или пробел то оставляю как есть
		else if ((int)symb > 0 || symb == 'ё' || symb == 'Ё')
			fprintf(f_out, "%c", (char)symb);
		//кодирование букв с а по ч(и с А по Ч)
		else if (((int)symb < -40) || ((int)symb > -40 && abs((int)symb) <= 32 && (int)symb < -8))
			fprintf(f_out, "%c", (char)((int)symb + 264));
		//кодирование букв с ш по я(и с Ш по Я)
		else
			fprintf(f_out, "%c", (char)((int)symb + 232));
	}
}

//2 задание//

//функция подсчета максимального и минимального повторения символа 
void couter_max_min(int& maxn, int& minn, int symbs[])
{
	int max = 0, min = 10000;
	for (int i = 0; i < 64; i++)
	{
		if (symbs[i] > max)
		{
			max = symbs[i];
			//прибавляю один тк массив
			maxn = i + 1;
		}
		if (symbs[i] < min && symbs[i] != 0)
		{
			min = symbs[i];
			//прибавляю один тк массив
			minn = i + 1;
		}
	}
}

//функция перевода числового значения символа в char 
void couter_letters(int maxn, int minn)
{
	cout << "Самая часто встречающаяся буква на конце слова:" << endl;
	cout << (char)(-maxn + 256) << endl;
	cout << "Самая редко встречающаяся буква на конце слова:" << endl;
	cout << (char)(-minn + 256) << endl;
}

