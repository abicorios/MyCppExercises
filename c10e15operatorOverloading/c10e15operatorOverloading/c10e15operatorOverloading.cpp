// c10e15operatorOverloading.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
std::ostream&operator<<(std::ostream&o,const char*s)
{
	printf("Initialize\n%sClean up\n",s);
	return o;
}

int main()
{
	std::cout << "Hello, world!\n";
}