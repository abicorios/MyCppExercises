// c8e6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>

struct zerro
{
	int y;
	zerro(int ii) { y = ii; }
};
int count = 0;
int fib(int, int&c = count);
int fib(int n, int&c)
{
	c++;
	if (n < 1)
		throw zerro(c);
	//std::cout << "count=" << count << "; n=" << n << '\n';
	if (n == 1 || n == 2) return 1;
	else return fib(n - 1) + fib(n - 2);
}


int before(int, int mem = 0, int&c = count);
int before(int m, int mem, int&c)
{
	c++;
	if (mem == 0) mem = m;
	//try
	//{
	if (fib(m) < mem) return fib(m);
	else return before(m - 1, mem);
	//}
	//catch (zerro(m))
	//{
	//	std::cerr << "i of fib_i must be positive\n";
	//}

}

int runner(int, int&c = count);
int runner(int x, int&c)
{
	c++;
	if (x <= 1) return before(x);
	if (x > 1) return runner(x - 1);
}

int main()
{
	for (int jj = 200; jj > -20; jj--)
	{
		count = 1;
		clock_t the_time;
		double elapsed_time;

		the_time = clock();

		try
		{
			std::cout << runner(jj) << '\n';
		}
		catch (zerro(q))
		{
			std::cerr << "i of fib_i must be positive\nerror in run " << q.y << '\n';
		}

		elapsed_time = double(clock() - the_time) / CLOCKS_PER_SEC;
		std::cout << "Elapsed time " << elapsed_time << " sec.\n";
	}
}

