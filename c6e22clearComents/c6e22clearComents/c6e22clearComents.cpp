// c6e22clearComents.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <sstream>
using namespace std;

string d_to_s(double);
string d_to_s(double ddd)
{
	ostringstream mybufer;
	mybufer << ddd;
	return mybufer.str();
}

map<string, string> q;
void preprocessor(string& );
void preprocessor(string& z)
{
	regex ze("\".*?\"");
	if (regex_search(z, ze))
	{
		smatch sm;
		regex_search(z, sm, ze);
		q["$" + d_to_s(q.size())] = sm[0];
		//cout << "$" + d_to_s(q.size()-1) << '\n';
		z=regex_replace(z, ze, "$" + d_to_s(q.size()-1), regex_constants::format_first_only);
	}
	if (regex_search(z, ze))
		preprocessor(z);
}

void postprocessor(string&);
void postprocessor(string& z)
{
	//regex ze("\\$\\d+");
	for (int i = 0; i < q.size(); i++)
	{
		//cout << "$" + d_to_s(i + 0) << '\n';
		//cout << q["$" + d_to_s(i + 0)] << '\n';
		//cout << z << '\n';
		z = regex_replace(z, regex("\\$" + d_to_s(i+0)), q["$" + d_to_s(i+0)]);
		//cout << z << '\n';
		
	}
	q.clear();
}

int main()
{
	
	string bs;
	//preprocessor(bs);
	//cout << bs;
	cout << "print source\nthis program delete coments\nprint one symbol @ in new line for quit\n";
	int counter = 0;
	while (true)
	{
		string s;
		cin >> s;
		preprocessor(s);
		regex e("//.*");
		regex e1("/\\*.*");
		regex e2(".*\\*/");
		if (counter > 0)
		{
			if (regex_search(s, e2))
			{
				s = regex_replace(s, e2, "");
				counter--;
			}
			else
			{
				postprocessor(s);
				continue;
			}
		}
		
		if(regex_search(s, e))
			s = regex_replace(s, e, "");
		
		
		
		
			if (regex_search(s, e1))
			{
				s = regex_replace(s, e1, "");
				counter++;
			}
		
		
		if (s == "@") break;
		else 
		{ 
			postprocessor(s);
			bs += "\n" + s; 
		}
	}
	
	cout << bs<<'\n';
}

