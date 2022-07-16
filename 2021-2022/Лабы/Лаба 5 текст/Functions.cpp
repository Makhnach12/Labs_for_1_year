#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;

//������� ������������� � ��������� ��������� ������ � ��������������
int decoder_func(const char* fname_orig, const char* fname_code)
{
	//��������� ��� �������������� �������� � �������� ��������
	int cod;
	//���������� ��� ������� � ������ � ������ ����� ��������������
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
		//��� ������ ���������� � ����� �(�)
		if (symb1 == symb2)
			cod = symb1;
		//������������� ���� � � �� �(� � � �� �)
		else if ((int)symb1 >= -40 && (int)symb1 < -32 || (int)symb1 >= -8)
			cod = ((int)symb2 + 24);
		else
		//������������� ��������� ����
			cod = ((int)symb2 - 8);
		//���� ���� ������������ �������
		if (cod != symb1)
		{
			fclose(f_code);
			fclose(f_or);
			return 1;
		}
	}
}

//������� ����������� � ������ ����������� ���� � ��������� ��������
bool coding_and_writing_func(const char* fname_orig, const char* fname_code)
{
	//��������� ��� ����������� ��������
	char symb = '0';

	FILE* f_in = fopen(fname_orig, "r");
	FILE* f_out = fopen(fname_code, "w");

	while (1)
	{
		//�������� ������ � ������������ �������� �� ����� �����
		if (fscanf(f_in, "%c", &symb) != 1)
		{
			fclose(f_in);
			fclose(f_out);
			return 0;
		}
		//���� ��� ����� ������ �� ��������� ���������� ��� �� ����� ������
		if (symb == '\n')
		    fprintf(f_out, "%s\n", "");
		//���� ��� ���� ��� ������ �� �������� ��� ����
		else if ((int)symb > 0 || symb == '�' || symb == '�')
			fprintf(f_out, "%c", (char)symb);
		//����������� ���� � � �� �(� � � �� �)
		else if (((int)symb < -40) || ((int)symb > -40 && abs((int)symb) <= 32 && (int)symb < -8))
			fprintf(f_out, "%c", (char)((int)symb + 264));
		//����������� ���� � � �� �(� � � �� �)
		else
			fprintf(f_out, "%c", (char)((int)symb + 232));
	}
}

//2 �������//

//������� �������� ������������� � ������������ ���������� ������� 
void couter_max_min(int& maxn, int& minn, int symbs[])
{
	int max = 0, min = 10000;
	for (int i = 0; i < 64; i++)
	{
		if (symbs[i] > max)
		{
			max = symbs[i];
			//��������� ���� �� ������
			maxn = i + 1;
		}
		if (symbs[i] < min && symbs[i] != 0)
		{
			min = symbs[i];
			//��������� ���� �� ������
			minn = i + 1;
		}
	}
}

//������� �������� ��������� �������� ������� � char 
void couter_letters(int maxn, int minn)
{
	cout << "����� ����� ������������� ����� �� ����� �����:" << endl;
	cout << (char)(-maxn + 256) << endl;
	cout << "����� ����� ������������� ����� �� ����� �����:" << endl;
	cout << (char)(-minn + 256) << endl;
}

