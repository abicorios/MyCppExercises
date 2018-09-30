// c8e8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
double positive(double);
double positive(double p)
{
	if (p > 0)return p;
	else throw p;
}

int main()
{
	for (int i = -10; i <= 10; i++)
	{
		clock_t the_time;
		double elapsed_time;
		the_time = clock();

		try
		{
			std::cout << positive(i) << '\n';
		}
		catch (double(a))
		{
			std::cerr << a << " is not positive\n";
		}
		elapsed_time = double(clock() - the_time) / CLOCKS_PER_SEC;
		std::cout << "Elapsed time " << elapsed_time << " sec.\n";
	}
}

