// c8e1double_linked_list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
namespace List
{
	void append(std::string);
	void prepend(std::string);
	std::string popFirst();
	std::string popLast();
	void lprint();
	void sort();
	void reverse();
}
namespace List
{
	std::vector<std::string> v0;
	void append(std::string s)
	{
		std::vector<std::string>& v = v0;
		v.push_back(s);
	}
	void prepend(std::string s)
	{
		std::vector<std::string>& v = v0;
		v.push_back(" ");
		for (int i = v.size() - 1; i > 0; i--)
			v[i] = v[i - 1];
		v[0] = s;
	}
	std::string popLast()
	{
		std::vector<std::string>& v = v0;
		std::string s = v[v.size() - 1];
		v.pop_back();
		return s;
	}
	std::string popFirst()
	{
		std::vector<std::string>& v = v0;
		std::string s = v[0];
		for (int i = 1; i < v.size(); i++)
			v[i - 1] = v[i];
		v.pop_back();
		return s;
	}
	void lprint()
	{
		for (int i = 0; i < v0.size(); i++)
			std::cout << v0[i] << ' ';
		std::cout << '\n';
	}
	void sort()
	{
		std::vector<std::string>& v = v0;
		std::sort(v.begin(), v.end());
	}
	bool reverser(std::string i, std::string j);
	bool reverser(std::string i, std::string j) { return (i>j); }
	void reverse()
	{
		std::vector<std::string>& v = v0;
		std::sort(v.begin(), v.end(),reverser);
	}
}





int main()
{
	List::append("a");
	List::append("b");
	List::lprint();
	List::reverse();
	List::lprint();
	List::sort();
	List::lprint();
	List::popFirst();
	List::lprint();
	std::cout << (std::string("a") < std::string("b"));
}

