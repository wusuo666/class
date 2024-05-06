#include<iostream>
using namespace std;

const int MAXSIZE=1024;

template <class T>
class shareStack
{
public:
    shareStack(){top1=-1,top2=MAXSIZE;}
    void pushs1(T x);
    T pops1();
    T getTops1();
    bool emptys1();
    void pushs2(T x);
    T pops2();
    T getTops2();
    bool emptys2();
private:
    T data[MAXSIZE];
    int top1;
    int top2;
};

template<class T>
void shareStack<T>::pushs1(T x)
{
    if(top1>=(top2-1))throw"上溢";
    top1++;
    data[top1]=x;
}
template<class T>
void shareStack<T>::pushs2(T x)
{
    if(top2<=(top1+1))throw"上溢";
    top2--;
    data[top2]=x;
}
template<class T>
bool shareStack<T>::emptys1()
{
    if(top1<=-1) return true;
    else return false;
}
template<class T>
bool shareStack<T>::emptys2()
{
    if(top2>=MAXSIZE) return true;
    else return false;
}
template<class T>
T shareStack<T>::getTops1()
{
    if(emptys1())throw"下溢";
    return data[top1];
}
template<class T>
T shareStack<T>::getTops2()
{
    if(emptys2())throw"下溢";
    return data[top2];
}
template<class T>
T shareStack<T>::pops1()
{
    if(emptys1())throw"下溢";
    top1--;
    return data[top1+1];
}
template<class T>
T shareStack<T>::pops2()
{
    if(emptys2())throw"下溢";
    top2++;
    return data[top2-1];
}

int main()
{
    shareStack<int> shareExp;
    for(int i=0;i<5;i++)        //调用两个push函数来初始化
    {
        shareExp.pushs1(i);
    }
    for(int i=5;i<10;i++)
    {
        shareExp.pushs2(i);
    }

    cout<<"s1是否为空:"<<shareExp.emptys1()<<endl;        //调用empty函数
    cout<<"s2是否为空:"<<shareExp.emptys2()<<endl;

    cout<<"s1栈顶元素为:"<<shareExp.getTops1()<<endl;       //调用getTop函数
    cout<<"s2栈顶元素为:"<<shareExp.getTops2()<<endl;

    cout<<"s1依次出栈:"<<"\t";                             //调用pop函数
    for(int i=0;i<5;i++)
    {
        cout<<shareExp.pops1()<<"\t";
    }
    cout<<endl;
    cout<<"s2依次出栈:"<<"\t";
    for(int i=0;i<5;i++)
    {
        cout<<shareExp.pops2()<<"\t";
    }
    cout<<endl;

    cout<<"s1是否为空:"<<shareExp.emptys1()<<endl;        //调用empty函数
    cout<<"s2是否为空:"<<shareExp.emptys2()<<endl;

    return 0;
}