// c7e16print.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>
using namespace std;

void print(int, int base = 10);
void print(int x, int base)
{
	switch (base)
	{
	case 10:
		cout << x << ' ';
		break;
	case 16:
		cout << hex << x << ' ';
		break;
	case 8:
		cout << oct << x << ' ';
		break;
	case 2:
		cout << bitset<8*sizeof(x)>(x)<<' ';
		break;
	default:
		break;
	}
	
}

int main()
{
	print(-1, 2);
	print(-2, 2);
	print(-3, 2);
	cout << '\n';
	print(10);
	print(10, 10);
	print(10, 8);
	print(10, 16);
	cout << '\n';
}

