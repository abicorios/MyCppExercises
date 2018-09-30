// c7e14.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
//#define PI = 3.14
#define PI 3.14
#define MAX(a,b) a>b?a:b
#define MAX(a,b) (a)>(b)?(a):(b)
#define FAC(a) (a)*FAC((a)-1)
#include <iostream>
using namespace std;

int main()
{
	int PING = 9;
	cout << PING << ' ' << PI << ' ' << (MAX(2, PI)) << ' ' << (MAX((MAX(1, 2)),( MAX(3, 4))));
	//FAC(3);
}

