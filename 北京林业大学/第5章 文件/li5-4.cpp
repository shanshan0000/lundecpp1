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
	Student stu[3] = {{"Mary","001",98},{"Susan","002",97},{"Peter","003",99}};
	fstream myfile;
	myfile.open("test.txt",ios::out|ios::in | ios::binary);  // ios::in | ios::out ��Ҫ�ȴ����ļ�
	if(!myfile)
	{
		cout<<"cannot open text.txt\n";
		exit(0);
	}
	for(int i=0;i<3;i++)
		myfile.write((char *)&stu[i],sizeof(Student));
	myfile.seekp(sizeof(Student)*2);               //ָ���3��ͬѧ,��fstream��,seekp��seekgû������
	Student temp;
	myfile.read((char *)&temp,sizeof(Student));
	cout<<temp.name<<"\t"<<temp.num<<"\t"<<temp.score<<"\n";
	myfile.seekp(0);                //ָ���1λͬѧ         
	myfile.read((char *)&temp,sizeof(Student));
	cout<<temp.name<<"\t"<<temp.num<<"\t"<<temp.score<<"\n";
	myfile.seekp(sizeof(Student)*1, ios::cur);         //ָ���3��ͬѧ
	myfile.read((char *)&temp,sizeof(Student));
	cout<<temp.name<<"\t"<<temp.num<<"\t"<<temp.score<<"\n";
	myfile.seekp(sizeof(Student)*1, ios::beg);         //ָ���2��ͬѧ
	myfile.read((char *)&temp,sizeof(Student));
	cout<<temp.name<<"\t"<<temp.num<<"\t"<<temp.score<<"\n";

	myfile.close();


	return 0;
}