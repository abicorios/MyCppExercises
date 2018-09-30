// c9e4infoAboutComentsIntoHeaders.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <filesystem>
#include <sstream>
#include <vector>
#include <locale>
#include <Windows.h>

std::locale loc;


namespace fs = std::experimental::filesystem::v1;
int count_pattern(std::string, std::string);
int count_pattern(std::string str, std::string pattern)
{
	std::regex e(pattern);
	std::regex_iterator<std::string::iterator> itr(str.begin(), str.end(), e);
	std::regex_iterator<std::string::iterator> endr;
	int n = 0;
	while (itr!=endr)
	{
		itr++;
		n++;
	}
	return n;
}


std::string file_to_string(const char*);
std::string file_to_string(const char*name)
{
	std::ifstream f(name);
	if (!f) return "";
	std::string s0, s;
	while (std::getline(f, s0)) s += (s0 + "\n");
	f.close();
	return s;
}

std::string headerinfo(std::vector<std::string> paths, std::string file);
std::string headerinfo(std::vector<std::string> paths, std::string file)
{
	std::string folder;
	for (auto p : paths)
	{
		std::ifstream fz(p + "\\" + file);
		if (fz) folder = p;
	}
	
	
	
	std::string s = file_to_string((folder + "\\" + file).c_str());
	int w = 0;
	int flag = 0;
	for (char c : s)
	{
		if ((flag == 0) && ((!isalnum(c,loc)) && (c != '_')));
		else if ((flag == 0) && (isalpha(c,loc) || (c == '_'))) { w++; flag = 1; }
		else if ((flag == 1) && ((!isalnum(c,loc)) && (c != '_'))) flag = 0;
		else if ((flag == 1) && (isalnum(c,loc) || (c == '_')));
		/*if (isalnum(c)||(c=='_')) std::cout << c;
		else std::cout << w<<'\n';*/
	}
	
	//std::cout << s << std::endl;
	int lines = count_pattern(s, "\\n")+1;
	//for (std::string::iterator it=s.begin();it!=s.end();it++)
	/*for(char c:s)
	{
		if (c == '\n') lines++;
	}*/
	//std::smatch sm;
	//std::regex e("/\\*(.*\\n)*?.*?\\*/");
	//std::regex_search(s, sm, e);
	//std::cout << sm[0];
	int comentlines = 0;
	std::size_t i = 0;
	while (i<s.size())
	{
		std::size_t beginz = s.find("/*",i);
		std::size_t endz = s.find("*/",i+2);
		if (beginz != std::string::npos&&endz != std::string::npos)
		{
			comentlines += (count_pattern(s.substr(beginz, endz - beginz), "\\n") + 1);
			i = endz;
		}
		else
			break;
	}
	//int comentlines = min(count_pattern(s,"/\\*"), count_pattern(s, "\\*/"));
	/*std::sregex_iterator rit(s.begin(), s.end(), e);
	std::sregex_iterator rend;*/
	//std::regex_iterator<std::string::iterator> rit(s.begin(), s.end(), e);
	//std::regex_iterator<std::string::iterator> rend;
	/*while (rit != rend)
	{
		std::cout << rit->str() << '\n';
		comentlines++;
		++rit;
	}*/
	//while (std::regex_search(s,sm,e))
	//{
	//	if (file == "Windows.h") std::cout << sm[0]<<' '<<file<<'\n'<<sm.position()<<'\n'<< sm.length()<<'\n';
	//	
	//	//s=std::regex_replace(s, e, "",std::regex_constants::format_first_only);
	//	std::string coment = sm[0];
	//	coment += "\n";
	//	for (auto c : coment) if (c == '\n')comentlines++;
	//	s.replace(sm.position(), sm.length(), "\n");
	//	//std::cout << coment;
	//}
	comentlines += count_pattern(s, "//.*");
	//std::regex e2("//.*");
	//while (std::regex_search(s,sm,e2))
	//{
	//	if(file=="Windows.h") std::cout << sm[0] << ' ' << file << '\n' << sm.position() << '\n' << sm.length() << '\n';
	//	comentlines++;
	//	std::cout << comentlines << '\n';
	//	s.replace(sm.position(), sm.length(), "");
	//	std::cout<<"s.replace" << '\n';
	//	//s = std::regex_replace(s, e2, "", std::regex_constants::format_first_only);
	//}
	//std::cout << s<<lines<<std::endl;
	//int w = 0;
	//while (std::regex_search(s2,sm,std::regex("\\w+")))
	//{
	//	w++; 
	//	//s2 = std::regex_replace(s2, std::regex("\\w+"), "", std::regex_constants::format_first_only);
	//	s2.replace(sm.position(), sm.length(), "\n");
	//}
	
	std::ostringstream rez;
	rez << "header " << file << ", coment lines " << comentlines << ", no coment lines " << lines - comentlines <<", words "<<w<< std::endl;
	return rez.str();
}

//#include <cstdlib>
void print_headers_of_sourcefile(const char*, std::vector<std::string> paths);
void print_headers_of_sourcefile(const char*name, std::vector<std::string> paths)
{
	/*std::ifstream f(name);
	if (!f) std::cerr << "cannot open\\n";
	std::string s0, s;
	while (std::getline(f, s0)) s += (s0 + "\\n");
	f.close();*/
	//std::cout << s;
	std::string s = file_to_string(name);
	std::smatch sm;
	std::regex e("^#include +([\"<](.+)[\">])");
	std::regex_search(s, sm, e);
	std::regex_iterator<std::string::iterator> rit(s.begin(), s.end(), e);
	std::regex_iterator<std::string::iterator> rend;
	std::cout << name << std::endl;
	while (rit != rend)
	{
		std::cout << '\t' << headerinfo(paths,rit->str(2)) << '\n';
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

void print_headers_used_in_folder(std::string folder, std::string expression, std::vector<std::string> paths);
void print_headers_used_in_folder(std::string folder, std::string expression, std::vector<std::string> paths)
{
	std::string path = folder;
	for (auto & p : fs::directory_iterator(path))
	{
		std::string ps = to_s(p);
		if (std::regex_match(ps, std::regex(expression)))
			print_headers_of_sourcefile(ps.c_str(),paths);
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::vector<std::string> paths = { "d:\\Users\\Спартак\\Documents\\Visual Studio 2017\\Projects\\c9e4infoAboutComentsIntoHeaders\\c9e4infoAboutComentsIntoHeaders",
		"d:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\include" ,
	"c:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.15063.0\\ucrt",
	"C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.15063.0\\um",
	"C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.15063.0\\shared"};
	//std::string filepath = "C:\\Program Files (x86)\\Windows Kits\\10\\Include\\10.0.15063.0\\um\\Windows.h"; // the file you provided
	//std::ifstream ifs(filepath.c_str(), std::ios_base::in | std::ios_base::binary);

	//ifs.seekg(0, std::ios_base::end);
	//size_t length = static_cast<size_t>(ifs.tellg());
	//ifs.seekg(0, std::ios_base::beg);

	//std::string text;
	//text.resize(length);

	//ifs.read(&text[0], length);
	//ifs.close();

	//std::string pattern("/\\*(.*\\n)*?.*?\\*/");
	//std::regex r(pattern, std::regex::icase);
	//for (std::sregex_iterator it(text.begin(), text.end(), r), end_it; it != end_it; ++it)
	//{
	//	std::cout << it->str() << std::endl;
	//}
	//std::cout << headerinfo(paths, "Windows.h");
	//std::cout << headerinfo(paths, "iostream");
	
	//std::cout<<headerinfo("d:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\include", "ConcurrencySal.h");
	print_headers_used_in_folder("D:\\Users\\Спартак\\Documents\\Visual Studio 2017\\Projects\\c9e4infoAboutComentsIntoHeaders\\c9e4infoAboutComentsIntoHeaders", "^.+\\.(cpp|h)$",paths);
	//print_headers_used_in_folder("d:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\VC\\Tools\\MSVC\\14.10.25017\\include", "^.+\\.(cpp|h)$");
}

