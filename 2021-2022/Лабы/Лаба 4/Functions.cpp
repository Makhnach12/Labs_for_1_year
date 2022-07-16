#include  <iostream>

using namespace std;

int number2coordinatex(int num, int coorax[], int cooraxm[], int a)
{
	int x;
	for (int i = 0; i < num; i++)
		if (a >= coorax[i] && a <= cooraxm[i])
		{
			x = a - coorax[i];
			break;
		}
	return x;
}

int number2coordinatey(int num, int coorax[], int cooraxm[], int a)
{
	int y;
	for (int i = 0; i < num; i++)
		if (a >= coorax[i] && a <= cooraxm[i])
		{
			y = i;
			break;
		}
	return y;
}

int movefunc(int st, int fin, int stx, int finx, int sty, int finy, int num, int coorax[])
{
	while (st != fin)
	{
		if (finx > stx && finy > sty)
		{
			if (sty<3 || sty>coorax[num - 4])
			{
				stx += 1; sty += 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
			else
			{
				sty += 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
		}
		else if (finx >= stx && finy < sty)
		{
			if (sty != 3 && sty != 2 && sty != 1)
			{
				sty -= 1;
				if (sty >= num - 4)
					stx += 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
			else if (st != 7 && st != 4 && st != 2)
			{
				sty -= 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
			else if (st == 7 || st == 4 || st == 2)
			{
				sty -= 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
		}
		else if (finx <= stx && finy > sty)
		{
			if (sty != num - 2 && sty != num - 3 && sty != num - 4)
			{
				sty += 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
			else if (st != coorax[num - 2] && st != coorax[num - 3] && st != coorax[num - 4])
			{
				if (stx > finx)
					stx -= 1;
				sty += 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
			else
			{
				sty += 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
		}
		else if (finx < stx && finy < sty)
		{
			if (sty <= 3 || sty >= coorax[num - 4])
			{
				stx -= 1; sty -= 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
			else
			{
				sty -= 1;
				st = coorax[sty] + stx;
				cout << st << "->";
			}
		}
		else if (finy == sty)
		{
			if (fin > st)
			{
				st += 1;
				cout << st << "->";
			}
			else if (st > fin)
			{
				st -= 1;
				cout << st << "->";
			}
		}

	}
	return 0;
}