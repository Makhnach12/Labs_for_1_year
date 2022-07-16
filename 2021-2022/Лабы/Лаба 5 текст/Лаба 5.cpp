/*
* ������������ ������ 5.1.10 
* ��������� �������� ������ � ��������� ����� �������� ������� 
* � � ������� ������ ������� ������������ �����
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include "Functions.h"
using namespace std;

//������� ��� �������� ��������� ������ ��� ������ � ��� ������
int checking_num_of_argc(int argc, const char* f_orig, const string f_out)
{
	FILE* f_in = fopen(f_orig, "r");
	//����� ������������ �� ���� ����� ��� ������ � ������
	if (argc == 1)
	{
		cout << "�� �� ����� ����� ��� ������ ��� ��� ������";
		return 0; 
	}
	//����� ������������ ���� ������� ����� ��������� ������
	else if (argc > 3)
	{
		cout << "�� ����� ������� ����� ��������� ������";
		return 0;
	}
	//����� ������������ ������ ������������ ������ ����� ��� ������
	else if (f_out.substr(f_out.find_last_of(".") + 1) != "txt")
	{
		cout << "�� �� ������� ������ ����� ��� ������";
		return 0;
	}
	//����� ������������ ���� ��� ��������������� ����� ��� ������
	if (f_in == NULL)
	{
		printf("���� ��� ������ �� ������");
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
	//����� ������������ �� ���� ����� ��� ������ � ������
	if (argc < 3)
	{
		cout << "�� �� ����� ����� ��� ������ ��� ��� ������";
		return 0;
	}
	//������� �������� ��������� ������
	if (checking_num_of_argc(argc, argv[1], argv[2]) == 0)
		return 0;

	FILE* f_in = fopen(argv[1], "r");
	FILE* f_out = fopen(argv[2], "w");

	//������� ��� ����������� ��������� ������ � ������ ���� � ����� ����
	coding_and_writing_func(argv[1], argv[2]);
    //�������� ������������ ����������� ��� ������ �������������
	if (decoder_func(argv[1], argv[2]) == 0)
		cout << "����������� ��������� ���������";
	else 
		cout << "����������� ��������� �����������";

	fclose(f_in);
	fclose(f_out);
	return 0;
}

