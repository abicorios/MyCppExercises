// c9e3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <filesystem>
#include <sstream>
namespace fs = std::experimental::filesystem::v1;


//#include <cstdlib>
void print_headers_of_sourcefile(const char*);
void print_headers_of_sourcefile(const char*name)
{
	std::ifstream f(name);
	if (!f) std::cerr << "cannot open\n";
	std::string s0, s;
	while (std::getline(f, s0)) s += (s0 + "\n");
	f.close();
	//std::cout << s;
	std::smatch sm;
	std::regex e("^#include +(.+)$");
	std::regex_search(s, sm, e);
	std::regex_iterator<std::string::iterator> rit(s.begin(), s.end(), e);
	std::regex_iterator<std::string::iterator> rend;
	std::cout << name << std::endl;
	while (rit != rend)
	{
		//v_variables.push_back(rit->str());
		std::cout << '\t' << rit->str(1) << '\n';
		++rit;
	}
}

std::string to_s(fs::directory_entry);
std::string to_s(fs::directory_entry p)
{
	std::ostringstream ostr;
	ostr << p;
	return ostr.str();
}

void print_headers_used_in_folder(std::string folder, std::string expression);
void print_headers_used_in_folder(std::string folder, std::string expression)
{
	std::string path = folder;
	for (auto & p : fs::directory_iterator(path))
	{
		std::string ps = to_s(p);
		if (std::regex_match(ps, std::regex(expression)))
			print_headers_of_sourcefile(ps.c_str());
	}
}

int main()
{
	print_headers_used_in_folder("D:\\Users\\Спартак\\Documents\\Visual Studio 2017\\Projects\\c9e3\\c9e3", "^.+\\.(cpp|h)$");
	print_headers_used_in_folder("d:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\include", "^.+\\.(cpp|h)$");
}

