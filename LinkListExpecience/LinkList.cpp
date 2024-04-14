#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<class T>
struct Node
{
	T data;
	struct Node<T>* next;
};


template<class T>
class LinkList
{
public:
	LinkList() { front = new Node<T>; front->next = NULL; tail = front; }
	LinkList(T a[], int n);
	~LinkList();				//销毁
	void Insert(int i,T x);		//插入
	T Delete(int i);			//删除
	int Locate(T x);			//按值查找
	Node<T>* Get(int i);		//按位查找
	int Getlength();			//获取长度
	void Show();				//遍历展示
	void Put(T x);				//加入

private:
	Node<T>* front;
	Node<T>* tail;

};

template<class T>
void LinkList<T>::Put(T x)
{
	Node<T>* s = new Node<T>;
	s->data = x;
	s->next = tail->next;
	tail->next = s;
	tail = tail->next;

}

template<class T>
void LinkList<T>::Insert(int i, T x)
{
	Node<T>* p = front;
	if (i != 1)p = Get(i - 1);
	if (p)
	{
		Node<T>* s = new Node<T>;
		s->data = x;
		s->next = p->next;
		p->next = s;
	}
	else throw"插入位置错误\n";
}

template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	//以下为头插法
	/*front = new Node<T>;
	front->next = NULL;
	for (int i = n-1; i >= 0; i--)
	{
		Node<T>* s = new Node<T>;
		s->data = a[i];
		s->next = front->next;
		front->next = s;
	}*/
	
	//以下为尾插法
	front = new Node<T>;
	front->next = NULL;
	Node<T>* r = front;
	for (int i = 0; i < n; i++)
	{
		Node<T>* s = new Node<T>;
		s->data = a[i];
		s->next = r->next;
		r->next = s;
		r = r->next;
	}
	tail = r;
}

template<class T>
LinkList<T>::~LinkList()
{
	while (front)
	{
		Node<T>* p = front;
		front = front->next;
		delete p;
	}

	// Node<T>* p = front;
	// while (p)
	// {
	// 	front = p;
	// 	p = p->next;
	// 	delete front;
	// }

}

template<class T>
T LinkList<T>::Delete(int i)
{
	Node<T>* p = front;
	for (int j = 1; j < i; j++)
	{
		if (p->next == NULL)throw "删除位置异常\n";
		p = p->next;
	}
	Node<T>* q = p->next;
	p->next = q->next;
	T x = q->data;
	delete q;
	return x;
}

template<class T>
int LinkList<T>::Locate(T x)
{
	Node<T>* p = front;
	int i = 0;
	while (p)
	{
		if (p->data == x)return i;
		p = p->next;
		i++;
	}
	cout << "不存在该值" << endl;
	return -1;
}

template<class T>
Node<T>* LinkList<T>::Get(int i)
{
	Node<T>* p = front;
	for (int j = 0; j < i; j++)
	{
		if (p == NULL)throw ("删除位置异常\n");
		p = p->next;
	}
	return p;
}

template<class T>
int LinkList<T>::Getlength()
{
	Node<T>* p = front;
	int i = 0;
	while (p->next)
	{
		p = p->next;
		i++;
	}
	return i;
}

template<class T>
void LinkList<T>::Show()
{
	for (int i = 0; i < Getlength(); i++)
	{
		cout << Get(i + 1)->data << "\t";
	}
	cout << endl;
	return;
}


int main()
{
	int a[] = { 1,2,3,4,5,6 };
	LinkList<int> myList(a, 6);
	cout << "链表长度此时为：" << myList.Getlength() << endl << "链表如下：";
	myList.Show();
	myList.Insert(2, 7);
	cout << "在第2个位置插入6后，链表长度此时为: " << myList.Getlength() << endl << "链表如下：";
	myList.Show();
	cout << "数值7在该链表的第" << myList.Locate(7) << "位" << endl;
	cout << "该链表的第5位是：" << myList.Get(5)->data << endl;
	myList.Put(10);
	myList.Show();
	myList.~LinkList();
	



	return 0;
}
