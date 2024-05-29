#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
#define MAXSIZE 1024;

struct HNode
{
    int weight;
    int parent;
    int lchild;
    int rchild;
};

struct HCode
{
    char data;
    string code;
};

class Huffman
{
private:
    HNode* HTree;                           //哈夫曼树
    HCode* HCodeTable;                       //存储编码表
    int N;                                  //叶子结点数量
public:
    Huffman(){ };
    void code(int i,string newcode);        //递归函数，对第i个结点编码
    void CreateHTree(vector<int> &a,vector<char> &name);    //创建哈夫曼树
    void CreateCodeTable();                         //创建编码表
    string Encode(char* s);                   //编码
    string Decode(char* s);                   //解码
    void PrintTree();                               //打印
    ~Huffman();
};

//打印哈夫曼树
void Huffman::PrintTree() {
    if (HTree == nullptr) {
        cout << "哈夫曼树为空!" << endl;
        return;
    }

    cout << "打印哈夫曼树:" << endl;

    queue<int> q;
    q.push(2 * N - 2);

    int cur_level_nodes = 1;
    int next_level_nodes = 0;

    while (!q.empty()) {
        int node_index = q.front();
        q.pop();
        cur_level_nodes--;

        if (HTree[node_index].lchild != -1) {
            q.push(HTree[node_index].lchild);
            next_level_nodes++;
        }
        if (HTree[node_index].rchild != -1) {
            q.push(HTree[node_index].rchild);
            next_level_nodes++;
        }

        cout << HTree[node_index].weight << " ";

        if (cur_level_nodes == 0) {
            cout << endl;
            cur_level_nodes = next_level_nodes;
            next_level_nodes = 0;
        }
    }
}

void Huffman::CreateHTree(vector<int> &a,vector<char> &name)        //创建哈夫曼树
{
    N = a.size();
    HCodeTable = new HCode[N];
    HTree = new HNode[2*N - 1];
    for(int i=0;i<N;i++)
    {
        HTree[i].weight=a[i];
        HTree[i].lchild=HTree[i].rchild=HTree[i].parent = -1;
        HCodeTable[i].data=name[i];
    }
    int x,y;
    for(int i = N;i<2*N-1;i++)
    {
        x=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[x])
            {
                x=j;
            }
        }
        a[x]=MAXSIZE;
        y=0;
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[y])
            {
                y=j;
            }
        }
        a[y]=MAXSIZE;
        // //
        // for(int i=0;i<2*N-1;i++)
        // {
        //     cout<<HTree[i].weight<<HTree[i].lchild<<" "<<HTree[i].rchild<<endl;
        // }
        // //
        // SelectMin(x,y,0,i);
        HTree[x].parent = HTree[y].parent = i;
        HTree[i].weight = HTree[x].weight + HTree[y].weight;
        HTree[i].lchild = x;
        HTree[i].rchild = y;
        HTree[i].parent = -1;
    }
}

void Huffman::code(int i,string newcode)        //递归函数，对第i个结点编码
{
    if(HTree[i].lchild == -1)
    {
        HCodeTable[i].code = newcode;
        // //
        // cout<<HCodeTable[i].data<<" "<<HCodeTable[i].code;
        // //
        return;
    }
    code(HTree[i].lchild,newcode+"0");
    code(HTree[i].rchild,newcode+"1");
}
void Huffman::CreateCodeTable()
{
    code(2*N-2,"");
}

//编码
string Huffman::Encode(char* s)       //s为原始数据，d为编码串
{
    string d;
    //统计频率
    int asci[128]={0};
    vector<int> times;
    vector<char> name;
    char* p = s;
    while(*p != '\0')
    {
        asci[(int)*p]++;
        p++;
    }
    for(int i=0;i<128;i++)
    {
        if(asci[i] != 0){
            times.push_back(asci[i]);
            name.push_back((char)i);
        }
    }
    CreateHTree(times,name);
    PrintTree();
    // //
    // for(int i=0;i<2*N-1;i++)
    // {
    //     cout<<HTree[i].weight<<HTree[i].lchild<<" "<<HTree[i].rchild<<endl;
    // }
    // //
    CreateCodeTable();
    //编码
    p = s;

    while(*p != '\0'){
        for(int i=0;i<N;i++){
            if(*p == HCodeTable[i].data){
                d += HCodeTable[i].code;
            }
        }
        p++;
    }
    return d;
}

//解码
string Huffman::Decode(char* s)
{
    char* p1=s;
    char* res=new char[1024];
    char* p2=res;
    while(*p1 !='\0')
    {
        int parent = 2*N - 2;
        while(HTree[parent].lchild != -1){
            if(*p1 == '0')
            {
                parent = HTree[parent].lchild;
            }
            else
            {
                parent = HTree[parent].rchild;
            }
            p1++;
        }
        *p2 = HCodeTable[parent].data;
        p2++;
    }
    *p2='\0';
    string d(res);
    delete[] res;
    return d;
}

//析构函数
Huffman::~Huffman()
{
    delete[] HTree;
    delete[] HCodeTable;
}

int main()
{
    string input;
    cout<<"请输入原始数据:"<<endl;
    std::getline(std::cin, input); 
    char* buffer = new char[input.length() + 1];
    strcpy(buffer, input.c_str());
    
    Huffman exaTree;
    string exa_encode_s = exaTree.Encode(buffer);
    cout<<"编码后的数据:"<<exa_encode_s<<endl;
    char* exa_encode_c = new char[exa_encode_s.length() + 1];
    strcpy(exa_encode_c, exa_encode_s.c_str());

    cout<<"编码后再解码结果为:";
    string exa_decode_s=exaTree.Decode(exa_encode_c);
    cout<<exa_decode_s<<endl;

    delete[] buffer; // 释放内存
    delete[] exa_encode_c; // 释放内存
    return 0;
}