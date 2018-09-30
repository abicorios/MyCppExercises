// c7e6qsort.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

struct User
{
	char* name;
	char* id;
	int dept;
};

User heads[] = { "Ritch","dmr",11271,
"Sethi","rav",11272,
"Szy","tgs",11273 };

int cmp1(const void* p, const void* q)
{
	return strcmp(static_cast<const User*>(p)->name, static_cast<const User*>(q)->name);
}

void print_id(User* v, int n)
{
	for (int i = 0; i < n; i++)
		cout << v[i].name << '\t' << v[i].id << '\t' << v[i].dept << '\n';
}


int main()
{
	qsort(heads, 3, sizeof(User), cmp1);
	print_id(heads, 3);
}

