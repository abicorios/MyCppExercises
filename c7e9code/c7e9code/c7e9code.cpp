// c7e9code.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//#include <string>
//#include <sstream>
using namespace std;

//int main(int argc,char* argv[])
int main()
{
	char*input="hello world";
	printf("%d\n", strlen(input));
	char*key="spbr";
	char*output = new char[strlen(input+1)];
	output[strlen(input)] = 0;
	for (int i = 0; input[i] != 0; i++) output[i] = input[i] ^ key[i%strlen(key)];
	for (int i = 0; output[i] != 0; i++) printf("%d\n", output[i]);
	//for (int i = 0; 'a' + i != 'z' + 1; i++) printf("%d %c\n", i+1, 'a' + i);
	vector<vector<char>> breakz(strlen(output),vector<char>(0));
	for (int i = 0; 'a' + i != 'z' + 1; i++) if( (('a' + i) ^ output[0])>='a'&& (('a' + i) ^ output[0])<='z') printf("%c %d %d %c\n", 'a' + i, 'a' + i, ('a' + i) ^ output[0], ('a' + i) ^ output[0]);
	for (int j = 0; j < strlen(output); j++)
	{
		for (int i = 0; 'a' + i != 'z' + 1; i++)
		{
			char d;
			d = ('a' + i) ^ output[j];
			if ((d >= 'a' && d <= 'z')||d==' ') breakz[j].push_back(d);
		}
	}
	for (int i = 0; 'a' + i != 'z' + 1; i++)
	{
		for (int j = 0; j < strlen(output); j++)
		{
			if (i < breakz[j].size())
				printf("%c ", breakz[j][i]);
			else
				printf("  ");
		}
		printf("\n");
	}
}

