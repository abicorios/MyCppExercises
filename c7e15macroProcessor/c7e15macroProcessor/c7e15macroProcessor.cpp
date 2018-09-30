// c7e15macroProcessor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <regex>
#include <string>
#include <map>
#include <sstream>
using namespace std;
string stri;
ostringstream z;
istringstream istr;
map<string, vector<string>> functions;
double s_to_d(string);
double s_to_d(string sz)
{
	istringstream mybufer;
	mybufer.str(sz);
	double ddd;
	mybufer >> ddd;
	return ddd;
}
string d_to_s(double);
string d_to_s(double ddd)
{
	ostringstream mybufer;
	mybufer << ddd;
	return mybufer.str();
}

bool preprocessor();
bool preprocessor()
{
	smatch sm;
	if (regex_match(stri, sm, regex("#define\\s+(([[:alpha:]]\\w*)\\((([[:alpha:]]\\w*,)*[[:alpha:]]\\w*)\\))\\s+(.+)")))
	{
		/*for (int i = 0; i < sm.size(); i++)
		{
		cout << "sm[" << i << "]=" << sm[i] << '\n';
		}*/
		string left_part = sm[1];
		string name_of_function = sm[2];
		string s_variables = sm[3];
		string right_part = sm[5];
		regex e("\\w");
		//cout << "variables is " << s_variables << '\n';
		vector<string> v_variables;
		v_variables.push_back(right_part);
		regex_iterator<string::iterator> rit(s_variables.begin(), s_variables.end(), e);
		regex_iterator<std::string::iterator> rend;
		while (rit != rend)
		{
			v_variables.push_back(rit->str());
			++rit;
		}
		/*for (int i = 0; i < v_variables.size(); i++)
		cout << "v_variables[" << i << "]=" << v_variables[i] << '\n';*/
		functions[name_of_function] = v_variables;
		/*for (map<string, vector<string>>::iterator it = functions.begin(); it != functions.end(); it++)
		{
		for (int i = 0; i < (it->second).size(); i++)
		{
		cout << "function " << it->first << " and i is " << i << " and v_i is " << (it->second)[i] << '\n';
		}
		}*/
		return true;
	}
	smatch f1;
	while (regex_search(stri, f1, regex("([[:alpha:]]\\w*)\\((((\\d+|\\d+\\.\\d*|\\d*\\.\\d+),)*(\\d+|\\d+\\.\\d*|\\d*\\.\\d+))\\)")))
	{
		/*for (int i = 0; i < f1.size(); i++)
		{
		cout << "f1[" << i << "]=" << f1[i] << '\n';
		}*/

		string name_of_function = f1[1];
		string s_variables = f1[2];
		regex e("(\\d+|\\d+\\.\\d*|\\d*\\.\\d+)");
		vector<string> v_variables;
		regex_iterator<string::iterator> rit(s_variables.begin(), s_variables.end(), e);
		regex_iterator<std::string::iterator> rend;
		while (rit != rend)
		{
			v_variables.push_back(rit->str());
			++rit;
		}
		/*for (int i = 0; i < v_variables.size(); i++)
		{
		cout << "v_variables[" << i << "]=" << v_variables[i] << '\n';
		}*/

		map<string, double> variables;
		for (int i = 0; i < v_variables.size(); i++)
			variables[functions[name_of_function][i + 1]] = s_to_d(v_variables[i]);

		stri = regex_replace(stri, regex("[[:alpha:]]\\w*\\(((\\d+|\\d+\\.\\d*|\\d*\\.\\d+),)*(\\d+|\\d+\\.\\d*|\\d*\\.\\d+)\\)"), "(" + functions[name_of_function][0] + ")", regex_constants::format_first_only);
		//cout << stri << '\n';
		for (map<string, double>::iterator it = variables.begin(); it != variables.end(); it++)
		{
			//cout << "it->first is " << it->first << " and it->second is " << it->second << '\n';
			stri = regex_replace(stri, regex(it->first), d_to_s(it->second));
		}
		//cout << stri << '\n';
		//istr.str(stri);
		//z << stri << '\n';

	}
	return false;
}

int main()
{
	//string s;
	map < string  , string > m;
	
	smatch sm;
	cout << "input #definition and use it.\nFor exit input one @ character in line.\n";
	getline(cin, stri);
	
	while (stri != "@")
	{
		if (preprocessor()) goto a;
		if (regex_match(stri, sm, regex("#define\\s+(\\w+)\\s+(.+)")))
		{
			m[sm[1]] = sm[2];
			goto a;
		}
		for (map<string, string>::iterator it = m.begin(); it != m.end(); it++)
		{
			regex e(it->first);
			stri = regex_replace(stri, e, it->second);
		}
		a:z << stri<<'\n';
		getline(cin, stri);
	}
	cout << z.str();
}

