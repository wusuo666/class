#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

class bigNum
{
public:
	bigNum() { front = new Node; front->next = NULL; tail = front; positive = true; }
	~bigNum();				//销毁
	void Show();				//遍历展示
	void generateNum();
	void Put(int x);				//加入

private:
	Node* front;
	Node* tail;
	bool positive;

};

bigNum::~bigNum()
{
	while (front)
	{
		Node* p = front;
		front = front->next;
		delete p;
	}
}

void bigNum::Show()
{
	if(positive==false)
	{
		Node* p=front;
		if(p->next==NULL)
		{
			cout<<"数据输入存在错误"<<endl;
			return;
		}
		cout<<"-";
		while(p->next)
		{
			p=p->next;
			cout<<p->data;
			cout<<endl;
		}
	}
}

void bigNum::Put(int x)
{
	Node* s = new Node;
	s->data = x;
	s->next = tail->next;
	tail->next = s;
	tail = tail->next;

}

void bigNum::generateNum()
{
	char ch;
	cin.get(ch);
	if (ch == '-')
	{
		positive = false;
		cin.get(ch);
		while (ch != '\n')
		{
			Put((int)ch);
			cin.get(ch);
		}
	}
	else
	{
		positive = true;
		while (ch != '\n')
		{
			Put((int)ch);
			cin.get(ch);
		}

	}
}


int main()
{
	bigNum num1;
	num1.generateNum();
	num1.Show();

	return 0;
}