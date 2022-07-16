#include "Class.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	arts ob;
	arts ob_2;
	cin >> ob;
	arts ob_3(ob);
	cout << ob;
	cout << ob_3;
	ob--;
	cin >> ob_2;
	if (ob_2 > ob)
		cout << ob_2;
	else
		cout << ob;

	return 0;
}