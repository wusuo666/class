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
	Node* Get(int i);				//按位查找
	void ChangeSign();				//变号
	void DeleteZero();				//删除零

private:
	Node* front;
	Node* tail;
	bool positive;

};

void bigNum::DeleteZero()
{
	while(tail->data==0)
	{
		Node* p=front;
		while(p->next!=tail)
		{
			p=p->next;
		}
		tail=p;
		p=p->next;
		tail->next=p->next;
		delete p;
	}
}

void bigNum::ChangeSign()
{
	positive=!positive;
}

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
	while(tail->next!=NULL)
	{
		tail=tail->next;
	}
	DeleteZero();
}

int compareBigNumWithOutSign(bigNum* num1,bigNum* num2)			//不考虑符号的比大小
{
	if(num1->GetLength()>num2->GetLength())return 1;
	else if(num1->GetLength()<num2->GetLength())return -1;
	else
	{
		stack<int> temp1,temp2;
		for(int i=1;i<=num1->GetLength();i++)
		{
			temp1.push(num1->Get(i)->data);
			temp2.push(num2->Get(i)->data);
			
		}
		for(int i=1;i<=num1->GetLength();i++)
		{
			if(temp1.top()>temp2.top()) return 1;
			else if(temp1.top()<temp2.top())return -1;
			temp1.pop();
			temp2.pop();
		}
		return 0;
	}
}

void bigPlus(bigNum* num1,bigNum* num2,bigNum* res)				//大整数的加法
{
	if(num1->GetSign()==num2->GetSign())			//符号相同条件
	{
		if(num1->GetLength()>=num2->GetLength())
		{
			int judge=0;
			for(int i=1;i<=num2->GetLength();i++)	
			{
				if((num1->Get(i)->data+num2->Get(i)->data+judge)>=10)		//要进位
				{
					res->PutTail(num1->Get(i)->data+num2->Get(i)->data+judge-10);
					
					// int a=num1->Get(i)->data+num2->Get(i)->data+judge;
					// cout<<a<<endl;
					judge=1;
				}
				else												//不用进位
				{
					res->PutTail(num1->Get(i)->data+num2->Get(i)->data+judge);
					
					// int a=num1->Get(i)->data+num2->Get(i)->data+judge;
					// cout<<a<<endl;
					// cout<<res->Get(i)->data;
					judge=0;
				}
			}
			for(int i=num2->GetLength()+1;i<=num1->GetLength();i++)		//补全多余数
			{
				res->PutTail(num1->Get(i)->data+judge);
				
				// int b=num1->Get(i)->data+judge;
				// cout<<b<<endl;
				// cout<<res->Get(i)->data;
				judge=0;
			}
			if(judge==1)res->PutTail(1);
		}
		else
		{
			int judge=0;
			for(int i=1;i<=num1->GetLength();i++)
			{
				if((num1->Get(i)->data+num2->Get(i)->data+judge)>=10)
				{
					res->PutTail(num1->Get(i)->data+num2->Get(i)->data+judge-10);
					// int a=num1->Get(i)->data+num2->Get(i)->data+judge;
					// cout<<a<<endl;
					judge=1;
				}
				else
				{
					res->PutTail(num1->Get(i)->data+num2->Get(i)->data+judge);
					// int a=num1->Get(i)->data+num2->Get(i)->data+judge;
					// cout<<a<<endl;
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
	else										//符号不相同
	{
		if(num1->GetSign()==true)				//num1为正
		{
			if(compareBigNumWithOutSign(num1,num2)==1)		//应为为比较num1和num2的大小
			{
				int judge=0;
				for(int i=1;i<=num2->GetLength();i++)
				{
					if((num1->Get(i)->data-num2->Get(i)->data+judge)<0)		//需要借位
					{
						res->PutTail(num1->Get(i)->data-num2->Get(i)->data+judge+10);
						judge=-1;
					}
					else											//不用借位
					{
						res->PutTail(num1->Get(i)->data-num2->Get(i)->data+judge);
						judge=0;
					}
				}
				for(int i=num2->GetLength()+1;i<=num1->GetLength();i++)		//补全
				{
					res->PutTail(num1->Get(i)->data+judge);
					judge=0;
				}
			}
			else if(compareBigNumWithOutSign(num1,num2)==0)				//相等
			{
				res->Put(0);
			}
			else														//num1小于num2
			{
				res->ChangeSign();
				int judge=0;
				for(int i=1;i<=num1->GetLength();i++)
				{
					if((num2->Get(i)->data-num1->Get(i)->data+judge)<0)		//需要借位
					{
						res->PutTail(num2->Get(i)->data-num1->Get(i)->data+judge+10);
						// cout<<num2->Get(i)->data-num1->Get(i)->data+judge+10<<endl;
						judge=-1;
					}
					else											//不用借位
					{
						res->PutTail(num2->Get(i)->data-num1->Get(i)->data+judge);
						// cout<<num2->Get(i)->data-num1->Get(i)->data+judge<<endl;
						judge=0;
					}
				}
				for(int i=num1->GetLength()+1;i<=num2->GetLength();i++)		//补全
				{
					res->PutTail(num2->Get(i)->data+judge);
					// cout<<num2->Get(i)->data+judge<<endl;
					judge=0;
				}
			}
		}
		else												//num1为负
		{
			res->ChangeSign();
			if(compareBigNumWithOutSign(num1,num2)==1)		//应为为比较num1和num2的大小
			{
				int judge=0;
				for(int i=1;i<=num2->GetLength();i++)
				{
					if((num1->Get(i)->data-num2->Get(i)->data+judge)<0)		//需要借位
					{
						res->PutTail(num1->Get(i)->data-num2->Get(i)->data+judge+10);
						judge=-1;
					}
					else											//不用借位
					{
						res->PutTail(num1->Get(i)->data-num2->Get(i)->data+judge);
						judge=0;
					}
				}
				for(int i=num2->GetLength()+1;i<=num1->GetLength();i++)		//补全
				{
					res->PutTail(num1->Get(i)->data+judge);
					judge=0;
				}
			}
			else if(compareBigNumWithOutSign(num1,num2)==0)				//相等
			{
				res->Put(0);
			}
			else														//num1小于num2
			{
				res->ChangeSign();
				int judge=0;
				for(int i=1;i<=num1->GetLength();i++)
				{
					if((num2->Get(i)->data-num1->Get(i)->data+judge)<0)		//需要借位
					{
						res->PutTail(num2->Get(i)->data-num1->Get(i)->data+judge+10);
						judge=-1;
					}
					else											//不用借位
					{
						res->PutTail(num2->Get(i)->data-num1->Get(i)->data+judge);
						judge=0;
					}
				}
				for(int i=num1->GetLength()+1;i<=num2->GetLength();i++)		//补全
				{
					res->PutTail(num2->Get(i)->data+judge);
					judge=0;
				}
			}
		}
	}
	res->DeleteZero();
}

void bigMinus(bigNum* num1,bigNum* num2,bigNum* res)			//大整数的减法
{
	num2->ChangeSign();
	bigPlus(num1,num2,res);
	num2->ChangeSign();
	res->DeleteZero();
}

int main()
{
	while(true)
	{
		cout<<"*要运行加法请输入1\n*要运行减法请输入2\n*要退出请输入0\n请输入:";
		char operate;
		cin.get(operate);
		cin.ignore(100,'\n');
		cout<<endl;
		if(operate=='1')
		{
			bigNum num01;
			bigNum num02;
			cout<<"请输入Num1数值:";
			num01.generateNum();
			cout<<"请输入Num2数值:";
			num02.generateNum();
			cout<<"Num1+Num2=";
			bigNum resPlus;
			bigPlus(&num01,&num02,&resPlus);
			resPlus.Show();
			cout<<endl;
		}
		else if(operate=='2')
		{
			bigNum num01;
			bigNum num02;
			cout<<"请输入Num1数值:";
			num01.generateNum();
			cout<<"请输入Num2数值:";
			num02.generateNum();
			cout<<"Num1-Num2=";
			bigNum resMinus;
			bigMinus(&num01,&num02,&resMinus);
			resMinus.Show();
			cout<<endl;
		}
		else if(operate=='0')return 0;
		else cout<<"请输入3个选项其中的一个"<<endl;
	}
	// bigNum num01;
	// bigNum num02;
	// cout<<"请输入Num1数值:";
	// num01.generateNum();
	// cout<<"请输入Num2数值:";
	// num02.generateNum();
	// cout<<"Num1-Num2=";
	// bigNum resMinus;
	// bigMinus(&num01,&num02,&resMinus);
	// resMinus.Show();
	// cout<<endl;
	// cout<<"num1和num2比大小"<<compareBigNumWithOutSign(&num01,&num02);
}