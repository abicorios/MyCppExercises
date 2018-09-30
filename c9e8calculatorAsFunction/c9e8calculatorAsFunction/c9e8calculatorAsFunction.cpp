// c9e8calculatorAsFunction.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include <vector>


using namespace std;


string stri;

map<string, vector<string>> functions;
istringstream istr;
double term(bool);
double prim(bool);
double error(const string&);

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

enum Token_value
{
	NAME, NUMBER, END,
	PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
	PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
};

Token_value get_token();

Token_value curr_tok = PRINT;

double expr(bool get)
{
	//cout << "expr\n";
	double left = term(get);

	for (;;)
		switch (curr_tok)
		{
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left -= term(true);
			break;
		default:
			return left;
		}
}

double expr(bool);

double term(bool get)
{
	//cout << "term\n";
	double left = prim(get);
	for (;;)
		switch (curr_tok)
		{
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true))
			{
				left /= d;
				break;
			}
			return error("divide by 0");
		default:
			return left;
		}
}

double number_value;
string string_value;

map<string, double> table;

double prim(bool get)
{
	//cout << "prim\n";
	if (get) get_token();
	switch (curr_tok)
	{
	case NUMBER:
	{
		double v = number_value;
		get_token();
		return v;
	}
	case NAME:
	{
		double&v = table[string_value];
		if (get_token() == ASSIGN) v = expr(true);
		return v;
	}
	case MINUS:
		return -prim(true);
	case LP:
	{
		double e = expr(true);
		if (curr_tok != RP) return error("')' expected");
		get_token();
		return e;
	}
	default:
		return error("primary expected");
	}
}

short number_of_input_string = 0;
Token_value get_token()
{
	//cout << "get_token\n";
	char ch;



	do
	{
		if (!istr.get(ch)) return curr_tok = END;
	} while (ch != '\n'&&isspace(ch));

	//cout << "char is " << ch << '\n';

	switch (ch)
	{
	case '@':
		return curr_tok = END;
	case ';':
	case '\n':
		return curr_tok = PRINT;
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return curr_tok = Token_value(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		istr.putback(ch);
		istr >> number_value;
		return curr_tok = NUMBER;
	default:
		if (isalpha(ch))
		{
			string_value = ch;
			while (istr.get(ch) && isalnum(ch)) string_value.push_back(ch);
			istr.putback(ch);
			return curr_tok = NAME;
		}
		error("bad token");
		return curr_tok = PRINT;
	}
}

int no_of_errors;

double error(const string& s)
{
	//cout << "counter of error\n";
	no_of_errors++;
	cerr << "errof: " << s << " in line " << number_of_input_string << '\n';
	return 1;
}

bool preprocessor();
bool preprocessor()
{
	smatch sm;
	if (regex_match(stri, sm, regex("(([[:alpha:]]\\w*)\\((([[:alpha:]]\\w*,)*[[:alpha:]]\\w*)\\))=(.+)")))
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
		cout << stri << '\n';
		for (map<string, double>::iterator it = variables.begin(); it != variables.end(); it++)
		{
			//cout << "it->first is " << it->first << " and it->second is " << it->second << '\n';
			stri = regex_replace(stri, regex(it->first), d_to_s(it->second));
		}
		cout << stri << '\n';
		istr.str(stri);

	}
	return false;
}
int calculator(string, bool initflag = false);
int calculator(string stri,bool initflag)
{
	if (initflag == false)
	{
		table["pi"] = 3.1415926535897932385;
		table["e"] = 2.7182818284590452354;
		cout << "calculator\n";
		cout << "only +-*/\n";
		cout << "but you can define function\n";
		cout << "for example !f(a,b)=2*a*a+3*a+b\n";
		cout << "end use it in next lines\n";
		cout << "for example 2*f(3,4)+5\n";
		cout << "print one @ simbol in line for exit\n";
		initflag = true;
	}
	//while (cin)
	//{
		number_of_input_string++;
		cout << "in[" << number_of_input_string << "]:"<<stri<<endl;
		//getline(cin, stri);
		istr.clear();
		istr.str(stri);
		while (istr)
		{
			if (preprocessor()) break;
			get_token();
			if (curr_tok == END) break;
			if (curr_tok == PRINT) continue;
			cout << "out[" << number_of_input_string << "]:" << expr(false) << '\n';
		}
	//}
	return no_of_errors;
}

int main()
{
	calculator("2+2");
	/*table["pi"] = 3.1415926535897932385;
	table["e"] = 2.7182818284590452354;
	cout << "calculator\n";
	cout << "only +-* /\n";
	cout << "but you can define function\n";
	cout << "for example !f(a,b)=2*a*a+3*a+b\n";
	cout << "end use it in next lines\n";
	cout << "for example 2*f(3,4)+5\n";
	while (cin)
	{
		number_of_input_string++;
		cout << "in[" << number_of_input_string << "]:";
		getline(cin, stri);
		istr.clear();
		istr.str(stri);
		while (istr)
		{
			if (preprocessor()) break;
			get_token();
			if (curr_tok == END) break;
			if (curr_tok == PRINT) continue;
			cout << "out[" << number_of_input_string << "]:" << expr(false) << '\n';
		}
	}
	return no_of_errors;*/
}