#include <iostream>
using namespace std;

template <typename T>
T & max(T & a,T & b)
{
	return a>b ? a : b;
}

int main()
{
	int i1 = 30, i2 = 50;
	double d1 = 3.33, d2 = 4.44;
	char c1 = 'A', c2 = 'B';
	cout<<"较大的整数为："<<max(i1,i2)<<"\n";
	cout<<"较大的浮点数为："<<max(d1,d2)<<"\n";
	cout<<"较大的字符为："<<max(c1,c2)<<endl;
	return 0;
}


++++++++++++++++++++++++

#include<iostream>
#include<string>
using namespace std;

template<typename T>
T Max(const T & t1, const T & t2){
	return t1>t2 ? t1 : t2;
}

int main(){
	cout<<Max(3,5)<<endl;
	
	string s1("abc"),s2("def");
	cout<<Max(s1,s2)<<endl;
	
//	cout<<Max(3,5.0)<<endl;   //error
		
	return 0;
}
