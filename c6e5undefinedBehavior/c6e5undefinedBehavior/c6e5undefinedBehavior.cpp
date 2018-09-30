// c6e5undefinedBehavior.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
    //undefined behavior
	//1
	int i = 5;
	i = ++i + ++i;
	cout << i << '\n';

	//2
	char c[5];
	cout << c[10] << '\n';

	//3
	char*c1="abc";
	cout << c1[10] << '\n';

	//4
	i++ * ++i;
	cout << i << '\n';

	//5
	i = ++i;
	cout << i << '\n';

	
	//implementation-defined behavior

	//1
	cout << sizeof(char) << '\n';

	//2
	cout << sizeof(int) << '\n';

	//3
	cout << sizeof(double) << '\n';

	//4
	cout << sizeof(signed) << '\n';

	//5
	cout << sizeof(unsigned) << '\n';
}

