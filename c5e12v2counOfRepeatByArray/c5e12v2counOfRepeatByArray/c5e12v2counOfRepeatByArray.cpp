// c5e12v2counOfRepeatByArray.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
    char*s= "abcabcabcacac";
	char*s1 = "ca";
	short i = 0;
	short count = 0;
	while (s[i] != '\0'&&s[i + 1] != '\0')
	{
		if (s[i] == s1[0] && s[i + 1] == s1[1]) count++;
		i++;
	}
	printf("%d\n", count);
}

