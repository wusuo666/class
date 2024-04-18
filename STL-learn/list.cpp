#include<iostream>
#include<list>
using namespace std;

void print(list<int>& l)
{
    list<int>::iterator it;
    it=l.begin();
    while(it!=l.end())
    {
        cout<<*it<<"\t";
        it++;
    }
    cout<<endl;
}

main()
{
    //一、构造函数          
    list<int> listCreat1;                //list<T> lst;1、默认构造，list采用模板类实现
    for (int i = 1; i < 10; ++i)
	{
		listCreat1.push_back(i);
	}
    cout<<"listCreat1如下:"<<"\t";
    print(listCreat1);

    int a[]={1,2,3,4,5};
    list<int> listCreat2(a,a+5);         //2、list(begin,end);构造函数，利用迭代器实现区间赋值
    cout<<"listCreat2如下:"<<"\t";
    print(listCreat2);

    list<int> listCreat3(3,10);          //3、list(n,elem);构造函数，将n个elem赋值给本身
    cout<<"listCreat3如下:"<<"\t";
    print(listCreat3);

    list<int> listCreat4(listCreat3);    //4、list(const list &lst);拷贝构造
    cout<<"listCreat4如下:"<<"\t";
    print(listCreat4);

    list<int> listCreat5(4);             //5、list(n);将n个默认值0赋给本身
    cout<<"listCreat5如下:"<<"\t";
    print(listCreat5);

    list<int> listCreat6{1,2,3,4,5,6};   //6、list{1,2,...,n};使用给定值初始化
    cout<<"listCreat6如下:"<<"\t";
    print(listCreat6);

    //二、list的赋值与交换
    list<int> lst;
    lst=listCreat1;                     //1、重载等号赋值
    cout<<"1、lst如下:"<<"\t";
    print(lst);

    lst.assign(listCreat2.begin(), listCreat2.end()); //2、区间赋值
	cout<<"2、lst如下:"<<"\t";
    print(lst);

    lst.assign(9, 1);                     //3、将9个1赋值给本身
	cout<<"3、lst如下:"<<"\t";
    print(lst);

    lst.swap(listCreat2);                   //4、将两个list互换
    cout<<"互换后lst如下:"<<"\t";
    print(lst);
    cout<<"互换后listCreat2如下:"<<"\t";
    print(listCreat2);

    //三、listd的大小操作
    list<int> lst1;
	for (int i = 1; i < 10; ++i)
	{
		lst1.push_back(i);
	}
    cout<<"lst1如下:";
	print(lst1);

	if (!lst1.empty())                                      //1、容器若不为空
	{
		cout << "list容器的大小为:" << lst1.size() << endl;
	}
	
	cout << "重新指定长度，使容器变长:" << endl;
	lst1.resize(15);                                        //2、等价于lst1.resize(15,0);
	print(lst1);                                            //重新指定容器长度,若变长，变长的部分赋值为0,若变短，超出容器长度的元素被删除

	cout << "重新指定长度，使容器变短:" << endl;              
	lst1.resize(5);                                         //重新指定容器长度,若变长，变长的部分赋值为elem,若变短，超出容器长度的元素被删除
	print(lst1);

    //四、list的插入与删除
    cout<<endl<<"四、list插入与删除"<<endl;
    list<int> lst2;
	for (int i = 1; i < 6; ++i)
	{
		lst2.push_back(i+5);            //push_back(elem);在容器尾部插入一个元素
		lst2.push_front(6 - i);         //push_front(elem);在容器头部插入一个元素
	}
    cout<<"lst2如下:"<<"\t";
	print(lst2);

	lst2.pop_back();                    //pop_back();在容器尾部删除一个元素
    cout<<"删除尾部后lst2如下:"<<"\t";
    print(lst2);
	lst2.pop_front();                   //pop_front();在容器头部删除一个元素
    cout<<"删除尾部后lst2如下:"<<"\t";
    print(lst2);

	list<int> lst3;                                    //insert(pos,elem);在迭代器pos处插入一个元素elem,返回新数据的位置
	lst3.insert(lst3.begin(),lst2.begin(), lst2.end());//insert(pos,begin,end);在lst3头部插入lst1的全部数据
    cout<<"在lst3头部插入lst2的全部数据后lst2如下:"<<"\t";
    print(lst3);
	lst3.insert(lst3.end(), 5, 10);                    //insert(pos,n,elem);在lst3尾部插入5个10
    cout<<"在lst3尾部插入5个10后lst3如下:"<<"\t";
	print(lst3);

	lst3.remove(10);                                    //remove(elem); 删除lst3中等于elem的元素
    cout<<"删除lst3中等于10的元素后lst3如下:"<<"\t";
	print(lst3);

	lst3.erase(lst3.begin(), lst3.end());   //等价于lst2.clear();
	cout<<"清空lst3后的lst3如下:"<<"\t";     //erase(pos);删除迭代器pos处的数据,返回下一个数据的位置
    print(lst3);                            //erase(begin,end);删除[begin,end)区间的数据,返回下一个数据的位置

    //五、list的数据
    cout<<endl<<"五、list的数据"<<endl;
    cout << "lst1中第一个元素是:" << lst1.front() << endl;
	cout << "lst1中最后一个元素是:" << lst1.back() << endl;

    //六、list的反转与排序
    cout<<endl<<"六、list的反转与排序"<<endl;
	list<int> lst4;
	lst4.push_back(5);
	lst4.push_back(1);
	lst4.push_back(7);
	lst4.push_back(3);
	lst4.push_back(6);
    cout<<"lst4如下:"<<"\t";
	print(lst4);

	cout << "反转后:" << "\t";                 //反转
	lst4.reverse();
	print(lst4);
	//排序
	//sort(lst1.begin(),lst1.end())//错误
	//所有不支持随机访问迭代器的容器，不能使用标准算法
	//但不支持随机访问迭代器的容器，内部会提供一些算法来弥补
	lst4.sort();            //list容器内部的排序算法
    cout<<"排序后:"<<"\t";
	print(lst4);

    return 0;
}