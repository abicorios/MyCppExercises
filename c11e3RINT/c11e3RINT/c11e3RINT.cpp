// c11e3RINT.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
class RINT
{
public:
	RINT(int ii = 0) :i(ii) {};
	int r() { return i; }
private:
	int i;
};
RINT operator+(RINT a, RINT b)
{
	return RINT(a.r() + b.r());
}
RINT operator-(RINT a)
{
	return RINT(-a.r());
}
RINT operator-(RINT a, RINT b)
{
	return RINT(a.r() - b.r());
}
RINT operator*(RINT a, RINT b)
{
	return RINT(a.r() * b.r());
}
RINT operator/(RINT a, RINT b)
{
	return RINT(a.r() / b.r());
}
RINT operator%(RINT a, RINT b)
{
	return RINT(a.r() % b.r());
}
void p(RINT);
void p(RINT a)
{
	std::cout << a.r() << std::endl;
}
int main()
{
	RINT a, b; a = 1; b = 2;
	p(a + b);
	p(-a);
	p(a - b);
	p(a*b);
	p(a / b);
	p(a%b);
}

