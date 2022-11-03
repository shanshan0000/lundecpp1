#include <iostream>
#include <iomanip>
using namespace std;
#define max 3

class Info
{
protected:
	int no;
	char name[20];
	double score;
public:
	void getInfo()
	{
		cout<<"����ѧ�š������ͳɼ���";
		cin>>no>>name>>score;
		if(no<=0 || no>max)
			throw no;
		if(score<0.0 || score>100.0)
			throw score;
	}
	void show()
	{
		cout<<setw(4)<<no<<setw(20)<<name<<setw(6)<<score<<endl;
	}
};



int main()
{
	Info stu[max];
	cout<<"��������Ϣ��\n";
	for(int i=0;i<max;i++)
	{
		try{
			stu[i].getInfo();
		}
		catch(int)
		{
			cout<<"ѧ������Խ��\n";
		}
		catch(double)
		{
			cout<<"�ɼ�Խ��\n";
		}
	}
	cout<<"���������Ϊ��\n";
	for(i=0;i<max;i++)
		stu[i].show();
	return 0;
}