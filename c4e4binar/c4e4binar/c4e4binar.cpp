// c4e4binar.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	for (short a = 0; a <= 1; a++)
		for(short b = 0; b <= 1; b++)
			cout << a << "&" << b << "=" << (a & b) << '\n';
	cout << '\n';

	for (short a = 0; a <= 1; a++)
		for (short b = 0; b <= 1; b++)
			cout << a << "^" << b << "=" << (a ^ b) << '\n';
	cout << '\n';

	for (short a = 0; a <= 1; a++)
		for (short b = 0; b <= 1; b++)
			cout << a << "|" << b << "=" << (a | b) << '\n';
	cout << '\n';
}

