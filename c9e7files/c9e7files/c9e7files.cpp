// c9e7files.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <string>

int main()
{
	for (int i = 0; i < 100; i++)
	{
		std::string name = "test"+ std::to_string(i)+ ".txt";
		std::ofstream ofs(name, std::ofstream::out);

		//ofs << "lorem ipsum";
		for (int j = 0; j < 1500; j++)
			ofs << j % 10;

		ofs.close();
	}
	std::ofstream ofs("test.txt", std::ofstream::out);
	for (int j = 0; j < 15000; j++)
		ofs << j % 10;
	ofs.close();
}

