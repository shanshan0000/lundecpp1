#include <iostream>
using namespace std;

class Base 
{
private:
	int b;
public:
	Base(int i)
	{
		cout<<"ִ�л���Base�Ĺ��캯��\n";
		b = i;
	}
	~Base()
	{
		cout<<"ִ�л���Base����������\n";
	}
};
class A
{
private: 
	int a;
public:
	A(int n)
	{
		a = n;
		cout<<"ִ����A�Ĺ��캯��\n";
	}
	~A()
	{
		cout<<"ִ����A����������\n";
	}
};

class Derive : public Base
{
private:
	int d;
	A aobj;
public:
	Derive(int a, int b, int c): Base(b), aobj(a)
	{
		d = c;
		cout<<"ִ��������Derive�Ĺ��캯��\n";
	}
	~Derive()
	{
		cout<<"ִ��������Derive����������\n";
	}
};

int main()
{
	{Derive dobj(10,20,30);}
	return 0;
}
