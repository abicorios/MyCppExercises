// c10e5Histogram.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <regex>
#include <vector>
#include <sstream>
#include <algorithm>

class Histogram
{
public:
	Histogram(std::string);
	void print();

private:
	std::vector<int> v;
	int s_to_i(std::string);
};

int Histogram::s_to_i(std::string s)
{
	std::stringstream stream;
	int i;
	stream << s;
	stream >> i;
	
	return i;
}

void Histogram::print()
{
	int m = *std::max_element(v.begin(),v.end());
	while (m--)
	{
		for (auto v_i : v) std::cout << ((v_i >= m + 1) ? '*' : ' ');
		std::cout << std::endl;
	}
}

Histogram::Histogram(std::string s)
{
	std::regex e("(\\d+)(,|$)");
	std::regex_iterator<std::string::iterator> it(s.begin(),s.end(), e);
	std::regex_iterator<std::string::iterator> rend;
	v.clear();
	while (it != rend) { v.push_back(s_to_i(it->str(1))); it++; }
}

int main()
{
	std::string s = "";
	for (int i = 1; i < 120; i++)s += (std::to_string(i%30)+",");
	Histogram(s).print();
	//Histogram("1,2,3,2,1,10,20,24,29").print();
}

