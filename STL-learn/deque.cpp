#include<iostream>
#include<deque>
#include<iterator>
using namespace std;

void print(deque<int>& d)
{
    deque<int>::iterator it;
    it=d.begin();
    while(it!=d.end())
    {
        cout<<*it<<"\t";
        it++;
    }
    cout<<endl;
}

int main()
{
    //一、构造函数
    cout<<"一、构造函数。"<<endl;
	deque<int> d1;                           //1、deque<T> d;使用模板类，默认构造函数
	for (int i = 0; i < 5; i++)
	{
		d1.push_back(i);
	}
    cout << "打印d1: ";
	print(d1);

	deque<int> d2(d1.begin(), d1.end());     //2、deque(begin(),end());利用迭代器将所有元素拷贝给本身
	cout << "打印d2: ";
	print(d2);

	deque<int> d3(5, 6);                     //3、deque(n,elem);将n个elem拷贝给本身
	cout << "打印d3: ";
	print(d3);

	deque<int> d4(d3);                       //4、deque(const deque& d);拷贝构造函数
	cout << "打印d4: ";
	print(d4);

    deque<int> d5(5);                        //5、deque(n);将n个默认值0赋给本身
    cout << "打印d5: ";
	print(d5);
    
    deque<int> d6{1,2,3,4,5,6};              //6、deque{1,2,...,n};使用给定值初始化
    cout << "打印d6: ";
	print(d6);

    //二、deque的赋值操作
    cout<<"二、deque的赋值操作"<<endl;
    deque<int> d21, d22, d23, d24;
	for (int i = 0; i < 5; i++)
	{
		d21.push_back(i);
	}
	d22=d21;                                 //deque& operator=(const deque &d);重载赋值运算符
	cout << "重载赋值运算符: ";
	print(d22);
    
	d23.assign(d21.begin(), d21.end());      //assign(begin(),end());将全部数据拷贝给本身
	cout << "将全部数据拷贝给本身: ";
	print(d23);
	
    d24.assign(5, 9);                        //assign(n,elem);将n个elem赋值给本身
	cout << "将n个elem赋值给本身: ";
	print(d24);

    d24.swap(d23);                           //swap(d);将两个deque互换
    cout<<"互换后d24如下:"<<"\t";
    print(d24);
    cout<<"互换后d23如下:"<<"\t";
    print(d23);

    //三、deque的大小操作
    cout<<"三、deque的大小操作"<<endl;
    deque<int> d;
	for (int i = 0; i < 5; i++)
	{
		d.push_back(i);
	}
	if (!d.empty())                                     //empty();判断容器是否为空，是返回1，否返回0
	{
		cout << "容器的大小为：" << d.size() << endl;    //size();返回容器中元素个数
		cout << "打印d: ";
		print(d);
	}
	//重新指定容器长度
	d.resize(10,5);                                     //resize(num);重新指定容器长度为num,若容器变长，以默认值0填充新位置;
	cout << "重新指定容器长度为num: ";                    //若容器变短，末尾超出容器长度的部分被删除
	print(d);

	d.resize(8);                                        //重新指定容器长度为num,若容器变长，以elem填充新位置
	cout << "重新指定容器长度为num: ";                    //若容器变短，末尾超出容器长度的部分被删除
	print(d);

    //deque与vector不同，没有capacity函数。

    //四、deque的插入和删除
    cout<<"四、deque的插入和删除"<<endl;
    deque<int> d44;
	for (int i = 0; i < 5; i++)
	{
		d44.push_back(i + 5);               //push_back(elem);在容器尾部插入一个数据
		d44.push_front(5 - i);              //push_front(elem);在容器头部插入一个数据
	}
	cout << "打印d44: ";
	print(d44);

	d44.pop_back();                         //pop_back();删除容器最后一个数据
    cout << "删除容器最后一个数据: ";
	print(d44);

	d44.pop_front();                        //pop_front();删除容器第一个数据
	cout << "删除容器第一个数据: ";
	print(d44);

    d44.insert(d44.begin(), 2);             //insert(pos,elem);在迭代器pos位置插入一个elem数据，返回新数据位置
	cout << "在迭代器pos位置插入一个elem数据: "<<"\t";
	print(d44);

	d44.insert(d44.begin(), 5, 3);          //insert(pos,n,elem);在迭代器pos位置插入n个elem数据，无返回值
	cout << "在迭代器pos位置插入n个elem数据: "<<"\t";
	print(d44);                             //insert(pos,begin,end);在迭代器pos位置插入[begin,end)区间的数据，无返回值

	d44.erase(d44.begin());                 //erase(pos);删除迭代器pos位置的数据，返回下一个数据位置
	cout << "在迭代器pos位置插入[begin,end)区间的数据: "<<"\t";
	print(d44);

	d44.clear();                            //clear();清空所有数据
	cout << "清空所有数据: ";                //上下两者可产生相同效果
	print(d44);                             //erase(begin,end);删除[begin,end)区间的数据，返回下一个数据的位置

    //五、deque的数据存取
    cout<<"五、deque的数据存取"<<endl;
    deque<int> de;
	for (int i = 0; i < 5; i++)
	{
		de.push_back(i);
	}
	for (int i = 0; i < de.size(); i++)
	{
		cout << de.at(i);                    //at(int idx);返回索引idx所指的数据
		cout << de[i] << " ";                //operator[];重载[]
	}
	cout << endl;
	cout << "容器de的第一个元素是:" << de.front() << endl;       //front();返回容器中第一个数据元素
	cout << "容器de的最后一个元素是:" << de.back() << endl;      //back();返回容器中最后一个数据元素

    return 0;
}