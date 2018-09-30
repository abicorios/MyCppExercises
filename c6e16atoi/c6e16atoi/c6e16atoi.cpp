// c6e16atoi.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
//#include <string>
using namespace std;

int main()
{
	int atoi(char*);
	cout << atoi("45") << " " << 45 << '\n';
	cout << atoi("077") << " " << 077 << '\n';
	cout << atoi("0xf")<<" "<< 0xf << '\n';
}

int atoi(char*c)
{
	int l= strlen(c);
	int number = 0;
	int d(char);
	if(c[0]!='0')
		for (int i = 0; i < l; i++) number += d(c[l-i-1]) * pow(10, i);
	else
		if(c[0]== '0' && c[1]!='x')
			for (int i = 1; i < l; i++) number += d(c[l - i]) * pow(8, i-1);
		else
			if(c[0] == '0' &&  c[1] == 'x')
				for (int i = 2; i < l; i++) number += d(c[l - i+1]) * pow(16, i - 2);
			else
			{
				cout << "myerror, it is not a number\n";
				return 0;
			}
	
	return number;
}

int d(char c)
{
	if (c >= '0'&&c <= '9')
		return c - '0';
	else
		if (c >= 'a'&&c <= 'f')
			return c - 'a'+10;
		else
			if (c >= 'A'&&c <= 'F')
				return c - 'A'+10;
			else
			{
				cout << "myerror, it is not a number\n";
				return 0;
			}
}
