// c7e3helloName.cpp: ���������� ����� ����� ��� ����������� ����������.
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