#include <iostream>
#include <cstdio>
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
	
	cout << "����ѧ����������";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		fflush(stdin);   //��ջ�����
		cout << "�����" << i + 1 << "��ѧ����������ѧ�źͳɼ���";
		cin.getline(temp[i].name, 20);
		cin >> temp[i].num >> temp[i].score;
	}
	FILE * out;
	out = fopen("text.txt", "w");  // fopen_s(&out, "text.txt", "w");
	if (!out)
	{
		cout << "cannot open text.txt. out \n";
		exit(0);
	}
	for (int i = 0; i<n; i++)
	{
		if (fwrite(&temp[i], sizeof(Student), 1, out) != 1)
		{
			cout << "file write error.\n";
			exit(0);
		}
	} 
	fclose(out);

	FILE * in;
	in = fopen("text.txt", "r");  // fopen_s(&in, "text.txt", "r"); 
	if (!in)
	{
		cout << "cannot open text.txt. in \n";
		exit(0);
	}
	
	cout << "����\tѧ��\t�ɼ�\n";
	for (int i = 0; i<n; i++)
	{
		fread(&temp[i], sizeof(Student), 1, in);
		cout << temp[i].name << "\t" << temp[i].num << "\t" << temp[i].score << "\n";
	}
	fclose(in);
	
	return 0;
}