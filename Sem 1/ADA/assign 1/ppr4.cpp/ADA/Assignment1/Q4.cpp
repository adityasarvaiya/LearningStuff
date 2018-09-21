#include <bits/stdc++.h>
using namespace std;


class String{
	int length;
	char* s;
	
	public:
	String(int _length, char a[]) : length(_length)
	{
		s = new char[length];
		for(int i=0; i<length; ++i){
			s[i] = a[i];
		}
	}
	
	String(int _length) : length(_length)
	{
		s = new char[length];
	}
	
	int len(){
		return length;
	}
	
	char& operator[](int& i)
	{
		return s[i];
	}
	
	String concat(String x)
	{
		int i, l;
		
		i = 0;
		l = length + x.len();
		
		char *tmp = new char[l];
		
		for(i=0; i<length; ++i){
			tmp[i] = s[i];
		}
		for(; i<l; ++i){
			tmp[i] = x[i];
		}
		
		String n(length+x.len(), tmp);
		return n;
	}
	
	friend String operator+(String& a, String&b)
	{
		int i;
		int l = a.len() + b.len();
		String* c = new String(l);
		for(i=0; i<a.len(); ++i){
			c[i] = a[i];
		}
		for(; i<l; ++i){
			c[i] = b[i];
		}
		return *c;
	}
	
	friend ostream& operator<<(ostream &os, String& str)
	{
		os<<str.s;
		return os;
	}
	/*
	friend istream& operator >>(istream &is, String& str)
	{
		is>>str.s;
		return is;
	}*/
};


int main(){
	String s(6, (char*)"ACBCDEFGH");
	cout<<s<<"\n";
	return 0;
}
