// c7e5cToCpp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
//#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n, i, flag = 0;

	//printf("Enter a positive integer: ");
	cout << "Enter a positive integer: ";
	//scanf("%d", &n);
	cin >> n;

	for (i = 2; i <= n / 2; ++i)
	{
		// condition for nonprime number
		if (n%i == 0)
		{
			flag = 1;
			break;
		}
	}

	if (flag == 0)
		//printf("%d is a prime number.", n);
		cout << n << " is a prime number.\n";

	else
		//printf("%d is not a prime number.", n);
		cout << n << " is not a prime number.\n";

	return 0;
}