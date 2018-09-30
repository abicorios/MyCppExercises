// c6e7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	cout << (i++ + i++) << '\n';
	cout << (i++ * i++) << '\n';
	cout << (i++ - i++) << '\n';
	cout << (i++ / i++) << '\n';
	cout << (i++ && i++) << '\n';
}

