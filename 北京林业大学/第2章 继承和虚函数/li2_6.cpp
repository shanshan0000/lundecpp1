#include <iostream>
using namespace std;

class B1
{
protected:
	int b1;
public:
	B1(int i)
	{
		cout<<"ִ�л���B1�Ĺ��캯��\n";
		b1 = i;
	}
	~B1()
	{
		cout<<"ִ�л���B1����������\n";
	}
};
class B2
{
protected: 
	int b2;
public:
	B2(int n)
	{
		b2 = n;
		cout<<"ִ�л���B2�Ĺ��캯��\n";
	}
	~B2()
	{
		cout<<"ִ�л���B2����������\n";
	}
};

class Derive : public B2, public B1
{
protected:
	int d;
public:
	Derive(int a, int b, int c): B1(a), B2(b)
	{
		d = c;
		cout<<"ִ��������D�Ĺ��캯��\n";
	}
	~Derive()
	{
		cout<<"ִ��������D����������\n";
	}
};

int main()
{
	{Derive dobj(10,20,30);}
	return 0;
}


#include <iostream>
using namespace std;

class B1
{
protected:
	int b;
public:
	B1(int i)
	{
		cout<<"ִ�л���B1�Ĺ��캯��\n";
		b = i;
	}
	~B1()
	{
		cout<<"ִ�л���B1����������\n";
	}
};
class B2
{
protected: 
	int b;
public:
	B2(int n)
	{
		b = n;
		cout<<"ִ�л���B2�Ĺ��캯��\n";
	}
	~B2()
	{
		cout<<"ִ�л���B2����������\n";
	}
};

class Derive : public B2, public B1
{
protected:
	int d;
public:
	Derive(int a, int b, int c): B1(a), B2(b)
	{
		d = c;
		cout<<"ִ��������D�Ĺ��캯��\n";
	}
	~Derive()
	{
		cout<<"ִ��������D����������\n";
	}
	void showb(){cout<<B1::b<<"\t"<<B2::b<<endl;}
};

int main()
{
	{
		Derive dobj(10,20,30);
		dobj.showb();
	}
	return 0;
}
