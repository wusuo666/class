#include <iostream>
#include <vector>
using namespace std;



int main()
{
	//vector与iterator
	vector<int> vecIntA;
	int Array[] = { 1,2,3,4,5 };

	vector<int> vecIntB;
	vecIntA.assign(Array, Array + 5);

	cout << vecIntA[3] << endl;
	cout << vecIntA.at(3) << endl;						//使用at函数访问更安全

	/*vecIntA[6] = 100;									//直接这样赋值可能会导致其他容器的元素被改变。（访问越界）
	cout << vecIntA[6] << endl;*/

	//引入迭代器后，可以不再使用.at和下标访问容器中的元素

	//迭代器相关函数
	//构造一个迭代器对象
	vector<int>::iterator it_b,it_e,it;							//vector的迭代器属于“随机访问迭代器”：迭代器一次可以移动多个位置
	it_b = vecIntA.begin();										//指向第一个元素
	cout << "begin()指向第一个元素:" << *it_b;
	cout << endl;
	it_e = vecIntA.end();										//指向末尾元素的下一个

	cout << "利用迭代器遍历:";
	for (it = vecIntA.begin(); it != vecIntA.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;




	return 0;
}