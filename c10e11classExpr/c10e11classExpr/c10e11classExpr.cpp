// c10e11classExpr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <map>

class ExprNode
{
public:
	ExprNode(const char* s) { cs = s; read();}
	int Eval()
	{
		copy();
		Node*itn = &n;
		Node*ito = &o;
		int result;
		for (auto operation : ops)
		{
			while (o.have(int(operation[0]))|| o.have(int(operation[1])))
			{
				ito = &o;
				itn = &n;
				while (ito->next)
				{
					if (ito->x == int(operation[0])|| ito->x == int(operation[1]))
					{
						result = f((itn->x), ito->x, (itn->next->x));
						ito->x = ito->next->x;
						ito->shift();
						itn->x = result;
						itn->shift();
						continue;
					}
					itn = itn->next;
					ito = ito->next;
				}
			}
		}
		return result;
	}
	void printBrackets()
	{
		Node*in = &numbers;
		Node*io = &operators;
		std::cout <<'('<< in->x; in = in->next;
		while (io->next)
		{
			if(io->x=='+'|| io->x == '-')
				std::cout <<')'<< char(io->x)<<'(' << in->x;
			else
				std::cout << char(io->x) << in->x;
			io = io->next;
			in = in->next;
		}
		std::cout <<')'<< std::endl;
	}
	void printPostfix()
	{
		Node*in = &numbers;
		Node*io = &operators;
		typedef std::string str;
		
		std::vector<str> vn;
		std::vector<str> vo;
		//vn.push_back(std::to_string(in->x)); in = in->next;
		while (io)
		{
			if (io->x == '+' || io->x == '-')
			{
				vn.push_back(std::to_string(in->x));
				vo.push_back(str({ char(io->x) }));
				in = in->next; io = io->next;
				continue;
			}
			if (io->x == '*' || io->x == '/')
			{
				str s = std::to_string(in->x) + ' '; in = in->next;
				while (io->x == '*' || io->x == '/')
				{
					s += (std::to_string(in->x) + ' ' +  char(io->x) +' ');
					in = in->next; io = io->next;
				}
				vn.push_back(s); if (io->next) vo.push_back(str({ char(io->x) })); else break;
				in = in->next; io = io->next;
				continue;
			}
		}
		for (auto i : vn) std::cout << i << std::endl;
		for (auto i : vo) std::cout << i << std::endl;
		if (vn[0][0] != '-')
			std::cout << vn[0] << ' ';
		else
			std::cout << vn[0].substr(1) << " - ";
		for (int i = 0; i < vo.size(); i++) std::cout << vn[i + 1] << ' ' << vo[i] << ' ';
	}
	/*void print()
	{
		std::cout << "numbers: ";
		Node*it = &numbers;
		while (it->next)
		{
			std::cout << it->x << ' ';
			it = it->next;
		}
		std::cout << "\noperators: ";
		it = &operators;
		while (it->next)
		{
			std::cout << char(it->x) << ' ';
			it = it->next;
		}
		std::cout << std::endl;
	}
	void printPostfix()
	{
		Node*itn = &numbers;
		Node*ito = &operators;
		std::cout << itn->x << ' ' << itn->next->x << ' ' << char(ito->x) << ' ';
		itn = itn->next->next; ito = ito->next;
		while (ito->next)
		{
			std::cout << itn->x << ' ' << char(ito->x) << ' ';
			itn = itn->next;
			ito = ito->next;
		}
		std::cout << std::endl;
	}*/
private:
	class Node
	{
	public:
		Node() {}
		int x;
		Node* next = NULL;
		Node* end()
		{
			Node* tmp = this;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			return tmp;
		}
		Node* preend()
		{
			Node* tmp = this;
			while (tmp->next->next)
			{
				tmp = tmp->next;
			}
			return tmp;
		}
		void insert(int x1) { Node* tmp = end(); tmp->x = x1; tmp->next = new Node; }
		bool have(int x)
		{
			Node* tmp = this;
			while (tmp->next)
			{
				if (tmp->x == x) return true;
				tmp = tmp->next;
			}
			return false;
		}
		void shift() { next = next->next; }
	};
	Node numbers;
	Node operators;
	Node n;
	Node o;
	std::vector<std::string> ops = { "*/","+-" };
	int f(int x, char op, int y)
	{
		switch (op)
		{
		case '+':return x + y;
		case '-':return x - y;
		case '*':return x*y;
		case '/':return x / y;
		}
	}
	const char* cs;
	void read()
	{
		int sign = 1;
		bool first = true;
		int n = 0;
		for (int i = 0; cs[i] != 0; i++)
		{
			if (cs[i] == '-'&&i == 0) {sign = -1; continue;}
			if (cs[i] >= '0'&&cs[i] <= '9') { n = n * 10 + (cs[i] - '0'); if (cs[i + 1] == 0)numbers.insert(n); }
			if (!(cs[i] >= '0'&&cs[i] <= '9') && i != 0) { if (first)n = n*sign; numbers.insert(n); first = false; n = 0; operators.insert(int(cs[i])); }
		}
	}
	void copy()
	{
		Node*itn = &numbers; Node*ito = &operators;
		while (itn->next) { n.insert(itn->x); itn = itn->next; }
		while (ito->next) { o.insert(ito->x); ito = ito->next; }
	}
	
};
class Expr
{
public:
	Expr(const char* a) { s0 = a; }
	int Eval()
	{
		std::string s = s0;
		std::smatch f00;
		for (auto o : ops)
		{
			while (std::regex_search(s, f00, std::regex(std::string("((?:^-)?[0-9]+)(\\") + o + ")([0-9]+)")))
			{
				/*std::cout << "f00 is " << f00[0] << std::endl;
				std::cout << "f00.position() is " << f00.position() << std::endl;
				std::cout << "f00.length() is " << f00.length() << std::endl;*/
				s.replace(f00.position(), f00.length(), std::to_string(f(s_to_i(f00[1]),f00[2].str()[0], s_to_i(f00[3]))));
			}
		}
		i = s_to_i(s);
		return i;
	}
	void print() { std::cout << i << std::endl; }
	void printBrackets()
	{
		std::string s = s0;
		std::smatch f00;
		std::map<std::string, std::string> m;
		int i = 0;
		//std::regex_search(s, f00, std::regex(std::string("(^-)?([0-9]+)")));
		//std::cout << f00[1].length() << std::endl;
		for (auto o : ops)
			while (std::regex_search(s, f00, std::regex(std::string("((?:^-)?[0-9]+|\\$[0-9])(\\") + o + ")([0-9]+|\\$[0-9])")))
			{
				m["$" + std::to_string(i)] = f00[0];
				s.replace(f00.position(), f00.length(), "$" + std::to_string(i));
				i++;
			}
		std::cout << s << std::endl;
		while (std::regex_search(s,f00,std::regex("\\$[0-9]")))
		{
			s.replace(f00.position(), f00.length(), '(' + m[f00[0]] + ')');
		}
		std::cout << s << std::endl;
	}
	void printPostfix()
	{
		typedef std::string str;
		std::string s = s0;
		std::smatch f00;
		std::map<std::string, std::string> m;
		int i = 0;
		//std::regex_search(s, f00, std::regex(std::string("(^-)?([0-9]+)")));
		//std::cout << f00[1].length() << std::endl;
		for (auto o : ops)
			while (std::regex_search(s, f00, std::regex(std::string("((^-)?([0-9]+)|\\$[0-9])(\\") + o + ")([0-9]+|\\$[0-9])")))
			{
				m["$" + std::to_string(i)] = ((s[0]=='-'&&f00.position()==0)?(str(f00[3])+' '+str(f00[2])):str(f00[1]))+' '+str(f00[5])+' '+str(f00[4])+' ';
				s.replace(f00.position(), f00.length(), "$" + std::to_string(i));
				i++;
			}
		std::cout << s << std::endl;
		while (std::regex_search(s, f00, std::regex("\\$[0-9]")))
		{
			s.replace(f00.position(), f00.length(), m[f00[0]]);
		}
		while (s.find("  ")!=str::npos)
		{
			s = std::regex_replace(s, std::regex("  "), " ");
		}
		std::cout << s << std::endl;
	}
private:
	std::string s0;
	int s_to_i(std::string z)
	{
		std::stringstream io;
		io << z;
		int i;
		io >> i;
		return i;
	}
	int i;
	std::vector<std::string> ops = { "*|/","+|-" };
	int f(int x, char op, int y)
	{
		switch (op)
		{
		case '+':return x + y;
		case '-':return x - y;
		case '*':return x*y;
		case '/':return x / y;
		}
	}
};

int main()
{
	Expr ex("-3-2+4*3/2");
	ex.Eval();
	ex.print();
	ex.printBrackets();
	ex.printPostfix();
	ExprNode t("-3-2+4*3/2");
	//32-2+4*3/2= 32-2+(4*3/2) = 4 3 * 2 / 32 + 2 - = 4 3 * 2 / 32 2 - + 
	std::cout << t.Eval() << std::endl;
	t.printBrackets();
	t.printPostfix();
}

