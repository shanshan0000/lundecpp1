#include <iostream>
using namespace std;

void fun()
{
	try{
		throw 'A';
	}
	catch(char)
	{
		cout<<"�ڲ��쳣����"<<endl;
		throw 'B';
	}
}

int main()
{
	try{
		fun();
	}
	catch(char)
	{
		cout<<"�ⲿ�쳣����"<<endl;
	}
	return 0;
}