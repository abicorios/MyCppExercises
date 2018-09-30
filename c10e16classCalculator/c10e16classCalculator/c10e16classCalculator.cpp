// c10e16classCalculator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include <vector>
class Calculator
{
public:
	Calculator(std::string s000 = "") { mys = s000; number_of_input_string = 0; initflag = false; cinFlag = false; }
	void init(std::string s000) { mys = s000; }
	void Eval() { if (mys.back() != ';') mys += ';';; calculator(mys); }
	void cin(int i = 1)
	{
		cinFlag = true;
		while (i--)
		{
			std::string s;
			number_of_input_string++;
			pyp << "in[" << number_of_input_string << "]:";
			std::cout << out();
			std::cin >> s;
			init(s);
			Eval();
		}
		cinFlag = false;
	}
	std::string out()
	{
		std::string s= pyp.str();
		pyp.str("");
		return s;
	}
private:
	std::stringstream pyp;
	bool cinFlag;
	bool initflag;
	std::string mys;
	std::string stri;

	std::map<std::string, std::vector<std::string>> functions;
	std::istringstream istr;
	//double term(bool);
	//double prim(bool);
	//double error(const std::string&);

	//double s_to_d(std::string);
	double s_to_d(std::string sz)
	{
		std::istringstream mybufer;
		mybufer.str(sz);
		double ddd;
		mybufer >> ddd;
		return ddd;
	}

	//std::string d_to_s(double);
	std::string d_to_s(double ddd)
	{
		std::ostringstream mybufer;
		mybufer << ddd;
		return mybufer.str();
	}

	enum Token_value
	{
		NAME, NUMBER, END,
		PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
		PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
	};

	//Token_value get_token();

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

	//double expr(bool);

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
	std::string string_value;

	std::map<std::string, double> table;

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

	short number_of_input_string;
	Token_value get_token()
	{
		char ch;

		do
		{
			if (!istr.get(ch)) return curr_tok = END;
		} while (ch != '\n'&&isspace(ch));

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

	double error(const std::string& s)
	{
		no_of_errors++;
		std::cerr << "errof: " << s << " in line " << number_of_input_string << '\n';
		return 1;
	}

	//bool preprocessor();
	bool preprocessor()
	{
		std::smatch sm;
		if (std::regex_match(stri, sm, std::regex("(([[:alpha:]]\\w*)\\((([[:alpha:]]\\w*,)*[[:alpha:]]\\w*)\\))=(.+)")))
		{
			std::string left_part = sm[1];
			std::string name_of_function = sm[2];
			std::string s_variables = sm[3];
			std::string right_part = sm[5];
			std::regex e("\\w");
			std::vector<std::string> v_variables;
			v_variables.push_back(right_part);
			std::regex_iterator<std::string::iterator> rit(s_variables.begin(), s_variables.end(), e);
			std::regex_iterator<std::string::iterator> rend;
			while (rit != rend)
			{
				v_variables.push_back(rit->str());
				++rit;
			}
			functions[name_of_function] = v_variables;
			return true;
		}
		std::smatch f1;
		while (std::regex_search(stri, f1, std::regex("([[:alpha:]]\\w*)\\((((\\d+|\\d+\\.\\d*|\\d*\\.\\d+),)*(\\d+|\\d+\\.\\d*|\\d*\\.\\d+))\\)")))
		{
			std::string name_of_function = f1[1];
			std::string s_variables = f1[2];
			std::regex e("(\\d+|\\d+\\.\\d*|\\d*\\.\\d+)");
			std::vector<std::string> v_variables;
			std::regex_iterator<std::string::iterator> rit(s_variables.begin(), s_variables.end(), e);
			std::regex_iterator<std::string::iterator> rend;
			while (rit != rend)
			{
				v_variables.push_back(rit->str());
				++rit;
			}
			std::map<std::string, double> variables;
			for (int i = 0; i < v_variables.size(); i++)
				variables[functions[name_of_function][i + 1]] = s_to_d(v_variables[i]);

			stri = std::regex_replace(stri, std::regex("[[:alpha:]]\\w*\\(((\\d+|\\d+\\.\\d*|\\d*\\.\\d+),)*(\\d+|\\d+\\.\\d*|\\d*\\.\\d+)\\)"), "(" + functions[name_of_function][0] + ")", std::regex_constants::format_first_only);
			pyp << stri << '\n';
			for (std::map<std::string, double>::iterator it = variables.begin(); it != variables.end(); it++)
			{
				stri = std::regex_replace(stri, std::regex(it->first), d_to_s(it->second));
			}
			pyp << stri << '\n';
			istr.str(stri);
		}
		return false;
	}
	//int calculator(std::string, bool initflag = false);
	int calculator(std::string strin)
	{
		if (initflag == false)
		{
			table["pi"] = 3.1415926535897932385;
			table["e"] = 2.7182818284590452354;
			pyp << "calculator\n";
			pyp << "only +-*/\n";
			pyp << "but you can define function\n";
			pyp << "for example f(a,b)=2*a*a+3*a+b\n";
			pyp << "end use it in next lines\n";
			pyp << "for example 2*f(3,4)+5\n";
			pyp << "print one @ simbol in line for exit\n";
			initflag = true;
		}
		std::regex e("([^;]+);");
		std::regex_iterator<std::string::iterator> it(strin.begin(), strin.end(), e);
		std::regex_iterator<std::string::iterator> itend;
		while (it != itend)
		{
			stri = it->str(1);
			if (!cinFlag)
			{
				number_of_input_string++;
				pyp << "in[" << number_of_input_string << "]:" << stri << std::endl;
			}
			istr.clear();
			istr.str(stri);
			while (istr)
			{
				if (preprocessor()) break;
				get_token();
				if (curr_tok == END) break;
				if (curr_tok == PRINT) continue;
				//std::cout << "out[" << number_of_input_string << "]:" << expr(false) << '\n';
				pyp << "out[" << number_of_input_string << "]:" << expr(false) << '\n';
				
			}
			it++;
		}
		return no_of_errors;
	}
};
int main(int argc,char*argv[])
{
	Calculator c;
	c.init("f(x)=x+1;f(1);1+1;a=3;a+2;");
	c.Eval();
	c.cin();
	if (argc == 2)
	{
		c.init(argv[1]);
		c.Eval();
	}
	std::cout << c.out();
	
}