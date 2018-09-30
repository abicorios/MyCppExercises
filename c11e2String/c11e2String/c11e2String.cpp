// c11e2String.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
class String
{
	struct Srep;
	Srep* rep;
	class Cref;
public:
	class Range{};
	String();
	String(const char*);
	String(const String&);
	String& operator=(const char*);
	String& operator=(const String&);
	~String();
	//void check(int i) const { if (i < 0 ||  rep->sz <= i) throw Range(); }
	void check(int i) const;
	//char read(int i) const { return rep->s[i]; }
	char read(int i) const;
	//void write(int i, char c) { rep = rep->get_own_copy(); rep->s[i] = c; }
	void write(int i, char c);
	//Cref operator[] (int i) { check(i); return Cref(*this, i); }
	Cref operator[] (int i);
	//char operator[] (int i) const { check(i); return rep->s[i]; }
	char operator[] (int i) const;
	//int size() const { return rep->sz; }
	int size() const;
	String& operator+=(const String&);
	String& operator+=(const char*);
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
	/*friend bool operator==(const String& x,const char* s)
	{return strcmp(x.rep->s,s)==0; }*/
	friend bool operator==(const String& x, const char* s);
	/*friend bool operator==(const String& x,const String& y)
	{return strcmp(x.rep->s,y.rep->s)==0; }*/
	friend bool operator==(const String& x, const String& y);
	/*friend bool operator!=(const String& x,const char* s)
	{return strcmp(x.rep->s,s)!=0; }*/
	friend bool operator!=(const String& x, const char* s);
	/*friend bool operator!=(const String& x,const String& y)
	{return strcmp(x.rep->s,y.rep->s)!=0; }*/
	friend bool operator!=(const String& x, const String& y);
};

//void String::check(int i) const { if (i < 0 || rep->sz <= i) throw Range(); }
//char String::read(int i) const { return rep->s[i]; }
//void String::write(int i, char c) { rep = rep->get_own_copy(); rep->s[i] = c; }
//String::Cref String::operator[] (int i) { check(i); return Cref(*this, i); }
//char String::operator[] (int i) const { check(i); return rep->s[i]; }
//int String::size() const { return rep->sz; }
//bool operator==(const String& x,const char* s)
//	{return strcmp(x.rep->s,s)==0; }
//bool operator==(const String& x,const String& y)
//	{return strcmp(x.rep->s,y.rep->s)==0; }
//bool operator!=(const String& x,const char* s)
//	{return strcmp(x.rep->s,s)!=0; }
//bool operator!=(const String& x,const String& y)
//	{return strcmp(x.rep->s,y.rep->s)!=0; }
struct String::Srep
{
	char* s;
	int sz;
	int n;
	Srep()
	{
		s = "";
		sz = 0;
		n = 1;
	}
	Srep(int nsz, const char* p)
	{
		n = 1;
		sz = nsz;
		s = new char[sz + 1];
		strcpy(s, p);
	}
	~Srep() { delete[] s; }
	Srep* get_own_copy()
	{
		if (n == 1) return this;
		n--;
		return new Srep(sz, s);
	}
	void assign(int nsz, const char* p)
	{
		if (sz != nsz)
		{
			delete[] s;
			sz = nsz;
			s = new char[sz + 1];
		}
		strcpy(s, p);
	}
private:
	Srep(const Srep& t)
	{
		/*n = t.n;
		sz = t.sz;
		s = t.s;*/
		cout << "no" << endl;
	}
	Srep& operator=(const Srep& t)
	{
		/*n = t.n;
		sz = t.sz;
		s = t.s;*/
		cout << "no" << endl;
		return *this;
	}
};
void String::check(int i) const { if (i < 0 || rep->sz <= i) throw Range(); }
char String::read(int i) const { return rep->s[i]; }
void String::write(int i, char c) { rep = rep->get_own_copy(); rep->s[i] = c; }

char String::operator[] (int i) const { check(i); return rep->s[i]; }
int String::size() const { return rep->sz; }
bool operator==(const String& x,const char* s)
	{return strcmp(x.rep->s,s)==0; }
bool operator==(const String& x,const String& y)
	{return strcmp(x.rep->s,y.rep->s)==0; }
bool operator!=(const String& x,const char* s)
	{return strcmp(x.rep->s,s)!=0; }
bool operator!=(const String& x,const String& y)
	{return strcmp(x.rep->s,y.rep->s)!=0; }
String& String::operator+=(const String& t)
{
	char sto[1024];
	strcpy(sto, rep->s);
	strcat(sto, t.rep->s);
	return *this = sto;
}
String& String::operator+=(const char* t)
{
	char sto[1024];
	strcpy(sto, rep->s);
	strcat(sto, t);
	return *this=sto;
}
ostream& operator<<(ostream&o, const String&S)
{
	return o << S.rep->s;
}
istream& operator>>(istream&i, String&S)
{
	char* s=new char[1024];
	i >> s;
	S = s;
	return i;
}
String::String()
{
	rep = new Srep(0, "");
}
String::String(const String& x)
{
	x.rep->n++;
	rep = x.rep;
}
String::~String()
{
	cout << "I delete " << rep->s << endl;
	if (--rep->n == 0) delete rep;
}
String& String::operator=(const String& x)
{
	x.rep->n++;
	if (--rep->n == 0) delete rep;
	rep = x.rep;
	return *this;
}
String::String(const char* s)
{
	rep = new Srep(strlen(s), s);
}
String& String::operator=(const char* s)
{
	if (rep->n == 1)
		rep->assign(strlen(s), s);
	else
	{
		rep->n--;
		rep = new Srep(strlen(s), s);
	}
	return *this;
}
class String::Cref
{
	friend class String;
	String& s;
	int i;
	Cref(String& ss, int ii) :s(ss), i(ii) {}
	Cref(const Cref& r) :s(r.s), i(r.i) {}
	Cref();
public:
	operator char() const { s.check(i); return s.read(i); }
	void operator=(char c) { s.write(i, c); }
};
String::Cref String::operator[] (int i) { check(i); return Cref(*this, i); }
String operator+(const String&S1, const String&S2)
{
	String t = S1;
	t += S2;
	return t;
}
String operator+(const String&S, const char*s)
{
	String t = S;
	t += s;
	return t;
}
void p(String&);
void p(String& S)
{
	cout << S << endl;
}
void p(bool);
void p(bool b)
{
	cout << b << endl;
}
void p(char);
void p(char c)
{
	cout << c << endl;
}
void p(int);
void p(int i)
{
	cout << i << endl;
}
int main()
{
	String S("abc");
	p(S);
	p(S != "abc"); p(S != "abcd");
	p(S != String("abc")); p(S != String("abcd"));
	p(S + String("def")); p(S + "ghi");
	p(S == "abc"); p(S == "abcd");
	/*String S0;
	cin >> S0;
	p(S0);*/
	try
	{
		S.check(-1);
	}
	catch (String::Range)
	{
		cerr << "my error\n";
	}
	p(S[0]);
	p(S += "d");
	p(S += String("ef"));
	p(S = "ab");
	p(S = String("cd"));
	p(S.read(0));
	p(S);
	p(S.size());
	S.write(1, 'e');
	p(S);
}

