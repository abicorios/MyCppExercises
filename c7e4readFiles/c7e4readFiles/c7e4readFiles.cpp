// c7e4readFiles.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main(int argc,char* argv[])
{
	//cout << argv[0] << '\n';
	//cout << argv[1] << '\n';
	
	int i = 0;
	while (argv[++i]!=0)
	{
		//cout << argv[i] << '\n';
		//cout<<i<< '\n';
		ifstream f(argv[i]);
		//ifstream f;
		//f.open(argv[i], ios::in);
		if (!f) cerr << "cannot open\n";
		char c;
		while (f.get(c)) cout << c;
		f.close();
	}
	//cout << 48;
}

