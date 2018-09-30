// c6e13cat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char* cat(char*, char*);
	cout << cat("ab","cd") << '\n';
	
}


char* cat(char*x, char*y)
{
	char* z = new char[strlen(x) + strlen(y) + 1];
	for (short i = 0; i < strlen(x); i++) z[i] = x[i];
	for (short i = strlen(x); i < (strlen(x) + strlen(y)); i++) z[i] = y[i- strlen(x)];
	z[strlen(x) + strlen(y)] = 0;
	return z;
}