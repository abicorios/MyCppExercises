// c10e17.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
class One
{
public:
	static double x;
};
double One::x = 3.1415;
class Two
{
public:
	static double& y;
};
double&Two::y = One::x;

int main()
{
	Two t;
	std::cout << t.y<<std::endl;
}

