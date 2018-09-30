// declarations.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	double mysqrt(double);
	extern int error_number;
	struct User;
	struct User { char* s; };
	User u1;
	u1.s = "abc";

	std::cout << mysqrt(2)<<" "<<error_number<<u1.s<<'\n';

	int count;
	double pi;
	const char* name;
	//char* season[];
	struct Date;



}

double mysqrt(double x) {return sqrt(x);}
int error_number = 0;
