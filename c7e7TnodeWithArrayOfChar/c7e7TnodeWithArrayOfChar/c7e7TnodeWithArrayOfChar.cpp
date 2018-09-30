// c7e7Tnode.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
//#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tnode
{
	//string word;
	int szz;
	char* word;// = new char[szz];
	int count = 1;
	Tnode* left;
	Tnode* right;
	bool fr = false;
	bool fl = false;
};
//Tnode stop;


Tnode* f(Tnode tn, vector<char*>);
void insert(Tnode&, char*, vector < char* > = {});
void insert(Tnode& tn, char* s, vector<char*> v)
{
	int sz = v.size();
	if (sz == 0)
	{
		tn.szz=strlen(s); tn.word = s; //tn.left = &stop; tn.right = &stop;
	}
	if (sz > 0)
	{
		f(tn, v)->szz=strlen(s); f(tn, v)->word = s; //f(tn, v)->left = &stop; f(tn, v)->right = &stop;
							
	}

}
void associate(Tnode*, char*, Tnode&);
void associate(Tnode*n0, char* s, Tnode&n1)
{
	if (s == "left") { n0->left = &n1; n0->fl = true; }
	if (s == "right") { n0->right = &n1; n0->fr = true; }
}


Tnode* f(Tnode tn, vector<char*> v)
{
	int sz = v.size();
	if (sz == 1)
	{
		if (v[sz - 1] == "left") return tn.left;
		if (v[sz - 1] == "right") return tn.right;
	}
	if (sz > 1)
	{
		if (v[sz - 1] == "left")
		{
			v.pop_back();
			return f(tn, v)->left;
		}
		if (v[sz - 1] == "right")
		{
			v.pop_back();
			return f(tn, v)->right;
		}
	}
}

void nodeprint(Tnode*);
void nodeprint(Tnode* tn)
{
	//if (tn->count == 0) return;
	cout << tn->word << '\n';

	//nodeprint(tn->left); 

	// nodeprint(tn->right); 

	if (tn->fl) { /*cout << 48 << '\n';*/ nodeprint(tn->left); }
	if (tn->fr) {/* cout << 48 << '\n';*/ nodeprint(tn->right); }

}

void collector(Tnode* tn, vector<char*>& ov);
void collector(Tnode* tn, vector<char*>& ov)
{
	ov.push_back(tn->word);
	if (tn->fl) { collector(tn->left, ov); }
	if (tn->fr) { collector(tn->right, ov); }
}


void orderprint(Tnode*);
void orderprint(Tnode* tn)
{
	vector<char*> ov;
	collector(tn, ov);
	sort(ov.begin(), ov.end());
	for (vector<char*>::iterator it = ov.begin(); it != ov.end(); it++)
		cout << *it << '\n';
}

int main()
{

	//stop.count = 0;
	Tnode node;
	insert(node, "foundation");


	Tnode r;
	associate(&node, "right", r);
	//node.right = &r;
	insert(node, "ar", { "right" });



	Tnode node2;
	associate(&node, "left", node2);
	//node.left = &node2;
	insert(node, "l", { "left" });




	Tnode node3;
	associate(node.left, "left", node3);
	//node.left->left = &node3;
	insert(node, "ll", { "left","left" });

	nodeprint(&node);
	cout << '\n';
	orderprint(&node);
}

