#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Student{
	char name[20];
	char num[10];
	double score;
};

int main()
{
	Student temp[100];
	int n;
	cout<<"����ѧ����������";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		fflush(stdin);   //��ջ�����
		cout<<"�����"<<i+1<<"��ѧ����������ѧ�źͳɼ���";
		cin.getline(temp[i].name,20);
		cin>>temp[i].num>>temp[i].score;
	}
	fstream fin, fout;
	fout.open("data.dat",ios::out);
	if(!fout)
	{
		cout<<"cannot open data.dat.\n";
		exit(0);
	}
	for(i=0;i<n;i++)
		fout.write((char *)&temp[i],sizeof(Student));
	fout.close();
	fin.open("data.dat",ios::in);
	if(!fin)
	{
		cout<<"cannot open data.dat.\n";
		exit(0);
	}
	cout<<"����\tѧ��\t�ɼ�\n";
	for(i=0;i<n;i++)
	{
		fout.read((char *)&temp[i],sizeof(Student));
		cout<<temp[i].name<<"\t"<<temp[i].num<<"\t"<<temp[i].score<<"\n";
	}
	fin.close();


	return 0;
}