// c10e13SimbolTable.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
typedef std::string str;
class Simbol
{
public:
	Simbol(str n, str v) { name = n; value = v; }
	str name;
	str value;
};
class SimbolTable
{
public:
	SimbolTable() {}
	void insert(str n, str v = "") { simbols.push_back(Simbol(n, v)); }
	str reed(str n)
	{
		for (auto vi : simbols)
			if (vi.name == n)
				return vi.value;
	}
private:
	std::vector<Simbol> simbols;
};

int main()
{
	SimbolTable t;
	t.insert("a", "b");
	std::cout << t.reed("a") << std::endl;
}

