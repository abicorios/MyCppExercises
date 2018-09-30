// c10e12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
class Node
{
public:
	Node() {}
	char x=0;
	Node* next = 0;
	int count() 
	{ 
		int a=0; 
		Node* tmp = this; 
		while (tmp->next) 
		{ 
			//std::cout << a << std::endl;
			tmp = tmp->next; 
			a++; 
		} 
		return a; 
	}
	Node* first(int i = 1)
	{
		Node*tmp = this;
		while (--i)
		{
			tmp = tmp->next;
		}
		return tmp;
	}
	Node*last(int i = 1)
	{
		return first(count() - i + 1);
	}
	Node* end()
	{
		Node* tmp = this;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		return tmp;
	}
	Node* preend()
	{
		Node* tmp = this;
		while (tmp->next->next)
		{
			tmp = tmp->next;
		}
		return tmp;
	}
	void insert(char x1) { Node* tmp = end(); tmp->x = x1; tmp->next = new Node; }
	bool have(char x)
	{
		Node* tmp = this;
		while (tmp->next)
		{
			if (tmp->x == x) return true;
			tmp = tmp->next;
		}
		return false;
	}
	//void shift() { next = next->next; }
};
class Char_queue
{
public:
	Char_queue() {};
	void in(char c0) { q.insert(c0); }
	char out() 
	{
		/*Node*tmp = q.last();
		char t = tmp->x;
		tmp->x = 0;
		tmp->next = 0;
		return t;*/
		char t = q.x;
		q = *q.next;
		return t;
	}
	int count() {return q.count(); }
private:
	Node q;
};
class Char_queue2
{
public:
	Char_queue2() {}
	void in(char c0) { v.push_back(c0); }
	char out()
	{
		char t = v[0];
		v.erase(v.begin());
		return t;
	}
	int count() { return v.size(); }
private:
	std::vector<char> v;
};



int main()
{
	Node n;
	std::cout << n.count() << std::endl;
	n.insert('+');
	std::cout << n.count() << std::endl;
	std::cout << n.first(1)->x << std::endl;
	std::cout << n.last(1)->x << std::endl;
	Char_queue q;
	std::cout << "Char_queue\n";
	std::cout << q.count() << std::endl;
	q.in('*');
	q.in('=');
	std::cout << q.count() << std::endl;
	std::cout << q.out() << std::endl;
	std::cout << q.count() << std::endl;
	Char_queue2 q2;
	std::cout << "Char_queue2\n";
	std::cout << q2.count() << std::endl;
	q2.in('*');
	q2.in('=');
	std::cout << q2.count() << std::endl;
	std::cout << q2.out() << std::endl;
	std::cout << q2.count() << std::endl;
}

