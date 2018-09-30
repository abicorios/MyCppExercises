// c5e8iterByIndex.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	int a[1001];
	for (int i = 0; i <= 1000; i++)a[i] = i;
	for (int i = 0; i <= 1000; i++) printf("%d\n", a[i]);
}

