// c7e8array2d.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> tr(vector<vector<int>>);
vector<vector<int>> tr(vector<vector<int>> m)
{
	int sz = m[0].size();
	vector<vector<int>> m0(sz, vector<int>(sz));
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
			m0[i][j] = m[j][i];
	}
	
	return m0;
}
void pr(vector<vector<int>>);
void pr(vector<vector<int>> m)
{
	int sz = m[0].size();
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
			cout << m[i][j] << '\t';
		cout << '\n';
	}
}
int main()
{
	int sz = 3;
	vector<vector<int>> m(sz, vector<int>(sz));
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz; j++)
			m[i][j] = 10 * i + j;
	}
	vector<vector<int>> mt(sz, vector<int>(sz));
	mt = tr(m);
	pr(m);
	cout << '\n';
	pr(mt);
}

