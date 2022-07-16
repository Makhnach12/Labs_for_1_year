//������������ ������ 5.2.7 
//��������� ����� � ������� ����� ����� ������������� � ����� ������������� ������� � ����� �����
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
	//������ ��� �������� ����
	int symbs[64] = {0};
	//���������� ��� ��������
	char symb1, symb2 = '0';
	/*���������� ��� �������� ��������� �������� 
	����� ����� � ����� ������������� ���� � ����� �����*/
	int maxn = 0, minn = 0;
	//�������� �� ���������� ��������� ��������� ������
	if (argc == 1 || argc > 2)
	{
		printf("�� �� ����� ��� ���������� ����� ��� �������� ������� ����� ��������� ������");
		return 0;
	}

	FILE* f_in = fopen(argv[1], "r");
	 
	if (f_in == NULL)
	{
		printf("���� �� ������");
		return 0;
	}

	//����������� ���� �� ������ � ��������� �������
	while (1)
	{
		//�������� �� ����� ����� � ������������ ���������� �������� ������������ �������
		if (fscanf(f_in, "%c", &symb1) != 1)
			break;
		//���� ����� ������� ����� �� ����� �� ���������� � �������� ����� ������� � ������� +1
		if ((int)symb2 <= -1 && (int)symb1 >= 0)
			symbs[abs((int)(symb2))-1] += 1;
		symb2 = symb1;
	}

	//������� ��� �������� ������������� � ������������ �������� �������
	couter_max_min(maxn, minn, symbs);
	//��������� ����� �� int � char
	couter_letters(maxn, minn);

	fclose(f_in);
	return 0;
}
 