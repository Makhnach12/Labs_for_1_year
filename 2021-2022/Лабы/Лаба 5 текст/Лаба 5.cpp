/*
* Лабораторная работа 5.1.10 
* Требуется поменять первую и четвертую часть алфавита местами 
* и с помощью нового порядка закодировать текст
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "Functions.h"
using namespace std;

//функция для проверки введенных файлов для чтения и для записи
int checking_num_of_argc(int argc, const char* f_orig, const string f_out)
{
	FILE* f_in = fopen(f_orig, "r");
	//когда пользователь не ввел файлы для чтения и записи
	if (argc == 1)
	{
		cout << "Вы не ввели файлы для чтения или для записи";
		return 0; 
	}
	//когда пользователь ввел слишком много текстовых файлов
	else if (argc > 3)
	{
		cout << "Вы ввели слишком много текстовых файлов";
		return 0;
	}
	//когда пользователь указал неправильный формат файла для записи
	else if (f_out.substr(f_out.find_last_of(".") + 1) != "txt")
	{
		cout << "Вы не указали формат файла для записи";
		return 0;
	}
	//когда пользователь ввел имя несуществующего файла для чтения
	if (f_in == NULL)
	{
		printf("Файл для чтения не найден");
		return 0;
	}
	fclose(f_in);
		return 1;
}

int main(int argc, const char* argv[])
{
	//setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//когда пользователь не ввел файлы для чтения и записи
	if (argc < 3)
	{
		cout << "Вы не ввели файлы для чтения или для записи";
		return 0;
	}
	//функция проверки текстовых файлов
	if (checking_num_of_argc(argc, argv[1], argv[2]) == 0)
		return 0;

	FILE* f_in = fopen(argv[1], "r");
	FILE* f_out = fopen(argv[2], "w");

	//функция для кодирования исхожного текста и записи кода в новый файл
	coding_and_writing_func(argv[1], argv[2]);
    //проверка правильности кодирования при помощи декодировщика
	if (decoder_func(argv[1], argv[2]) == 0)
		cout << "Кодирование выполнено правильно";
	else 
		cout << "Кодирование выполнено неправильно";

	fclose(f_in);
	fclose(f_out);
	return 0;
}

