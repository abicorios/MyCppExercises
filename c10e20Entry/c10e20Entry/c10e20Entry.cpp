// c10e20Entry.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
enum Type {S,I};
class Entry
{
public:
	char* name;
	Type t;
	void set(std::stringstream r)
	{
		if (t == S) r >> s;
		else r >> i;
	}
	std::stringstream reed()
	{
		std::stringstream r;
		if (t == S) r << s;
		else r << i;
		return r;
	}
	
private:
	union
	{
		char* s;
		int i;
	};
	
};
void f(Entry* p)
{
	if (p->t == S)std::cout << p->reed().str();
}

int main()
{
	
}