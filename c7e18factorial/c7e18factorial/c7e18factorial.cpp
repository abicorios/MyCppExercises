// c7e18factorial.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int factorial(int);
int factorial(int n)
{
	int r;
	r = n;
	while(--n) r *= n;
	return r;
}

int main()
{
	cout << factorial(3) << '\n';
}

