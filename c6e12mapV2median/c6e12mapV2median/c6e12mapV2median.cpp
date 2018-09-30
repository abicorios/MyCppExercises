// c6e12mapV2median.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>
#include <vector>
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

	map<string, vector<double>> sv;
	for (multimap<string, double>::iterator it = m.begin(); it != m.end(); it++)
		sv[(*it).first].push_back((*it).second);//sv - string to vector map

	vector<double> gv;
	for (multimap<string, double>::iterator it = m.begin(); it != m.end(); it++)
		gv.push_back((*it).second);//gv - grand vector, all elements

	double fsum(vector<double>);
	double sum = fsum(gv);
	//for (multimap<string, double>::iterator it = m.begin(); it != m.end(); it++)
	//	sum += (*it).second;
	cout << "sum is " << sum << '\n';
	cout << "average is " << sum / gv.size() << '\n';
	
	
	double median(vector<double>);
	cout << "median is " << median(gv) << '\n';

	for (map<string, vector<double>>::iterator it = sv.begin(); it != sv.end(); it++)
	{
		cout << "sum of " << (*it).first << " is " << fsum((*it).second) << '\n';
		cout << "average of " << (*it).first << " is " << fsum((*it).second)/ ((*it).second).size() << '\n';
		cout << "median of " << (*it).first << " is " << median((*it).second) << '\n';
	}
}

double median(vector<double> v)
{
	double me;
	if (v.size() % 2 == 1)
		me = v[(v.size() - 1) / 2];
	else
		me = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
	return me;
}

double fsum(vector<double> v)
{
	double sum = 0;
	for (vector<double>::iterator it = v.begin(); it != v.end(); it++)
		sum += (*it);
	return sum;
}