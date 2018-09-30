// c7e19date.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;
struct Date
{
	short day;
	short month;
	short year;
	short wday;
};
int what_day(Date*);
void dprint(Date);

void wdpp(short& wd)
{
	short x = (wd++) % 7;
	wd = (x == 0) ? 7 : x;
}
void dincr(Date&);
void dincr(Date& d)
{
	//dprint(d);
	d.wday = what_day(&d);
	//dprint(d);
	if (d.day >= 1 && d.day <= 27)
	{
		d.day++;
		d.wday = what_day(&d);
		return;
	}
	if (d.day == 28 && d.month != 2) 
	{
		d.day++;
		d.wday = what_day(&d);
		return;
	}
	if (((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) && d.day == 28 && d.month == 2)
	{
		d.day++;
		d.wday = what_day(&d);
		return;
	}
	if ((d.year % 4 != 0 || (d.year % 100 == 0 && d.year % 400 != 0))&& d.day == 28 && d.month == 2)
	{
		d.day = 1;
		d.month++;
		d.wday = what_day(&d);
		return;
	}
	/*else
	{
		d.day = 1;
		d.month++;
		d.wday = what_day(&d);
		return;
	}*/
	if (d.day == 28 && d.month == 2)
	{
		d.day = 1;
		d.month++;
		d.wday = what_day(&d);
		return;
	}
	if (d.day == 28 && d.month != 2) 
	{
		d.day++;
		d.wday = what_day(&d);
		return;
	}
	if (d.day == 29 && d.month != 2)
	{
		d.day++;
		d.wday = what_day(&d);
		return;
	}
	if (d.day == 29 && d.month == 2)
	{
		d.day = 1;
		d.month++;
		d.wday = what_day(&d);
		return;
	}
	if (d.day == 30)
	{
		switch (d.month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			d.day++;
			d.wday = what_day(&d);
			//return;
			break;
		default:
			d.day = 1;
			d.month++;
			d.wday = what_day(&d);
			//return;
			break;
		}
		return;
	}
	if (d.day == 31)
	{
		if (d.month != 12)
		{
			d.day = 1;
			d.month++;
			d.wday = what_day(&d);
			return;
		}
		else
		{
			d.day = 1;
			d.month = 1;
			d.year++;
			d.wday = what_day(&d);
			return;
		}
	}
	
}
short s_to_sh(string);
short s_to_sh(string sz)
{
	istringstream mybufer;
	mybufer.str(sz);
	short sh;
	mybufer >> sh;
	return sh;
}
Date string_to_date(string);
Date string_to_date(string s)
{
	smatch sm;
	regex_match(s, sm, regex("(\\d{2})\\.(\\d{2})\\.(\\d{4})"));
	Date d;
	d.day = s_to_sh(sm[1]);
	d.month = s_to_sh(sm[2]);
	d.year = s_to_sh(sm[3]);
	return d;
}

int what_day(Date* date)
{
	int a = (14 - date->month) / 12;
	int y = date->year - a;
	int m = date->month + 12 * a - 2;
	return (7000 + (date->day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
}
Date find_date_for_next_monday(Date);
Date find_date_for_next_monday(Date d)
{
	
	
	dprint(d);
	dincr(d);
	d.wday = what_day(&d);
	dprint(d);
	while (d.wday != 1)
	{
		dincr(d);
		d.wday = what_day(&d);
		dprint(d);
	}
	return d;
}

void dprint(Date d1)
{
	cout << d1.day << '.' << d1.month << '.' << d1.year << " day "<<d1.wday<< '\n';
}

int main()
{
	/*Date date = string_to_date("26.07.2017");
	cout << what_day(&date)<<'\n';*/
	Date d0 = string_to_date("26.07.2017");
	d0.wday = what_day(&d0);
	Date d1 = find_date_for_next_monday(d0);
	dprint(d1);
	/*for (int i = 0; i < 10; i++)
	{
		dincr(date);
		dprint(date);
	}*/
	
}

