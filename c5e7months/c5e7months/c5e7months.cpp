// c5e7months.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	char m[] = "jfmaMJuAsond";
	int n[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1; i <= 12; i++)std::cout << i << '\t' << n[i-1] << '\n';
	for (int i = 1; i <= 12; i++)std::cout << m[i-1] << '\t' << n[i - 1] << '\n';
	struct MnD
	{
		char* month;
		unsigned short int days;
	};
	MnD table[12];
	table[0].month = "January";
	table[1].month = "February";
	table[2].month = "March";
	table[3].month = "April";
	table[4].month = "May";
	table[5].month = "June";
	table[6].month = "July";
	table[7].month = "August";
	table[8].month = "September";
	table[9].month = "October";
	table[10].month = "November";
	table[11].month = "December";
	for (int i = 1; i <= 12; i++)table[i - 1].days = n[i - 1];
	for (int i = 1; i <= 12; i++)std::cout << table[i - 1].month << "\t\t" << table[i - 1].days << '\n';
}

