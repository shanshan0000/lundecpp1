#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str("He world.");
	string ins;
	cout<<"ԭ�ַ����ǣ�"<<str<<endl;
	cout<<"����Ҫ������ַ�����";
	cin>>ins;
	str.insert(2,ins,0,ins.size());
	cout<<"���ַ����ǣ�"<<str<<endl;

	return 0;
}