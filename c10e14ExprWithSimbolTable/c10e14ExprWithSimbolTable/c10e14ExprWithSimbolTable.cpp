// c10e14ExprWithSimbolTable.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <boost/regex.hpp>
#include <iostream>
#include <sstream>
typedef std::string str;
class Expr
{
public:
	Expr(const char* a) { s0 = a;reed(); }
	int Eval()
	{
		std::vector<str> ter = terms;
		std::vector<str> sig = signs;
		boost::smatch sm;
		for (auto &t : ter)
		{
			while (boost::regex_search(t, sm, boost::regex("([0-9]+)(" + ops[0] + ")([0-9]+)")))
			{
				t.replace(sm.position(),sm.length(),f(sm[1], sm[2], sm[3]) );
				std::cout << t << std::endl;
			}
		}
		for (auto t : ter)
			std::cout << t << std::endl;
		if (ter.size() == sig.size()) ter.insert(ter.begin(), "0");
		while (ter.size() > 1)
		{
			ter[0] = f(ter[0], sig[0], ter[1]);
			ter.erase(ter.begin());
			sig.erase(sig.begin());
		}
/*
		str s = s0;
		
		boost::smatch f00;
		for (auto o : ops)
		{
			while (boost::regex_search(s, f00, boost::regex(str("((?:^-)?([0-9]+))([") + o + "])((?2))")))
			{
				s.replace(f00.position(), f00.length(),f(f00[1], f00[3], f00[4]));
			}
		}
		i = s_to_i(s);*/
		i = s_to_i(ter[0]);
		return i;
	}
	//void print() { std::cout << i << std::endl; }
	void printBrackets()
	{
		
		std::vector<str> ter = terms;
		int ts = ter.size();
		int ss = signs.size();
		if (ts > ss) { std::cout << '(' << ter[0] << ')'; ter.erase(ter.begin()); }
		for (int i = 0; i < ts; i++)
		{
			std::cout << signs[i] << '(' << ter[i] << ')';
		}
		std::cout << std::endl;
	}
	
private:
	str s0;
	int s_to_i(str z)
	{
		std::stringstream io;
		io << z;
		int i;
		io >> i;
		return i;
	}
	int i;
	std::vector<str> ops = { "\\*|/","+-" };
	std::vector<str> terms;
	std::vector<str> signs;
	void reed()
	{
		boost::regex e("([+-])?([^+-]+)");
		boost::sregex_iterator it(s0.begin(), s0.end(), e);
		boost::sregex_iterator itend;
		while (it != itend)
		{
			str z = (*it)[1];
			if(z.size()>0) signs.push_back(z);
			terms.push_back((*it)[2]);
			it++;
		}
	}
	str f(str x0, str op0, str y0)
	{
		int x = s_to_i(x0);
		int y = s_to_i(y0);
		char op = op0[0];
		int r;
		switch (op)
		{
		case '+':
			r= x + y;
			break;
		case '-':
			r = x - y;
			break;
		case '*': r = x*y; 
			break;
		case '/':r = x / y;
			break;
		}
		str st = (std::to_string(int(r)));
		std::cout <<x0<<op0<<y0<<'='<< r << std::endl;
		return st;
	}
};
int main()
{
	Expr ex("-3-2+4*3/2");
	//ex.Eval();
	ex.printBrackets();
	std::cout << ex.Eval() << std::endl;
	
	/*str s = "3-2+4*3/2";
	boost::smatch sm;
	boost::regex e("^([\\+\\-])?([^\\+\\-]+)(?:([\\+\\-])([^\\+\\-]+))*");
	boost::regex_match(s, sm, e, boost::match_extra);
	for(auto i:sm)
		std::cout << i << std::endl;
	boost::regex e1("([+-])?([^+-]+)");
	boost::sregex_iterator it(s.begin(),s.end(), e1);
	boost::sregex_iterator itend;
	while (it != itend)
	{
		std::cout << (*it)[1]<<'\n'<< (*it)[2] << std::endl;
		it++;
	}*/
}

