#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

int input(stringstream& ss,stack<char>& sc,stack<int>& si)
{
    if(ss.str().empty())cout<<"输入表达式不合法";
    int res=0;
    char str;
    ss>>str;
    while(str)
    {
        //判断是否为括号(还未写)
        
        vector<int> tempNum;
        while(str>='0'&&str<='9')
        {
            tempNum.push_back((int)str-48);
            ss>>str;
        }
        int num=0;
        for(int i=0;i<tempNum.size();i++)
        {
            // num+=pow(10,tempNum.size()-i-1) * tempNum.pop_back();
        }
        
    }

}

int main()
{
    stringstream ss; // 创建一个字符串流

    // 向字符串流中插入数据
    ss << "Hello, world!";

    // 获取字符串流的长度
    std::size_t length = ss.str().length(); // 或者使用 ss.str().size()

    std::cout << "字符串流的长度为：" << length << std::endl;
    cout<<ss.str()<<endl;

    return 0;
}