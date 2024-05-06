#include<iostream>
using namespace std;

bool vis[30]={false};   //列的标记数组，初始为false
bool lr[30]={false};    //左对角线的标记数组，初始为false
bool fr[30]={false};    //右对角线的标记数组，初始为false
const int len=8;
int cnt=0;
int data1[70]={0};
int n=0;

bool judgeChess(int x,int y)
{
    if(vis[x]||lr[y-x+len]||fr[x+y]) return false;
    else return true;
}

void recursion_eight_empress(int y)      //递归方案
{
    cout<<n++<<"\t"<<y<<"\t";
    if(y==8)
    {
        cout<<"第"<<++cnt<<"种摆法如下:"<<endl;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                cout<<data1[8*i+j]<<"\t";
            }
            cout<<endl;
            return;
        }
    }
    for(int i=0;i<len;i++)
    {
        if(!judgeChess(i,y)) continue;
        vis[i]=true;
        lr[y-i+len]=true;
        fr[y+i]=true;
        data1[8*y+i]=true;
        cout<<i<<"\t"<<y<<endl;
        recursion_eight_empress(y+1);
        vis[i]=false;
        lr[y-i+len]=false;
        fr[y+1];
        data1[8*y+i]=false;

    }
    return;
}

int main()
{
    recursion_eight_empress(1);

    return 0;
}