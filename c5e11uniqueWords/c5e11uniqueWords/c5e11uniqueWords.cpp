// c5e11uniqueWords.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <string>
#include <set>

using namespace std;

int main()
{
	set<string> words;
	istream_iterator<string> ii(cin);
	while (*ii != "Q") { words.insert(*ii); ii++; }
	set<string>::iterator it;
	for (it = words.begin(); it != words.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
}