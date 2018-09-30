// c5e6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	void f(char);
	void g(char&);
	void h(const char&);

	char a = 'a';
	f(a); g(a); h(a);

	std::cout << '\n';
 
	char a49 = 49;
	f(49); g(a49); h(49);

	std::cout << '\n';

	char c3300 = 3300;
	f(c3300); g(c3300); h(c3300);

	std::cout << '\n';

	char c = 'c';
	f(c); g(c); h(c);

	std::cout << '\n';

	unsigned char uc = 'u';
	f(uc); h(uc);

	std::cout << '\n';

	signed char sc = 's';
	f(sc);
}

void f(char mychar)
{
	std::cout<<"f print " << mychar << '\n';
}

void g(char&mychar)
{
	std::cout << "g print " << mychar << '\n';
}

void h(const char&mychar)
{
	std::cout << "h print " << mychar << '\n';
}