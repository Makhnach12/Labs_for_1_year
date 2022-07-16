#include <stdio.h>
#include <iostream>

using namespace std;

int check(int x, int lvl)
{
    if (lvl == 1)
        return 1;
    else
    {
    if (x == 1) return check(8, lvl - 1) + check(6, lvl - 1);
    if (x == 2) return check(7, lvl - 1) + check(9, lvl - 1);
    if (x == 3) return check(4, lvl - 1) + check(8, lvl - 1);
    if (x == 4) return check(3, lvl - 1) + check(9, lvl - 1) + check(0, lvl - 1);
    if (x == 6) return check(1, lvl - 1) + check(7, lvl - 1) + check(0, lvl - 1);
    if (x == 7) return check(2, lvl - 1) + check(6, lvl - 1);
    if (x == 8) return check(1, lvl - 1) + check(3, lvl - 1);
    if (x == 9) return check(4, lvl - 1) + check(2, lvl - 1);
    if (x == 0) return check(4, lvl - 1) + check(6, lvl - 1);
    }
}

int main(int argc, char* argv[])
{
    int num, sum = 0;
    cin >> num;
    for (int i = 0; i < 10; i++){
        if (i != 0 && i != 8 && i!=5)
            sum += check(i, num);
    }
    if (num == 1)
        sum = 8;
    cout << sum;
    return 0;
}