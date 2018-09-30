// c6e17itoa.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
char* itoa0(int);
int len(int);
void xtoy(int, int&);
void itoa(int, char*&);

int main()
{
	//char* itoa0(int i);
	//int len(int);
	cout << itoa0(12)<<'\n';
	int a = 1;
	int b = 2;
	xtoy(a, b);
	cout << b << '\n';
	char*f = "abc";
	char*t;
	itoa(48, t);
	cout << t << '\n';
}


int len(int number)
{
	int l = 1;
	while (number /= 10) l++;
	return l;
}


char* itoa0(int i)
{
	//int len(int);
	int l = len(i);
	char*b = new char[l + 1];
	for (int j = 0; j < l; j++)
	{
		b[l - j-1] = char(i % 10 + '0');
		i /= 10;
	}
	b[l] = 0;
	return b;
}

void xtoy(int x, int &y)
{
	y = x;
}

//void itoa(int i, char* &b)
void itoa(int i, char*&b)
{
	b = itoa0(i);
}