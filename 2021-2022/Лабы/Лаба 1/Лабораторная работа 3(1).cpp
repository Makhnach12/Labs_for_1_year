/* ������������ ������ 1. ������� 3.1
��������� �� ��������� ����������� ������� ������������ ������ �� ����� � ����������� ������� ��� ���
*/
#include <iostream>
using namespace std;
int main()
{
	double x; double y;
	cout << "Write x\n" << "x=";
	cin >> x;
	while (std::cin.fail())//���������� ����� �������� ������
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please write correct number\n"<<"";
		cin >> x;
	}
	
	cout << "Write y\n" << "y=";
	cin >> y;
	while (std::cin.fail())//���������� ����� �������� ������
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Please write correct number\n";
		cin >> y;
	}  

	if ((x < -2) && (y < x * x) && (y > (2 - x)) && (y>0))//�������� ������� ��� �������� x*x � 2-x
	{
		cout << "Yes";
	}
	else if ((x > 0) && (y < x * x) && (y < (2 - x)) && (y>0))//�������� ������� ��� �������� x*x � 2-x
	{
		cout << "Yes";
	}
	else cout << "No";
	return 0;
	system("pause");
}
/*Test 
  x=1 y=0.5 yes
  x=1 y=1 no
  x=-3 y=5.5 yes
  */
