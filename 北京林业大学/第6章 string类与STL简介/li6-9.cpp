#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> vec(10);
	typedef ostream_iterator<string> output;
	cout << "�������ɸ��ַ�������-1����:";
	int i;
	for (i = 0; i< (int)vec.size(); i++)
	{
		cin >> vec[i];
		if (vec[i] == "-1")
			break;
	}
	cout << "�����" << i << "���ַ����ֱ�Ϊ��";
	copy(vec.begin(), vec.begin() + i, output(cout, " "));
	cout << "\n";
	string str;
	cout << "����Ҫ���ҵ��ַ���";
	cin >> str;
	vector<string>::iterator it;
	it = find(vec.begin(), vec.begin() + i, str);
	if (it != vec.end())
		cout << *it << "�ַ�������" <<endl;
	else
		cout << "���ַ���������" << endl;

	return 0;
}