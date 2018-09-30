// c6e1for.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char* input_line = "abc?abc?ab?";
	short max_length = 0;
	char*pi = input_line;
	while (*pi++) max_length++;
	cout << max_length<<'\n';
	short quest_count = 0;
	short i;
	for (i = 0; i < max_length; i++)
		if (input_line[i] == '?')quest_count++;
	cout << "quest_count is " << quest_count << '\n';
	char*p = input_line;
	quest_count = 0;
	while(*p++)*p=='?'?quest_count++:0;
	cout << "quest_count is " << quest_count << '\n';
}

