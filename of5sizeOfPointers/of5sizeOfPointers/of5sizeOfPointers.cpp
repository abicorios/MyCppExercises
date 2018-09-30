// of5sizeOfPointers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	char array_of_char[] = { 'a','b','c','d','a','b','c','d' ,'a','b','c','d','a','b','c','d' };
	std::cout <<"&array_of_char[0] is "<< &array_of_char[0]<<'\n';
	std::cout << "&array_of_char[1] is " << &array_of_char[1] << '\n';

	int array_of_int[] = { 0,1 };
	std::cout << "&array_of_int[0] is " << &array_of_int[0] << '\n';
	std::cout << "&array_of_int[1] is " << &array_of_int[1] << '\n';

	
	void* a=0;
	std::cout <<"void is "<<  a;

}

