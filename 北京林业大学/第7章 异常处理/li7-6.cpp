#include <iostream>
using namespace std;

class Demo
{
public:
	int x;
	Demo(int y)
	{
		x = y;
		cout<<"����Demo��Ĺ��캯��"<<endl;
		if(x<0) throw x;
		else
			cout<<"����Demo��Ĺ��캯�����������"<<y<<endl;
	}
	~Demo()
	{
		cout<<"����Demo���������������������"<<x<<endl;
	}
};

void fun()
{
	cout<<"���뺯��fun"<<endl;
	Demo d1(4),d2(-5);  // fun��ִֹ��
	throw 'A';
}

int main()
{
	cout<<"��������ʼִ��"<<endl;
	try{
		cout<<"����fun����"<<endl;
		fun();
	}
	catch(int n)
	{
		cout<<"����"<<n<<"��������"<<endl;
	}
	catch(char)
	{
		cout<<"�ں������׳��쳣"<<endl;
	}
	cout<<"������ִ�����"<<endl;
	return 0;
}