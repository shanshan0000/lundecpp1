#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec1(5);
	vector<int>::iterator it1;  //�����������������ĵ���������it1
	cout<<"����5��������";
	for(it1 = vec1.begin();it1!=vec1.end();it1++)
		cin>>*it1;
	cout<<"vec1�е�Ԫ�ظ�����"<<vec1.size()<<endl;
	cout<<"vec1�е�Ԫ��ֵ�ֱ�Ϊ��";
	for(it1 = vec1.begin();it1!=vec1.end();it1++)
		cout<<*it1<<" ";
	cout<<"\n\n";

	vector<char> vec2(5);
	vector<char>::iterator it2;  //�����������������ĵ���������it1
	cout<<"����5���ַ���";
	for(it2 = vec2.begin();it2!=vec2.end();it2++)
		cin>>*it2;
	cout<<"vec2�е�Ԫ�ظ�����"<<vec2.size()<<endl;
	cout<<"vec2�е�Ԫ��ֵ�ֱ�Ϊ��";
	for(it2 = vec2.begin();it2!=vec2.end();it2++)
		cout<<*it2<<" ";
	cout<<endl;

	return 0;
}