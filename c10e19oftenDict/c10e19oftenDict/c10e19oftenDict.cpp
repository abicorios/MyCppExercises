// c10e19oftenDict.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

int count(std::string, std::string);
int count(std::string bigs, std::string subs)
{
	int n = 0;
	int found = bigs.find(subs);
	while (found != std::string::npos)
	{
		n++;
		found = bigs.find(subs, found + 1);
	}
	return n;
}

std::map<std::string, int> f(std::istream&,std::vector<std::string>);
std::map<std::string, int> f(std::istream& is, std::vector<std::string> v)
{
	std::string s;
	std::map<std::string, int> m;
	while (std::getline(is, s))
	{
		for (auto vi : v)
		{
			m[vi] += count(s, vi);
		}
	}
	return m;
}

int main()
{
	/*std::ofstream ofs("test.txt", std::ofstream::out);
	for (int j = 0; j < 1000; j++)
		ofs << "0123456789\n";
	ofs.close();*/
	std::ifstream f0("test.txt");
	std::vector<std::string> v0{ "1","2","8","4" };
	std::map<std::string, int> m1;
	m1=f(f0,v0 );
	for (auto mi : m1)
	{
		std::cout << mi.first << ' ' << mi.second << std::endl;
	}
}