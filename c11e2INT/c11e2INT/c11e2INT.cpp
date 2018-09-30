// c11e2INT.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
class INT
{
public:
	INT(int ii=0) :i(ii) {};
	operator int() { return i; }
private:
	int i;
};

int main()
{
	INT a, b; a = 1; b = 2;
	std::cout<< a + b<<std::endl;
}

