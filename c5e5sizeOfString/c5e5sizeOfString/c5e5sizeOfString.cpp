// c5e5sizeOfString.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	char str[] = "a short string";
	int size_of_array = sizeof(str);
	std::cout << "str is \"" << str << "\"\n";
	std::cout << "size_of_array is " << size_of_array << '\n';
	std::cout<<"str[size_of_array-1] is "<< str[size_of_array - 1] <<" and int(str[size_of_array-1]) is "<< int(str[size_of_array - 1])<< '\n';
	std::cout << "str[size_of_array-2] is " << str[size_of_array - 2]  <<'\n';
	int size_of_string = 0;
	for (int i = 1; str[i-1] != 0; i++)size_of_string = i;
	std::cout << "size_of_string is " << size_of_string << '\n';
}

