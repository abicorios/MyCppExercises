// c10e6random.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <iostream>
class Random
{
public:
	Random(long long sd=0);
	void draw();
	long long seed;
	double un;
private:
	long long number;
	long long before;
	long long next(long long);
	long long a = 69069;
	long long c= 1;
	long long m=pow(2,32);
};
class RandomE
{
public:
	RandomE(long long sd = 0);
	long long seed;
	void draw();
	double en;
private:
	Random r;
	double un_to_e(double);
	double l = 0.5;
};

double RandomE::un_to_e(double r0)
{
	
	return -log(r0)/l;
		//l*exp(l*r0);
}
RandomE::RandomE(long long sd)
{
	seed = sd;
	r=Random(seed);
	en = un_to_e(r.un);
}
void RandomE::draw()
{
	r.draw();
	en = un_to_e(r.un);
}
long long Random::next(long long x)
{
	//std::cout << m << std::endl;
	return (a*x + c) % m;
}

Random::Random(long long sd)
{
	seed = sd;
	number = seed;
	un = double(number) / double(m);
}

void Random::draw()
{
	number = next(number);
	un = double(number) / double(m);
}

int main()
{
	Random r;
	for (int i = 0; i < 100; i++)
	{
		r.draw();
		std::cout << r.un << std::endl;
	}
	std::cout << "-----" << std::endl;
	RandomE z;
	for (int i = 0; i < 100; i++)
	{
		z.draw();
		std::cout << z.en << std::endl;
	}
}

