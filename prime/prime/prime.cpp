// prime.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>


int main()
{
	int n;
	std::cout << "input n\n";
	std::cin >> n;
	/*int x[10];
	for (int k = 0; k < 10; k++) x[k] = k;
	int y[10][10];
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) y[i][j] = i*j;*/
	std::set<int> numbers;
	for (int i = 2; i <= n; i++) numbers.insert(i);
	std::set<int> multiples;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) multiples.insert(i*j);
	}
	std::set<int> result;
	std::set_difference(numbers.begin(), numbers.end(), multiples.begin(), multiples.end(),std::inserter(result, result.end()));
	std::set<int>::iterator it;
	for (it = result.begin(); it != result.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

