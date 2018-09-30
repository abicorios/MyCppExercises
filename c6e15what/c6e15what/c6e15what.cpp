// c6e15what.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	/*for(int i=7;i>0;i--)
		std::cout << "case " << i << ":		*to++ = *from++;\n";*/
	int f[] = { 1,2,3,4,5,6,7,8,9 };
	int t[9];
	for (int i = 0; i < 9; i++) t[i] = 0;
	void send(int*, int*, int);
	send(t, f, 9);
	for(int i = 0;i<9;i++)
		std::cout << t[i] << '\n';
}

void send(int* to, int* from, int count)
{
	int n = (count + 7) / 8;
	switch (count % 8)
	{
	case 0: do {*to++ = *from++;
	case 7:     *to++ = *from++;
	case 6:     *to++ = *from++;
	case 5:     *to++ = *from++;
	case 4:     *to++ = *from++;
	case 3:     *to++ = *from++;
	case 2:     *to++ = *from++;
	case 1:     *to++ = *from++;
	} while (--n > 0);
	}
}

