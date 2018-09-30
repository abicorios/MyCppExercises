// c6e3map.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>
#include <set>
using namespace std;

int main()
{
	multimap<string, double> m;
	cout << "enter map like on\na 1 b 2 c 3 go\n";
	for (;;)
	{
		string s;
		double d;
		cin >> s;
		if (s == "go") break;
		//cout << "s is " << s << '\n';
		cin >> d;
		//cout << "d is " << d << '\n';
		m.insert(make_pair(s, d));
	}

	double sum = 0;
	for (multimap<string, double>::iterator it = m.begin(); it != m.end(); it++)
		sum += (*it).second;
	cout << "sum is " << sum << '\n';
	cout << "average is " << sum/m.size() << '\n';
	
	set<string> keys;
	for (multimap<string, double>::iterator it = m.begin(); it != m.end(); it++)
		keys.insert((*it).first);

	map<string, double> msum;
	map<string, double> msize;
	for (set<string>::iterator it = keys.begin(); it != keys.end(); it++)
	{
		msum[*it] = 0;
		msize[*it] = 0;
	}

	for (multimap<string, double>::iterator it = m.begin(); it != m.end(); it++)
	{
		msum[(*it).first] += (*it).second;
		msize[(*it).first]++;
	}

	for (set<string>::iterator it = keys.begin(); it != keys.end(); it++)
		cout << "sum of " << *it << " is " << msum[*it] << '\n' << "average of " << *it << " is " << msum[*it] / msize[*it] << '\n';

}

