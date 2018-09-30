// c5e8iterByPointer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	int a[1001];
	for (int i = 0; i <= 1000; i++)a[i] = i;
	for (int*p = a; p != &a[1001]; p++)printf("%d\n", *p);
}

