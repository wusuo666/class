#include<iostream>
#include<queue>
using namespace std;

class Person
{
public:
	string m_name;
	int m_age;
	Person(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
};

int main()
{
	Person p1("张三", 35);
	Person p2("李四", 28);
	Person p3("王五", 30);
	Person p4("赵六", 40);
	queue<Person> que1;                  //queue<T> que;queue采用模板类实现，默认构造函数
	
    que1.push(p1);                       //push(elem);入队——往队尾添加元素
	que1.push(p2);

    queue<Person> que2(que1);            //queue(const queue& que);拷贝构造
    cout << "que2的大小为：" << que2.size() << endl;

	que1.push(p3);
	que1.push(p4);
    
    que2=que1;                           //queue& operator=(const queue& que);重载赋值运算符
    cout << "que2的大小为：" << que2.size() << endl;
	cout << "que1的大小为：" << que1.size() << endl;
	
    while (!que1.empty())                                   //empty();判断队列是否为空
	{
		cout << "que1队头元素为：" << que1.front().m_name    //front();返回队头元素
			 << que1.front().m_age << "岁" << endl;
		cout << "que1队尾元素为：" << que1.back().m_name     //back();返回队尾元素
			 << que1.back().m_age << "岁" << endl;
		que1.pop();                                         //pop();出队——从队头删除元素
	}
	
    cout << "que1的大小为：" << que1.size() << endl;         //size();返回队列大小
    return 0;
}
