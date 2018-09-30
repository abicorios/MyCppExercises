// c5e13date.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;
unsigned ld = 10;//a length of a date string, "12.45.7890" are 10 simbols
short np = 2;//a number of the points, "12.45.7890" have 2 points
short dp = 0;//a day position, the position of "12" in "12.45.7890" is 0, as far as a start is 0-position
short dl = 2;//a day length, the length of "12" string is 2
short mp = 3;//a month position, the position of "45" is 3, as far as the position of first point "." is 2
short ml = 2;//a month length is 2, it is the length of "45"
short yp = 6;//a year position is 6, the position of "7890" is 6
short yl = 4;//a year length is 4, it is the length of "7890"

struct Date
{
	string day;
	string month;
	string year;
};

Date init();

Date init()
{
	Date mydate;
	mydate.day= "00";
	mydate.month = "00";
	mydate.year = "0000";
	return mydate;
}

int main()
{
	vector<Date> fread();
	void fprint(vector<Date>);
	
	vector<Date> d = fread();
	fprint(d);
}

vector<Date> fread()
{
	
	vector<Date> dates;
	
	string st;
	getline(cin, st);
	//cin >> st;
	
	if (st.length() >= ld)
	{
		int n = st.length() - ld + 1;//a number of a shift for a date search
		cout << "n is " << n << '\n';
		for (short j = 1; j <= n; j++)
		{
			cout << "j is " << j << '\n';
			string s = st.substr(j - 1, 10);
			if (count(s.begin(), s.end(), '.') == np)
			{
				set<char> ss;
				ss.clear();
				for (unsigned i = 0; i < s.length(); i++) ss.insert(s[i]);
				ss.erase('.');
				set<char>::iterator e = ss.end();
				e--;
				if (*ss.begin() >= '0' && *e <= '9')
				{
					Date mydate = init();
					mydate.day = s.substr(dp, dl);
					mydate.month = s.substr(mp, ml);
					mydate.year = s.substr(yp, yl);
					dates.push_back(mydate);
				}
			}
		}
	}
	return dates;
}

void fprint(vector<Date> myvectordate)
{
	for(vector<Date>::iterator it= myvectordate.begin();it!=myvectordate.end();it++)
		cout<< (*it).day + '.' + (*it).month + '.' + (*it).year<<'\n';
}