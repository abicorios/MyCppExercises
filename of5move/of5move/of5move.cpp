// of5move.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int a = 1;
	int b = 2;
	void f(int*, int*);
	f(&a, &b);
	std::cout << "a=" << a << "; b=" << b << '\n';

	int c = 3;
	int d = 4;
	void g(int&, int&);
	g(c, d);
	std::cout << "c=" << c << "; d=" << d<<'\n';
}

void f(int*x,int*y)
{
	int z = *x;
	*x = *y;
	*y = z;
}

void g(int&x, int&y)
{
	int z = x;
	x = y;
	y = z;
}