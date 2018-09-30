// c7e1functions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"



void f1(char*, int&); void f1(char*, int&){}
void (*f2)(char*, int&)=f1;
typedef void(*f0)(char*, int&);
void f3(f0); void f3(f0 f2){}
f0 f4(); f0 f4() { return f2; }
f0 f5(f0); f0 f5(f0 f2) { return f2; }

int main()
{
    return 0;
}

