#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack<int> stk1;                    //stack<T> stk;stack采用模板类实现，默认构造，T为数据类型，如int等
	for (int i = 0; i < 5; ++i)
	{
		stk1.push(i+10);                //push(elem);入栈，向栈顶添加元素
	}
	stack<int> stk2(stk1);              //stack(const stack &stk);拷贝构造
	cout << "stk1的大小为:" << stk1.size() << endl;
	cout << "stk2的大小为:" << stk2.size() << endl;
	//打印栈顶元素并出栈
	while (!stk1.empty())                                   //empty();判断栈是否为空
	{
		cout << "stk1栈顶元素为:" << stk1.top() << endl;     //top();返回栈顶元素
		stk1.pop();                                         //pop();出栈，删除栈顶元素
	}
	cout << "stk1的大小为:" << stk1.size() << endl;          //size();返回栈的大小
	stk2 = stk1;                                            //stack& operator=(const stack& stk);重载赋值运算符
	cout << "stk2的大小为:" << stk2.size() << endl;

    return 0;
}
