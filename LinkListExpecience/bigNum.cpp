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
	bigNum(int a[], int n);
	~bigNum();				//销毁
	void Show();				//遍历展示
	void generateNum();
	void Put(int x);				//加入

private:
	Node* front;
	Node* tail;
	bool positive;

};

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


	return 0;
}