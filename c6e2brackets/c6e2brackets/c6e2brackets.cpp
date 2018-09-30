// c6e2brackets.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int main()
{
	int a;
	int b = 1;
	int c = 2;
	int d = 3;
	a = (((b + (c* d))<<2) & 8);
	cout << a << '\n';
	cout << ((b + (c* d)) << 2) << '\n';
	cout << (b + c* d << 2) << '\n';
	cout << '\n';

	cout << (a& (077 != 3)) << '\n';
	cout << '\n';

	cout << ((a==b)||(a==c)&&(c<5)) << '\n';
	cout << '\n';

	int x = 4;
	cout << (c = x != 0) << '\n';
	cout << (c = (x != 0)) << '\n';
	cout << '\n';

	int i = 5;
	cout << (0 <= i < 7) << '\n';
	cout << (0 <= (i < 7)) << '\n';
	cout << '\n';

	int f(int, int);
	cout<<(f(1,2)+3) << '\n';
	cout << '\n';

	int l = 1;
	cout << (a = - l + +b - -5) << '\n';
	cout << (a = (-l) + (+b) - (-5)) << '\n';
	cout << '\n';

	a = b == c++;
	a = b = c = 0;
	a = (b = (c = 0));

	int a1[5][3];
	for (int i = 0; i < 5; i++) for (int j = 0; j < 3; j++) a1[i][j] = 1;
	int*b1 = &b;
	int*d1 = &d;
	cout << "a1[4][2] is " << a1[4][2] << '\n';
	a1[4][2] *= *b1 ? c : *d1 * 2;
	cout << "a1[4][2] is " << a1[4][2] << '\n';
	cout << a1[4][2] << '\n';
	a1[4][2] = 1;
	a1[4][2] *= ((*b1) ? c : ((*d1) * 2));
	cout << a1[4][2] << '\n';
	cout << '\n';

	a = 1; b = 2; c = 3; d = 4;
	a = b, c = d;
	cout << "a is " << a << '\n';
	cout << "c is " << c << '\n';

	a = 1; b = 2; c = 3; d = 4;
	(a = b), (c = d);
	cout << "a is " << a << '\n';
	cout << "c is " << c << '\n';
}

int f(int x, int y)
{
	return x + y;
}