// c10e7table.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
class Table
{
	typedef std::string str;
	
public:
	struct P
	{
		str s;
		double d;
		P(str s0="n", double d0=0) { s = s0; d = d0; }
	};
	Table(std::vector<str> c = {}, std::vector<str> r = {}) { columns = c; rows = r; }
	std::vector<str> columns;
	std::vector<str> rows;
	void add_row(str s) { rows.push_back(s); }
	void insert(str c, str r, P d) 
	{ 
		if (std::find(rows.begin(), rows.end(), r) == rows.end())
			this->add_row(r);
		table[c][r] = d; 

	}
	void insert(std::vector<std::vector<P>> vv)
	{
		for (unsigned ic = 0; ic < columns.size(); ic++)
		{
			for (unsigned ir = 0; ir < rows.size(); ir++)
			{
				table[columns[ic]][rows[ir]] = vv[ir][ic];
			}
		}
	}
	P e(str c, str r) { return table[c][r]; }
private:
	std::map<std::string,std::map<std::string,P>> table;
};
typedef Table::P p;
using namespace std;

double term(bool);
double prim(bool);
double error(const string&);

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

//map<string, double> table;
Table table({ "A" }, {"1"});

double prim(bool get)
{
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
		//double&v = table[string_value];
		double temp = table.e("A", string_value).d;
		double&v = temp;
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

Token_value get_token()
{
	char ch;

	do
	{
		if (!cin.get(ch)) return curr_tok = END;
	} while (ch != '\n'&&isspace(ch));



	switch (ch)
	{
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
		cin.putback(ch);
		cin >> number_value;
		return curr_tok = NUMBER;
	default:
		if (isalpha(ch))
		{
			string_value = ch;
			while (cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
			cin.putback(ch);
			return curr_tok = NAME;
		}
		error("bad token");
		return curr_tok = PRINT;
	}
}

int no_of_errors;

double error(const string& s)
{
	no_of_errors++;
	cerr << "errof: " << s << '\n';
	return 1;
}
int main()
{
	/*Table t({ "a","b" }, { "1","2" });
	t.insert("a", "1", Table::P("number",48));
	std::cout << t.e("a","1").d<<std::endl;
	t.insert({ {p("n",1),p("m",2)},{p("i",3),p("j",4)} });
	std::cout << t.e("a", "1").d << std::endl;*/

	//table["pi"] = 3.1415926535897932385;
	table.insert("A", "pi", p("n",3.1415926535897932385));
	//table["e"] = 2.7182818284590452354;
	table.insert("A", "e", p("n", 2.7182818284590452354));

	while (cin)
	{
		get_token();
		if (curr_tok == END) break;
		if (curr_tok == PRINT) continue;
		cout << expr(false) << '\n';
	}

	return no_of_errors;
}