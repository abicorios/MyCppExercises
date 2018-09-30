// c8e3exceptionWithTwoFunctions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
struct zerro
{
	double y;
	zerro(double dd) { y = dd; }
};
double div(double, double);
int err();
double div(double x, double y)
{
	if (y == 0)
		throw zerro(y);
	return x / y;
}

int err()
{
	std::cerr << "do not divide by zero\n";
	return 1;
}
int main()
{
	std::cout << "enter x:\n";
	double x;
	std::cin >> x;
	std::cout << "enter y:\n";
	double y;
	std::cin >> y;
	try
	{
		std::cout << "x/y=" << div(x, y) << '\n';
	}
	catch (zerro(y))
	{
		err();
	}
	return 0;
}

