#include<iostream>
#include<stack>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

class bigNum
{
public:
	bigNum(){front = new Node; front->next = NULL; tail = front; positive = true;}
	bigNum(bool sign) { front = new Node; front->next = NULL; tail = front; positive = sign; }
	~bigNum();						//销毁
	void Show();					//遍历展示
	void generateNum();				//输入数字
	void Put(int x);				//加入头
	void PutTail(int x);			//加入尾
	bool GetSign();					//获取正负号
	int GetLength();				//获取长度
	int GetData();					//获取数值
	Node* Get(int i);		//按位查找

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

int bigNum::GetLength()
{
	Node* p = front;
	int i = 0;
	while (p->next)
	{
		p = p->next;
		i++;
	}
	return i;
}

Node* bigNum::Get(int i)
{
	Node* p = front;
	for (int j = 0; j < i; j++)
	{
		p = p->next;
	}
	return p;
}

void bigNum::Show()
{
	if(positive==false)
	{
		stack<int> myStack;
		Node* p=front;
		cout<<"-";
		while(p->next)
		{
			p=p->next;
			myStack.push(p->data);
		}
		while(!myStack.empty())
		{
			cout<<myStack.top();
			myStack.pop();
		}
		cout<<endl;
	}
	else
	{
		stack<int> myStack;
		Node* p=front;
		while(p->next)
		{
			p=p->next;
			myStack.push(p->data);
		}
		while(!myStack.empty())
		{
			cout<<myStack.top();
			myStack.pop();
		}
		cout<<endl;
	}
}

void bigNum::Put(int x)
{
	Node* s = new Node;
	s->data = x;
	s->next = front->next;
	front->next=s;
	if(tail->next!=NULL)tail=tail->next;
}

void bigNum::PutTail(int x)
{
	Node* s=new Node;
	s->data=x;
	s->next=tail->next;
	tail->next=s;
	tail=s;
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

void bigPlus(bigNum* num1,bigNum* num2,bigNum* res)
{
	if(num1->GetSign()==num2->GetSign())			//符号相同条件
	{
		if(num1->GetLength()>=num2->GetLength())
		{
			int judge=0;
			for(int i=1;i<=num2->GetLength();i++)	
			{
				if((num1->Get(i)->data+num2->Get(i)->data)>=10)		//要进位
				{
					res->PutTail(num1->Get(i)->data+num2->Get(i)->data+judge-10);
					// 调试
					// int a=num1->Get(i)->data+num2->Get(i)->data+judge;
					// cout<<a<<endl;
					judge=1;
				}
				else												//不用进位
				{
					res->PutTail(num1->Get(i)->data+num2->Get(i)->data+judge);
					//调试
					// int a=num1->Get(i)->data+num2->Get(i)->data+judge;
					// cout<<a<<endl;
					// cout<<res->Get(i)->data;
					judge=0;
				}
			}
			for(int i=num2->GetLength()+1;i<=num1->GetLength();i++)		//补全多余数
			{
				res->PutTail(num1->Get(i)->data+judge);
				// 调试
				// int b=num1->Get(i)->data+judge;
				// cout<<b<<endl;
				// cout<<res->Get(i)->data;
				judge=0;
			}
		}
		else
		{
			int judge=0;
			for(int i=1;i<=num1->GetLength();i++)
			{
				if((num1->Get(i)->data+num2->Get(i)->data)>=10)
				{
					res->PutTail(num1->Get(i)->data+num2->Get(i)->data+judge);
					int a=num1->Get(i)->data+num2->Get(i)->data+judge;
					cout<<a;
					judge=1;
				}
				else
				{
					res->PutTail(num1->Get(i)->data+num2->Get(i)->data+judge);
					int a=num1->Get(i)->data+num2->Get(i)->data+judge;
					cout<<a;
					judge=0;
				}
			}
			for(int i=num1->GetLength()+1;i<=num2->GetLength();i++)
			{
				res->PutTail(num2->Get(i)->data+judge);
				judge=0;
			}
		}
	}
}


int main()
{
	bigNum num01;
	bigNum num02;
	cout<<"请输入Num1数值:";
	num01.generateNum();
	cout<<"请输入Num2数值:";
	num02.generateNum();
	cout<<"Num1+Num2=";
	bigNum res;
	bigPlus(&num01,&num02,&res);
	res.Show();


	return 0;
}