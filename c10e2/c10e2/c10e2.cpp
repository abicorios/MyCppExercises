// c10e2.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <map>
namespace Chrono
{
	bool leapyear(int y);
	class  Date
	{
	public:
		enum Month
		{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};
		class Bad_date {};
		Date(int dd = 0, Month mm = Month(0), int yy = 0);
		Date(int dz, int mz, int yz);
		int day() const;
		Month month() const;
		int year() const;
		std::string string_rep() const;
		void char_rep(char s[]) const;
		static void set_default(int, Month, int);
		Date& add_year(int n);
		Date& add_month(int n);
		Date& add_day(int n);
		int unix_time();
	private:
		int d, y;
		Month m;
		static Date default_date;
		static Date unix_base;
		Date& Date::year_pp();
		Date& Date::month_pp();
		Date& Date::day_pp();
		Date& Date::day_mm();
		int maxd(Month, int);
	};
	Date::Month& operator++(Date::Month&mzbcx, int)
	{
		if (mzbcx == Date::dec)
			mzbcx = Date::jan;
		else
			mzbcx = Date::Month(mzbcx + 1);
		return mzbcx;
	}
	Date::Month& operator--(Date::Month&mzbcx, int)
	{
		if (mzbcx == Date::jan)
			mzbcx = Date::dec;
		else
			mzbcx = Date::Month(mzbcx - 1);
		return mzbcx;
	}
	Date::Month operator+(Date::Month mz, int i)
	{
		int x = (int(mz) + i) % 12;
		x = (x == 0) ? 12 : x;
		return Date::Month(x);
	}
	Date::Month operator-(Date::Month mz, int i)
	{
		Date::Month tmp = mz;
		while (i--)tmp--;
		return tmp;
	}
	bool operator<(Date a, Date b)
	{
		if (a.year() < b.year())
			return true;
		else if (a.year() == b.year() && a.month() < b.month())
			return true;
		else if (a.year() == b.year() && a.month() == b.month() && a.day() < b.day())
			return true;
		else
			return false;
	}
	Date Date::default_date(1, jan, 1970);
	Date Date::unix_base(1, jan, 1970);
	int Date::maxd(Month mz,int yz)
	{
		int max;
		switch (mz)
		{
		case feb:
			max = 28 + leapyear(yz);
			break;
		case apr: case jun: case sep: case nov:
			max = 30;
			break;
		case jan: case mar: case may: case jul: case aug: case oct: case dec:
			max = 31;
			break;
		default:
			max = 0;
			break;
		}
		return max;
	}
	Date::Date(int dd, Date::Month mm, int yy)
	{
		if (yy == 0)yy = default_date.year();
		if (mm == 0)mm = default_date.month();
		if (dd == 0)dd = default_date.day();
		int max = maxd(mm,yy);
		if (dd < 1 || max < dd) throw Bad_date();
		y = yy;
		m = mm;
		d = dd;
	}
	Date::Date(int dz, int mz, int yz)
	{
		Date::Date(dz, Date::Month(mz), yz);
	}
	inline int Date::day() const
	{
		return d;
	}
	inline Date::Month Date::month() const
	{
		return m;
	}
	inline int Date::year() const
	{
		return y;
	}
	Date& Date::day_pp()
	{
		int mx = maxd(m, y);
		if (d < mx) d++;
		else if (d == mx && m < 12) { d = 1;m++; }
		else if (d == mx && m == 12) { d = 1; m = jan; y++; }
		return *this;
	}
	Date& Date::day_mm()
	{
		if(d > 1)d--;
		else if (d == 1 && m > 1) { m--; d = maxd(m, y); }
		else if (d == 1 && m == 1) { d = 31; m--; y--; }
		return *this;
	}
	int Date::unix_time()
	{
		int n = 0;
		Date tmp = *this;
		while (unix_base<tmp)
		{
			n++;
			tmp.day_mm();
		}
		return n;
	}
	Date& Date::month_pp()
	{
		int mx = maxd(m + 1, y);
		if (d <= mx&&m<12) { m++; }
		else if (d > mx && m < 12) { d = d%mx; m++++; }
		else if (m == 12) { m = jan; y++; }
		return *this;
	}
	Date& Date::year_pp()
	{
		if (d != 29 || m != feb)y++;
		else
		{
			d = 1;
			m = mar;
			y++;
		}
		return *this;
	}
	Date& Date::add_day(int n)
	{
		while (n--)
		{
			day_pp();
		}
		return *this;
	}
	Date& Date::add_month(int n)
	{
		while (n--)
		{
			month_pp();
		}
		return *this;
	}
	Date& Date::add_year(int n)
	{
		while (n--)
		{
			year_pp();
		}
		return *this;
	}
	bool leapyear(int y);
	bool leapyear(int y)
	{
		return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
	}
	std::string zn(int);
	std::string zn(int n)
	{
		std::string s = std::to_string(n);
		if (n < 10)
			return "0" + s;
		else
			return s;
	}
	std::string Date::string_rep() const
	{
		return zn(d) + "." + zn(m) + "." + zn(y);
	}
	int ch_to_int(char);
	int ch_to_int(char c)
	{
		return c - '0';
	}
	std::vector<char> sub_array(char*, int, int);
	std::vector<char> sub_array(char*s, int beginz, int endz)
	{
		std::vector<char> s1;
		for (int i = beginz; i <= endz; i++)
			s1.push_back(s[i]);
		return s1;
	}
	int v_to_int(std::vector<char> v)
	{
		int r = 0;
		int j = 1;
		for (int i = v.size() - 1; i >= 0; i--)
		{
			r += ch_to_int(v[i])*j;
			j *= 10;
		}
		return r;
	}
	void Date::char_rep(char s[]) const
	{
		int ddd;
		int mmm;
		int yyy;
		if (strlen(s) != 10) throw Bad_date();
		ddd = v_to_int(sub_array(s, 0, 1));
		mmm = v_to_int(sub_array(s, 3, 4));
		yyy = v_to_int(sub_array(s, 6, 9));
		Date(ddd,Month(mmm), yyy);
	}
	inline bool operator==(Date a, Date b)
	{
		return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
	}
	void Date::set_default(int ddd, Date::Month mmm, int yyy)
	{
		default_date = Date(ddd, mmm, yyy);
	}
}
enum Dayz {mon,two,the};
Dayz operator++(Dayz&xbb,int)
{
		if (xbb == the)
			return xbb = mon;
		else
			return xbb = Dayz(xbb + 1);
}
int main()
{
	std::map<std::string, int> ma{ {"bday",28},{"bmonth",2},{"byear",1970},{"addday",1},{"addmonth",20},{"addyear",8} };
	Chrono::Date mydate;
	try
	{
		mydate= Chrono::Date(ma["bday"], Chrono::Date::Month(ma["bmonth"]), ma["byear"]);
	}
	catch (Chrono::Date::Bad_date)
	{
		std::cerr << "it is not date\n";
	}
	for (auto it : ma) std::cout << it.first << "=" << it.second << std::endl;
	std::cout <<"mydate "<< mydate.string_rep() << std::endl;
	mydate.add_day(ma["addday"]);
	std::cout <<"mydate.add_day("<<ma["addday"]<<"); "<< mydate.string_rep() << std::endl;
	mydate.add_month(ma["addmonth"]);
	std::cout <<"mydate.add_month(" << ma["addmonth"] << "); "<< mydate.string_rep() << std::endl;
	mydate.add_year(ma["addyear"]);
	std::cout <<"mydate.add_year(" << ma["addyear"] << "); "<< mydate.string_rep() << std::endl;
	std::cout << Chrono::Date(1, Chrono::Date::jan, 1971).unix_time() << std::endl;
}