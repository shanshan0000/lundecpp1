#include <iostream>
using namespace std;

class B
{
protected:
	int b;
public:
	B(int bval)
	{
		cout<<"ִ����B�Ĺ��캯��\n";
		b = bval;
	}
};
class D1 : virtual public B
{
protected: 
	int d1;
public:
	D1(int bval, int dval) : B(bval)
	{
		d1 = dval;
		cout<<"ִ����D1�Ĺ��캯��\n";
	}
};

class D2 : virtual public B
{
protected: 
	int d2;
public:
	D2(int bval, int dval) : B(bval)
	{
		d2 = dval;
		cout<<"ִ����D2�Ĺ��캯��\n";
	}
};

class Derive : public D1, public D2
{
protected:
	int d3;
public:
	Derive(int bval, int dval1, int dval2, int dval3): D1(bval, dval1), D2(bval, dval2), B(bval)
	{
		d3 = dval3;
		cout<<"ִ����Derive�Ĺ��캯��\n";
	}
	void show()
	{
		cout<<"��Աb��ֵΪ��"<<b<<"\n";
		cout<<"��Աd1��ֵΪ��"<<d1<<"\n";
		cout<<"��Աd2��ֵΪ��"<<d2<<"\n";
		cout<<"��Աd3��ֵΪ��"<<d3<<"\n";
	}
};

int main()
{
	Derive dobj(10,20,30,40);
	dobj.show();
	return 0;
}
