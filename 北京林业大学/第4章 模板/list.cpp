#include <iostream>
using namespace std;

template <class T>
class List{
private:
	T data;
	List * next;
	static List * tail;      //ָ�����һ�����
	static List * head;      //ָ��ͷ���
public:
	List() :next(NULL)                  //����ͷ���
	{
		head = tail = this;
	}
	List(T newnode) :data(newnode), next(NULL)    //�����½��
	{}
	void append(T node);               //��������ӽ��
	bool insert(T node, T posnode);   //�ڽ��posnode��һ�γ��ֵĺ�������½��, ����ɹ�����true������false
	void deleteNode(T node);          //ɾ�����,ע������ж����ͬ�Ľ����Ҫɾ��
	void delList();                   //ɾ����������
	void dispList();                  //��ʾ����
};

template <class T>
List<T> * List<T>::tail = NULL;
template <class T>
List<T> * List<T>::head = NULL;

template <class T>
void List<T>::append(T node)
{
	tail->next = new List(node);
	tail = tail->next;
}

template <class T>
bool List<T>::insert(T node, T posnode)
{
	for (List * find = head->next; find != NULL; find = find->next)
		if (find->data == posnode)       //�ҵ��˲����λ��
		{
			List * temp = new List(node);
			if (find->next == NULL)         //posnode�����һ����㣬��ʱ��Ҫ�޸�tail
			{
				temp->next = NULL;
				find->next = tail = temp;
				return true;
			}
			else{                            //�������һ����㣬ֻ���м���,����Ҫ�޸�tail
				temp->next = find->next;
				find->next = temp;
				return true;
			}
		}
	return false;
}

template <class T>
void List<T>::deleteNode(T node)
{
	List * find = head->next, *pre = head;
	while (find != NULL)
	{
		if (find->data == node)
		{
			if (find->next == NULL)         //Ҫɾ���������һ����㣬��Ҫ�޸�tail
			{
				pre->next = NULL;
				tail = pre;
				delete find;
				find = NULL;
			}
			else{                      //Ҫɾ���Ĳ������һ�����
				pre->next = find->next;
				delete find;
				find = pre->next;
			}
		}
		else{                        //������Ҫɾ���Ľ��
			pre = find;
			find = find->next;
		}
	}
}

template <class T>
void List<T>::delList()
{
	List * current = head->next;
	List * temp;
	while (current != NULL)
	{
		temp = current;
		head->next = current->next;
		current = current->next;
		delete temp;
	}
	tail = head;
	head->next = NULL;
}

template <class T>
void List<T>::dispList()
{
	for (List * temp = head->next; temp != NULL; temp = temp->next)
		cout << temp->data << " ";
	cout << endl;
}

int main()
{
	List<int> list1;
	list1.append(1);
	list1.deleteNode(1);
	list1.append(2);
	list1.append(3);
	list1.append(4);
	list1.insert(10, 2);
	list1.append(5);
	list1.append(3);
	list1.append(3);
	list1.dispList();
	list1.deleteNode(3);
	list1.dispList();
	list1.delList();
	list1.dispList();

	List<char> list2;
	list2.append('A');
	list2.append('B');
	list2.append('C');
	list2.append('D');
	list2.insert('E', 'B');
	list2.insert('F', 'D');
	list2.append('G');
	list2.append('G');
	list2.append('G');
	list2.dispList();
	list2.deleteNode('G');
	list2.dispList();
	list2.delList();
	list2.dispList();

	system("pause");

	return 0;
}
