// c7e2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
using namespace std;

int fp(int x,int y)
{
	return x + y;
}

int fm(int x, int y)
{
	return x - y;
}

typedef int(&rifii)(int, int);

rifii f(string);
rifii f(string s)
{
	if (s == "plus") return fp;
	if (s == "minus") return fm;
}

int main()
{
	int x = f("minus")(3,4);
	printf("%d\n", x);
}

