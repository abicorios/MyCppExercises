// c6e7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int i = 0;
	cout << (i++ + i++) << '\n';
	cout << (i++ * i++) << '\n';
	cout << (i++ - i++) << '\n';
	cout << (i++ / i++) << '\n';
	cout << (i++ && i++) << '\n';
}

