#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
//#include <functional>
using namespace std;

int main()
{
	typedef vector<int> int_vector;
	typedef istream_iterator<int> input;
	typedef ostream_iterator<int> output;
	typedef back_insert_iterator<int_vector> ins;
	int_vector vec;

	cout << "����һ���������Է����ֽ�����";
	copy(input(cin), input(), ins(vec));
	cout << "����ǰ��" << vec.size() << "�������ֱ�Ϊ��";
	copy(vec.begin(), vec.end(), output(cout, " "));
	cout << "\n";
	sort(vec.begin(), vec.end());
	//sort(vec.begin(), vec.end(), greater<int>());
	cout << "������" << vec.size() << "�������ֱ�Ϊ��";
	copy(vec.begin(), vec.end(), output(cout, " "));
	cout << endl;

	return 0;
}