// c5e10months.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char* months[12] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	void p(char*[]);
	p(&months[0]);
}

void p(char*m[])
{
	for (short i = 0; i < 12; i++) cout << *(m + i) << '\n';
}