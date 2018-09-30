// c7e11errorLikeOnPrintf.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstdarg>
#include <regex>
#include <sstream>
using namespace std;
//const char* Null_cp = 0;
string ca_to_s(char*);
string ca_to_s(char* ca)
{
	ostringstream mybufer;
	mybufer << ca;
	return mybufer.str();
}
string i_to_s(int);
string i_to_s(int iz)
{
	ostringstream mybufer;
	mybufer << iz;
	return mybufer.str();
}
void error(string s...);
void error(string s...)
{
	va_list ap;
	va_start(ap, s);
	smatch sm;
	regex e("%.");
	/*while (regex_search(s, sm, e))
	{
		char* ca = va_arg(ap, char*);
		string z = ca_to_s(ca);
		s = regex_replace(s, e, z, regex_constants::format_first_only);
	}*/
	while (regex_search(s,sm,e))
	{
		if (sm[0] == "%c")
		{
			char c = va_arg(ap, char);
			
			string z = { c };
			
			s = regex_replace(s, e, z, regex_constants::format_first_only);
		}

		if (sm[0] == "%d")
		{
			int d = va_arg(ap, int);
			
			string z = i_to_s(d);
			
			s = regex_replace(s, e, z, regex_constants::format_first_only);
		}
		
		if (sm[0] == "%s")
		{
			char* ca = va_arg(ap, char*);
			string z = ca_to_s(ca);
			
			s = regex_replace(s, e, z, regex_constants::format_first_only);
		}
	}
	va_end(ap);
	cout << s << '\n';
}

int main()
{
	error("%s,  %d is %c%c%c","okay",2,'t','w','o');
}

