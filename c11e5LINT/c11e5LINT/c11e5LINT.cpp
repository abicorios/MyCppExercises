// c11e5LINT.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
class LINT
{
public:
	LINT(long long ii = 0) :i(ii) {};
	long long r() { return i; }
private:
	long long i;
};
LINT operator+(LINT a, LINT b)
{
	return LINT(a.r() + b.r());
}
LINT operator-(LINT a)
{
	return LINT(-a.r());
}
LINT operator-(LINT a, LINT b)
{
	return LINT(a.r() - b.r());
}
LINT operator*(LINT a, LINT b)
{
	return LINT(a.r() * b.r());
}
LINT operator/(LINT a, LINT b)
{
	return LINT(a.r() / b.r());
}
LINT operator%(LINT a, LINT b)
{
	return LINT(a.r() % b.r());
}
void p(LINT);
void p(LINT a)
{
	std::cout << a.r() << std::endl;
}
int main()
{
	LINT a, b; a = 1; b = 2;
	p(a + b);
	p(-a);
	p(a - b);
	p(a*b);
	p(a / b);
	p(a%b);
}