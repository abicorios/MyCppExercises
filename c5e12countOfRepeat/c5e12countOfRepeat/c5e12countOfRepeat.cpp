// c5e12countOfRepeat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "abcabcabcacac";
	string s1 = "ca";
	short start = 0;
	short count = 0;
	
	while (start<s.length()&&start>=0)
	{
		start= s.find(s1, start);
		//cout << start << '\n';
		if (start >= 0)
		{
			start++;
			count++;
		}
	}

	cout << s1 << " in " << s << " is " << count << " times.\n";
}