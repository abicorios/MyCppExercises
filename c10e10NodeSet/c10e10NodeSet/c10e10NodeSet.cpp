// c10e10NodeSet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <sstream>

class NodeSet
{
public:
	bool have(int x) { return set.have(x); }
	void insert(int x) { if (!have(x))set.insert(x); }
	NodeSet(std::vector<int> v = {}) { for (int vi : v)insert(vi); }
	static NodeSet union_of_sets(NodeSet, NodeSet);
	static NodeSet intersect_of_sets(NodeSet, NodeSet);
	static NodeSet simetric_sub_of_sets(NodeSet, NodeSet);
	static NodeSet sub_of_sets(NodeSet, NodeSet);
	std::string str()
	{
		std::stringstream s;
		s << '{';
		Node*it = &set;
		while (it->next->next)
		{
			//std::cout << "it is " << it << ",it->next is " << it->next << std::endl;
			s << it->x << ',';
			it = it->next;
		}
		s << it->x << '}';
		return s.str();
	}
private:
	class Node
	{
	public:
		Node() {}
		int x;
		Node* next = NULL;
		Node* end()
		{
			Node* tmp = this;
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			return tmp;
		}
		void insert(int x1) { Node* tmp = end(); tmp->x = x1; tmp->next = new Node; }
		bool have(int x)
		{
			Node* tmp = this;
			while (tmp->next)
			{
				if (tmp->x == x) return true;
				tmp = tmp->next;
			}
			return false;
		}
	};
	Node set;
};
NodeSet NodeSet::union_of_sets(NodeSet A, NodeSet B)
{
	NodeSet temp;
	Node*it = &A.set;
	while (it->next)
	{
		temp.insert(it->x);
		it = it->next;
	}
	it = &B.set;
	while (it->next)
	{
		temp.insert(it->x);
		it = it->next;
	}
	return temp;
}
NodeSet NodeSet::intersect_of_sets(NodeSet A, NodeSet B)
{
	NodeSet temp;
	Node*it = &A.set;
	while (it->next)
	{
		if(A.have(it->x)&&B.have(it->x)) temp.insert(it->x);
		it = it->next;
	}
	return temp;
}
NodeSet NodeSet::sub_of_sets(NodeSet A, NodeSet B)
{
	NodeSet temp;
	Node*it = &A.set;
	while (it->next)
	{
		if (!B.have(it->x)) temp.insert(it->x);
		it = it->next;
	}
	return temp;
}
NodeSet NodeSet::simetric_sub_of_sets(NodeSet A, NodeSet B)
{
	return sub_of_sets(union_of_sets(A, B), intersect_of_sets(A, B));
}
int main()
{
	//Node n(8);
	/*NodeSet::Node n;
	n.insert(8);
	std::cout << n.x << std::endl;
	n.insert(7);
	std::cout << n.next->x << std::endl;
	n.insert(5);
	std::cout << n.next->next->x << std::endl;*/
	NodeSet s({ 1,2 });
	for (int i:{1,2,3}) std::cout << s.have(i) << std::endl;
	s.insert(3);
	std::cout << s.have(3) << std::endl;
	std::cout << s.str() << std::endl;
	NodeSet t({ 2,3,4,5 });
	std::cout << s.str() << 'u' << t.str() << '=' << NodeSet::union_of_sets(s, t).str() << std::endl;
	std::cout << s.str() << "/\\" << t.str() << '=' << NodeSet::intersect_of_sets(s, t).str() << std::endl;
	std::cout << s.str() << "-" << t.str() << '=' << NodeSet::sub_of_sets(s, t).str() << std::endl;
	std::cout << s.str() << "~" << t.str() << '=' << NodeSet::simetric_sub_of_sets(s, t).str() << std::endl;
}