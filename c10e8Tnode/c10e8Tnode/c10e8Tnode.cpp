// c10e8Tnode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
class Tnode
{
public:
	std::string word;
	Tnode* left=NULL;
	Tnode* right=NULL;
	Tnode(std::string s="") { word = s; }
	void insert(std::string s) { word = s; }
	void l(std::string s) {if(!left) left = new Tnode; left->word = s; }
	void r(std::string s) {if(!right) right = new Tnode; right->word = s; }
	Tnode* adres(std::string s) 
	{ 
		if (s.size()) 
		{ 
			char c = s[0]; 
			s.erase(0, 1); 
			if (c == 'l')
			{
				if (!left) left = new Tnode;
				return left->adres(s);
			}
			else
			{
				if (!right) right = new Tnode;
				return right->adres(s);
			}
		}
		else 
			return this; 
	}
	~Tnode();
private:
	//Tnode* i = this;
	//Tnode::Tnode z;
};
Tnode::~Tnode()
{
	//if (!left) left->~Tnode();
	//if (!right) right->~Tnode();
	//delete[] this;
}
int main()
{
	Tnode t("a");
	std::cout << t.left << std::endl;
	t.l("b");
	std::cout << t.left->word << std::endl;
	t.left->l("c");
	std::cout << t.left->left->word << std::endl;
	std::cout << t.adres("ll")->word << std::endl;
	//std::cout << std::string("").size() << std::endl;
}