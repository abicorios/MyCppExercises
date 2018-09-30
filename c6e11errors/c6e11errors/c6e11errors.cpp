// c6e11errors.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>;
using namespace std;


int main()
{
	void f(int, int);
	cout << "input number\n";
	int a;
	cin >> a;
	f(a, 0);
	//cout >> "abc\n";
}

void f(int a, int b)
{
	if (a = 3) cout << a << '\n';
	if (a & 077 == 0) cout << "a & 077 == 0";
	cout << "a=" << a << '\n';
	goto a;
a: a = b + 1;
	cout << "a=" << a << '\n';
}