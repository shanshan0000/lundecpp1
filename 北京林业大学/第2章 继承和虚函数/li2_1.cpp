#include <iostream>
using namespace std;

class Rectangle
{
protected:
	int lenghth;
	int width;
public:
	void set1(int l, int w)
	{
		lenghth = l;
		width = w;
	}
};

class Cuboid : public Rectangle
{
private:
	int height;
public:
	void set2(int h)
	{
		height = h;
	}

	void show()
	{
		cout<<"���ȣ�"<<lenghth<<endl;
		cout<<"��ȣ�"<<width<<endl;
		cout<<"�߶ȣ�"<<height<<endl;
	}
};

int main()
{
	Cuboid obj;
	obj.set1(20,10);
	obj.set2(5);
	obj.show();
	return 0;
}
