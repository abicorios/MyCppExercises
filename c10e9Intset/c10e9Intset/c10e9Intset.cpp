// c10e9Intset.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
class Intset
{
public:
	Intset(std::vector<int> v0 = {}) { for (int u : v0)insert(u); }
	void insert(int x) { if (!have(x))v.push_back(x); }
	bool have(int x) {return std::find(v.begin(), v.end(), x) != v.end(); }
	static Intset union_of_sets(Intset, Intset);
	static Intset intersect_of_sets(Intset, Intset);
	static Intset simetric_sub_of_sets(Intset,Intset);
	static Intset sub_of_sets(Intset, Intset);
	std::string str()
	{
		std::stringstream s;
		s << "{";
		for (std::vector<int>::iterator it = v.begin(); it + 1 < v.end();it++) s << *it << ',';
		s << v[v.size() - 1] << '}';
		return s.str();
	}
private:
	std::vector<int> v;
};
Intset Intset::union_of_sets(Intset A, Intset B)
{
	Intset temp;
	temp.v = A.v;
	for (int x : B.v) temp.insert(x);
	return temp;
}
Intset Intset::intersect_of_sets(Intset A, Intset B)
{
	Intset temp;
	for (int x : A.v) if (A.have(x) && B.have(x)) temp.insert(x);
	return temp;
}
Intset Intset::sub_of_sets(Intset A, Intset B)
{
	Intset temp;
	for (int x : A.v) if (!B.have(x)) temp.insert(x);
	return temp;
}
Intset Intset::simetric_sub_of_sets(Intset A, Intset B)
{
	return sub_of_sets(union_of_sets(A, B), intersect_of_sets(A, B));
}
int main()
{
	Intset s({3,4});
	s.insert(1);
	std::cout << s.have(1) << std::endl;
	std::cout << s.have(2) << std::endl;
	std::cout << s.have(3) << std::endl;
	std::cout << s.have(4) << std::endl;
	Intset t({ 2,3,4,5 });
	std::cout<< s.str()<<'u'<<t.str()<<'='<<Intset::union_of_sets(s,t).str()<<std::endl;
	std::cout << s.str() << "/\\" << t.str() << '=' << Intset::intersect_of_sets(s, t).str() << std::endl;
	std::cout << s.str() << "-" << t.str() << '=' << Intset::sub_of_sets(s, t).str() << std::endl;
	std::cout << s.str() << "~" << t.str() << '=' << Intset::simetric_sub_of_sets(s, t).str() << std::endl;

}