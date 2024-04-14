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
	~bigNum();						//销毁
	void Show();					//遍历展示
	void generateNum();				//输入数字
	void Put(int x);				//加入
	bool GetSign();					//获取正负号

private:
	Node* front;
	Node* tail;
	bool positive;

};

bool bigNum::GetSign()
{
	return positive;
}

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
		cout<<"-";
		while(p->next)
		{
			p=p->next;
			cout<<p->data;
		}
		cout<<endl;
	}
	else
	{
		Node* p=front;
		while(p->next)
		{
			p=p->next;
			cout<<p->data;
		}
		cout<<endl;
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
			Put((int)ch-48);
			cin.get(ch);
		}
	}
	else
	{
		positive = true;
		while (ch != '\n')
		{
			Put((int)ch-48);
			cin.get(ch);
		}

	}
}


int main()
{
	bigNum num1;
	num1.generateNum();
	num1.Show();
	cout<<num1.GetSign();

	return 0;
}