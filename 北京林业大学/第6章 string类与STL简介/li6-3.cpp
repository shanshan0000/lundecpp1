#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str[5];
	cout<<"����5���ַ�����\n";
	for(int i=0;i<5;i++)
		cin>>str[i];

	cout<<"����ǰ����5���ַ���Ϊ��\n";
	for(int i=0;i<5;i++)
		cout<<str[i]<<"\n";
	for(int i=0;i<4;i++)
		for(int j=i+1;j<5;j++)
			if(str[i]>str[j])
			{
				string temp;
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
	cout<<"�������5���ַ���Ϊ��\n";
	for(int i=0;i<5;i++)
		cout<<str[i]<<"\n";

	return 0;
}