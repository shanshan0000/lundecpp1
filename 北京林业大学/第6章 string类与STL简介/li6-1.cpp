#include <iostream>
#include <string>
using namespace std;

int main()
{
	char * s = "Hello world.";
	string s1;         //Ĭ�Ϲ��캯�����մ�
	cout<<"s1 = "<<s1<<endl;
	string s2(s);       //���캯��string(const char * s)
	cout<<"s2 = "<<s2<<endl;
	string s3(s2);     //�������캯��
	cout<<"s3 = "<<s3<<endl;
	string s4(s2,1,3); 
	cout<<"s4 = "<<s4<<endl;
	string s5(s,3);
	cout<<"s5 = "<<s5<<endl;
	string s6(6,'H');
	cout<<"s6 = "<<s6<<endl;

	return 0;
}