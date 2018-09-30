// c11e1transform.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
struct X
{
	int i;
	X(int);
	X operator+(int);
};
X::X(int ii)
{
	i = ii;
}
X X::operator+(int ii)
{
	i += ii;
	return *this;
}
struct Y
{
	int i;
	Y(X);
	Y operator+(X);
	operator int();
};
Y::Y(X xx)
{
	i = xx.i;
}
Y Y::operator+(X xx)
{
	i += xx.i;
	return *this;
}
Y::operator int()
{
	return i;
}
extern X operator*(X, Y);
X operator*(X xx, Y yy)
{
	return X(xx.i*yy.i);
}
extern int f(X);
int f(X xx)
{
	return xx.i * 2 + 1;
}
X x = 1;
Y y = x;
int i = 2;
//void p(int i);
//void p(int i)
//{
//	std::cout << i << std::endl;
//}
void p(X z);
void p(X z)
{
	std::cout << z.i << std::endl;
}
int main()
{
	p(i + 10);
	//y + 10;
	//y + 10 * y;
	p(x + y + i);
	p(x*x + i);
	p(f(7));
	//f(y);
	p(y + y);
	p(106 + y);
}

