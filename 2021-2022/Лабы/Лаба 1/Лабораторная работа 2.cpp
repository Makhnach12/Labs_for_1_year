/*������������ ������ 1, ������� 1.2
����� ��������� �������� ���������� x ��� ��������� ��������� � � b ��� ���������:a*x+b=0
*/
#include <iostream>
using namespace std;
int main()
{
	double a; double b; double x;
	cout << "Write a\n"<<"a=";
	cin >> a;
	while (std::cin.fail())//���������� ����� ������ ��������� ����
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please write correct number\n"<<"a=";
		cin >> a;
	}

	cout << "Write b\n"<<"b=";
	cin >> b;
	while (std::cin.fail())//���������� ����� ������ ��������� ����
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please write correct number\n"<<"b=";
		cin >> b;
	}

	if ((a == 0) && (b == 0))//��� �=0 � b=0 � ��� ���������� ����� �������
	{
		cout << "INF"<<endl;
	}
	else if ((a == 0) && !(b == 0))//��� �=0 � b<>0 � ��� ��� ������� 
	{
		cout << "Wrong" << endl;
	}
	else if (a != 0)// ��� ����� b, ���� �<>0 �� ������� x
	{
		x = -(b / a);
		cout << "x="<< x << endl;
	}
	system("pause");
}
/* 
Test 
a b x
0 0 inf
0 1 NO
1 1 -1
*/