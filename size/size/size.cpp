// size.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	std::cout << "size of bool is "<<sizeof(bool)<<'\n';
	std::cout << "size of char is " << sizeof(char) << '\n';
	std::cout << "size of int is " << sizeof(int) << '\n';
	std::cout << "size of double is " << sizeof(double) << "\n\n";

	std::cout << "size of bool* is " << sizeof(bool*) << '\n';
	std::cout << "size of char* is " << sizeof(char*) << '\n';
	std::cout << "size of int* is " << sizeof(int*) << '\n';
	std::cout << "size of double* is " << sizeof(double*) << "\n\n";

	enum key1 {a};
	enum key5 {a1,a2,a3,a4,a5};

	std::cout << "size of 1 enum is " << sizeof(key1) << '\n';
	std::cout << "size of 5 enum is " << sizeof(key5) << '\n';
}

