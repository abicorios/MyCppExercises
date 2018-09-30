// c5e11uniqueWordsByVector.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> words;
	vector<string> uwords;
	vector<string>::iterator it;
	istream_iterator<string> ii(cin);

	while (*ii != "Q") { words.push_back(*ii); ii++; }
	uwords.push_back(words[0]);
	words.erase(words.begin());
	int mycount;
	int iters = words.size();
	for (int i = 0; i < iters; i++)
	{
		mycount = count(uwords.begin(), uwords.end(), words[0]);
		if (mycount == 0) uwords.push_back(words[0]);
		words.erase(words.begin());
	}

	for (it = uwords.begin(); it != uwords.end(); it++) cout << *it << '\n';
}