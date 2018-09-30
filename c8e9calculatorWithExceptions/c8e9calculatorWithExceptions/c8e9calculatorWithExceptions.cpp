// c8e9calculatorWithExceptions.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>
//using namespace std;
namespace calculator
{
	double term(bool);
	double prim(bool);
	double error(const std::string&);

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
	struct Zero
	{
		//bool z=false;
		Zero() {}
	};
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
				//return error("divide by 0");
				throw Zero();
			default:
				return left;
			}
	}

	double number_value;
	std::string string_value;

	std::map<std::string, double> table;
	struct Bracket
	{
		std::string s = "')' expected\n";
		Bracket(){}
	};
	struct  Prim
	{
		std::string s = "primary expected\n";
		Prim() {}
	};
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
			if (curr_tok != RP) /*return error("')' expected");*/ throw Bracket();
			get_token();
			return e;
		}
		default:
			//return error("primary expected");
			throw Prim();
		}
	}

	struct BadToken
	{
		std::string s = "bad token\n";
		BadToken() {}
	};
	Token_value get_token()
	{
		char ch;

		do
		{
			if (!std::cin.get(ch)) return curr_tok = END;
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
			std::cin.putback(ch);
			std::cin >> number_value;
			return curr_tok = NUMBER;
		default:
			if (isalpha(ch))
			{
				string_value = ch;
				while (std::cin.get(ch) && isalnum(ch)) string_value.push_back(ch);
				std::cin.putback(ch);
				return curr_tok = NAME;
			}
			//error("bad token");
			throw BadToken();
			return curr_tok = PRINT;
		}
	}

	/*int no_of_errors;

	double error(const std::string& s)
	{
		no_of_errors++;
		std::cerr << "errof: " << s << '\n';
		return 1;
	}*/
}
int main()
{
	std::cout << "print @ simbol for exit\n";
	calculator::table["pi"] = 3.1415926535897932385;
	calculator::table["e"] = 2.7182818284590452354;

	while (std::cin)
	{
		try
		{
			calculator::get_token();
			if (calculator::curr_tok == calculator::END) break;
			if (calculator::curr_tok == calculator::PRINT) continue;
			std::cout << calculator::expr(false) << '\n';
		}
		catch (calculator::Zero)
		{
			std::cerr << "divide by 0\n";
		}
		catch (calculator::Bracket(a))
		{
			std::cerr << a.s;
		}
		catch (calculator::Prim(a))
		{
			std::cerr << a.s;
		}
		catch (calculator::BadToken(a))
		{
			std::cerr << a.s;
		}
	}

	//return calculator::no_of_errors;
}