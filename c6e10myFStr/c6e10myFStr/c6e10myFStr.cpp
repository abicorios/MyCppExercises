// c6e10myFStr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	short strlen(char*);
	char*s1="abc";
	char*s2;
	void strcpy(char*, char*&);
	strcpy(s1, s2);
	cout << s2 << '\n';
	bool strcmp0(char*, char*);
	cout << strcmp0("abc","ab") << '\n';
}

short strlen(char*s)
{
	short l = 0;
	while (s[++l]);
	return l;
}

void strcpy(char*input, char*&output)
{
	output = input;
}

bool strcmp0(char*a, char*b)
{
	bool c = 1;
	int i;
	for (i = 0; a[i] != 0; i++) c &= (a[i] == b[i]);
	c &= !b[i];
	return c;
}