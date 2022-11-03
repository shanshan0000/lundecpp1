#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vec1(3, 6);
	cout << "vec1�е�Ԫ�ظ�����" << vec1.size() << "\n";
	cout << "vec1�е�Ԫ��ֵ�ֱ�Ϊ��";
	for (vector<int>::size_type i = 0; i<vec1.size(); i++)
		cout << vec1[i] << ' ';
	cout << "\n\n";

	for (vector<int>::iterator it1 = vec1.begin(); it1 != vec1.end(); it1++)
		cout << *it1 << ' ';
	cout << "\n\n";

	vector<char> vec2;
	vec2.push_back('C');
	vec2.push_back('h');
	vec2.push_back('n');
	vec2.push_back('a');
	vector<char>::iterator it; //�����ַ������������ĵ���������it
	it = vec2.begin() + 2; //ָ���3��Ԫ��
	vec2.insert(it, 'i');      //��itָ���λ��ǰ����'i'
	cout << "vec2�е�Ԫ�ظ�����" << vec2.size() << "\n";
	cout << "vec2�еĵ�һ��Ԫ��ֵΪ��" << vec2.front() << "\n";
	cout << "vec2�е�Ԫ��ֵ�ֱ�Ϊ��";
	for (vector<char>::size_type i = 0; i<vec2.size(); i++)
		cout << vec2[i] << " ";
	cout << endl;

	return 0;
}

+++++++++++++++++++++++++++++++++++++

#include <string>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<string> vs;
	string temp;
	for (int i = 0; i < 5; i++){
		cin >> temp;
		vs.push_back(temp);
	}
	vector<string>::iterator it = vs.begin();
	vs.insert(it, "one");
	for (; it != vs.end(); it++)
		cout << *it << " ";
	cout << endl;
	vector<string>::iterator it1 = vs.begin(), it2 = vs.end();

	vs.insert(vs.begin(), it1, it2);

	for (it = vs.begin(); it != vs.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}