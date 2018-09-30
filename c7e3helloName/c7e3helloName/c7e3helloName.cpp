// c7e3helloName.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
//#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	int i = 0;
	while(argv[++i]!=0)
		cout << "Hello, " << argv[i] << "!\n";
}