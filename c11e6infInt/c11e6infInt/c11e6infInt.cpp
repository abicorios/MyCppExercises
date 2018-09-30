// c11e6infInt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>
typedef long long i64;
typedef unsigned long long ui64;
typedef std::string str;
str st(char c);
str st(char c)
{
	return std::to_string(int(c));
}
class infInt
{
public:
	infInt(i64 x=0)
	{
		if (x == 0) { m[0] = 0; sign = true;}
		else
		{
			if (x > 0)sign = true; else { sign = false; x = -x; }
			ui64 i = 0;
			while (x)
			{
				m[i] = x % 10;
				x /= 10;
				i++;
			}
		}
	}
	infInt(str s)
	{
		if (s[0] == '-')
		{
			sign = false;
			s.erase(0, 1);
		}
		else sign = true;
		ui64 sz = s.length()-1;
		for (auto it : s)
		{
			m[sz] = it-'0';
			sz--;
		}
	}
	str r()
	{
		str s = "";
		for (auto it : m)
		{
			s = st(it.second) + s;
		}
		if (!sign)s = '-' + s;
		return s;
	}
	ui64 l()
	{
		ui64 i = 0;
		for (auto it : m)
		{
			i++;
		}
		return i;
	}
	bool operator==(infInt t)
	{
		n(); t.n();
		bool re = true;
		re &= (sign == t.sign);
		ui64 len = l();
		re &= (len == t.l());
		while (len)
		{
			len--;
			re &= (m[len]==t.m[len]);
		}
		return re;
	}
	infInt operator++()
	{
		bool stop=true;
		ui64 i = 0;
		if (sign)
		{
			while (stop)
			{
				if (m[i] < 9)
				{
					m[i] += stop;
					stop = false;
				}
				else
				{
					m[i] = 0;
				}
				i++;
			}
		}
		else
		{
			//if()
			while (stop)
			{
				if (m[i] > 0)
				{
					m[i] -= stop;
					stop = false;
				}
				else
				{
					m[i] = 9;
				}
				i++;
			}
		}
		return *this;
	}
	infInt operator--()
	{
		sign = !sign;
		++(*this);
		sign = !sign;
		return *this;
	}
	infInt operator++(int)
	{
		return ++*this;
	}
	infInt operator--(int)
	{
		return --*this;
	}
private:
	void n()
	{
		i64 len = l();
		if (m[len - 1] == 0&&len>1)
		{
			m.erase(len - 1);
			n();
		}
		else return;
	}
	std::map<long long, char> m;
	bool sign;
};
void p(infInt);
void p(infInt x)
{
	std::cout << x.r() << std::endl;
}
int main()
{
	infInt a = -123;
	p(a);
	infInt b = "-28";
	p(b);
	p(++a); p(++a); p(++a); p(++a);
	p(--b); p(--b);
	infInt c = 48;
	p(c);
	p(c++); p(c++); p(c++);
	p(c--); p(c--); p(c--);
	std::map<long long, char> m;
	m[0] = 1;
	std::cout << (m[1] == 0) << std::endl;
	for(auto it:m) std::cout << it.first << std::endl;
	m.erase(1);
	for (auto it : m) std::cout << it.first << std::endl;
}