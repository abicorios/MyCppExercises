// c6e14rev.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	char*a = "abc";
	char* rev(char*);
	std::cout << rev(a) << '\n';
}

char* rev(char*s)
{
	int l = strlen(s);
	char*r = new char[l];
	for (int i = 0; i < l; i++) r[i] = s[l - 1 - i];
	r[l] = 0;
	return r;
}