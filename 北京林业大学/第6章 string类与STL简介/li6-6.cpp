#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

//copy�����Ĳ������ǵ�����
// #include <algorithm>    
//output_iterator copy( input_iterator start, input_iterator end, output_iterator dest );
//The copy function copies the elements between start and end to dest. 
//In other words, after copy has run,   
//*dest = *start   *(dest+1) = *(start+1)   *(dest+2) = *(start+2)   ...   *(dest+N) = *(start+N)

int main()
{
	typedef vector<int> int_vector;
	typedef istream_iterator<int> input;
	typedef ostream_iterator<int> output;

	//��������������������������copy�㷨ÿ��������ĩ�˲���һ������
	typedef back_insert_iterator<int_vector> ins; 

	int_vector vec;

	cout<<"�������ɸ��������Է����ֽ�����";

	//���������ֱ�Ϊ��ʼλ�á�����λ�ú�Ŀ�ĵ�

	//ǰ������������������������ʱ����ǰһ��ָ�����������������Ŀ�ʼ����һ����ָ��"pass-the-end value"��

	//��һ���������ӿ�ʼλ��ÿ���۽�����󵽴�ڶ�����������ָ���λ��

	copy(input(cin),input(),ins(vec));

	cout<<"�����"<<vec.size()<<"�������ֱ�Ϊ��";

	//output(cout, " ")չ�������ʽ�ǣ�ostream_iterator(cout, " ")����Ч���ǲ���һ����������������ĵ���������//��λ��ָ������������ʼ����������" "��Ϊ�ָ����copy���������ͷ��β��vector�е�����"����"������豸��
//��һ������������ĵ���������ӿ�ʼλ��ÿ���۽�����󵽴�ڶ�������������ĵ�������ָ���λ�á�

	copy(vec.begin(),vec.end(),output(cout," ")); 

	cout<<endl;
	return 0;
}