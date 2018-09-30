// simbols.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	for (char c = 'a'; c < 'z' + 1; c++) std::cout << c <<'\t'<<int (c)<< '\n';
	for (char n = '0'; n < '9' + 1; n++) std::cout << n << '\t' << int(n) << '\n';
	for (int i = 0; i <=255; i++) std::cout << char(i) << '\t' << std::dec << i << '\t'<< std::hex<<i<<'\n';
}