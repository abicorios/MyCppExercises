// minmaxsizes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	std::cout << "min(char)=" << std::numeric_limits<char>::min()<<'\t'<<int(std::numeric_limits<char>::min())<<'\n';
	std::cout << "max(char)=" << std::numeric_limits<char>::max() << '\t' << int(std::numeric_limits<char>::max()) << '\n';

	std::cout << "min(short)=" << std::numeric_limits<short>::min() << '\n';
	std::cout << "max(short)=" << std::numeric_limits<short>::max() << '\n';

	std::cout << "min(int)=" << std::numeric_limits<int>::min() << '\n';
	std::cout << "max(int)=" << std::numeric_limits<int>::max() << '\n';

	std::cout << "min(long)=" << std::numeric_limits<long>::min() << '\n';
	std::cout << "max(long)=" << std::numeric_limits<long>::max() << '\n';

	std::cout << "min(float)=" << std::numeric_limits<float>::min() << '\n';
	std::cout << "max(float)=" << std::numeric_limits<float>::max() << '\n';

	std::cout << "min(double)=" << std::numeric_limits<double>::min() << '\n';
	std::cout << "max(double)=" << std::numeric_limits<double>::max() << '\n';

	std::cout << "min(long double)=" << std::numeric_limits<long double>::min() << '\n';
	std::cout << "max(long double)=" << std::numeric_limits<long double>::max() << '\n';

	std::cout << "min(unsigned)=" << std::numeric_limits<unsigned>::min() << '\n';
	std::cout << "max(unsigned)=" << std::numeric_limits<unsigned>::max() << '\n';
}

