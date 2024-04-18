#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

void Print(vector<int>& v)				//vector遍历
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\t";
	}
	cout << endl;
}

int main()
{
	//一、vector的构造函数
	int arr[5] = { 1,2,3,4,5 };
	vector<int> v1(arr, arr + 5);		//1、将地址arr到arr+5(取不到）的数组存进去    （前闭后开）
	cout << "v1如下" << "\t";
	Print(v1);

	vector<int> v2(3, 10);				//2、存储三个10
	cout << "v2如下" << "\t";
	Print(v2);

	vector<int> v3(v1);					//3、拷贝构造函数
	vector<int> v4 = v1;
	cout << "v3如下" << "\t";
	Print(v3);
	cout << "v4如下" << "\t";
	Print(v4);

	vector<int> v5(4);                  //4、存入4个默认值0；
	cout << "v5如下" << "\t";
	Print(v5);

	vector<int> v6{ 1,2,3,4,5,6 };		//5、使用给定值初始化
	cout << "v6如下" << "\t";
	Print(v6);

	//二、vector的赋值。
	vector<int> vecIntD;
	int iArray[] = { 0,1,2,3,4 };
	v1.assign(iArray, iArray + 5);					//1、用其他容器的迭代器作参数进行赋值
	cout << "赋值后v1如下：" << "\t";
	Print(v1);

	v2.assign(v1.begin(), v1.end());				//2、用vector的迭代器作参数进行赋值
	cout << "赋值后v2如下：" << "\t";
	Print(v2);

	v3.assign(3, 9);								//3、赋值3个9到vecIntC里面
	cout << "赋值后v3如下：" << "\t";
	Print(v3);

	v4 = v1;										//4、利用等号的重载赋值
	cout << "赋值后v4如下：" << "\t";
	Print(v4);

	v4.swap(v3);									//5、两个vector互换
	cout << "互换后v3'如下：" << "\t";
	Print(v3);
	cout << "互换后v4'如下：" << "\t";
	Print(v4);
	cout << endl;

	//三、vector的大小
	vector<int> vecInt = { 1,2,3,4 };
	cout << "vecInt如下：" << "\t";
	Print(vecInt);
	int n1 = vecInt.size();										//1、通过sizi函数访问元素个数
	cout << "vecInt中元素的个数为：" << n1 << endl;

	vector<int> vecEmpty;
	cout << "vecEmpty元素个数为：" << vecEmpty.size() << endl;
	if (vecEmpty.empty()) cout << "vecEmpty is empty" << endl;	//2、判断vector是否为空(返回bool类型)

	vecInt.resize(6);											//3、重新指定容器长度为num，若容器变长，则以默认值0填充新位置，
	cout << "(resize不指定元素)vecInt如下：" << "\t";			//若容器变短，则删除多余元素
	Print(vecInt);

	vecInt.resize(8, 3);										//4、重新指定容器长度为num，若容器变长，则以elem填充新位置，
	cout << "(resize指定元素)vecInt如下：" << "\t";				//若容器变短，则删除多余元素
	Print(vecInt);

	vecInt.resize(4);											//5、容器变短，删除多余元素
	cout << "(resize减短元素)vecInt如下：" << "\t";
	Print(vecInt);
	cout << endl;

	//四、vector元素的访问方式
	//vecInt[8];								//1、通过下标访问可能会造成程序异常，且不会反馈错误信息
	//vecInt.at(8);								//2、通过at函数访问可能会造成程序异常，但会反馈错误信息
	cout <<"利用at函数访问元素如下：" <<"\t" << vecInt.at(2) << endl;		//3、通过at函数正常访问元素
	cout << endl;

	//五、vector的插入与删除
	vecInt.push_back(10);										//1、在末尾插入一个元素(10)
	cout << "(在末尾插入元素后)vecInt如下：" << "\t";
	Print(vecInt);

	vecInt.pop_back();											//2、删除末尾元素
	cout << "(在末尾插入元素后)vecInt如下：" << "\t";
	Print(vecInt);

	vecInt.insert(vecInt.begin() + 3, 100);						//3、在指定位置插入指定元素
	cout << "(在第3个位置插入100)vecInt如下：" << "\t";			//注意：第一个参数应该为指针，而不是下标
	Print(vecInt);
	
	vecInt.insert(vecInt.begin() + 3, 3, 1000);					//4、在指定位置插入多个相同元素
	cout << "(在第3个位置插入3个100)vecInt如下：" << "\t";
	Print(vecInt);

	int b[] = { 40,50,60,70,80 };
	vecInt.insert(vecInt.begin() + 7, b + 1, b + 5);			//5、将指定区间中的元素插入到相应位置
	cout << "(在第6个位置插入指定区间内容)vecInt如下：" << "\t";
	Print(vecInt);
	cout << endl;
	
	return 0;
}
