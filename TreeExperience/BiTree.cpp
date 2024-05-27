#include<iostream>
#include<queue>
using namespace std;

template<class T>class BiNode
{
public:
    T data;
    BiNode<T>* lchild;
    BiNode<T>* rchild;
};

template<class T>class BiTree
{
private:
    void Creat(BiNode<T>* &R,T data[],int i);
    void Release(BiNode<T>* R);
public:
    BiNode<T>* root;
    BiTree(T data[], int size);
    void PreOrder(BiNode<T>* R);
    void InOrder(BiNode<T>* R);
    void PostOrder(BiNode<T>* R);
    void LevelOrder(BiNode<T>* R);
    int TreeDepth(BiNode<T>* root);
    bool Path(BiNode<T>* R,T target,vector<T>& path);
    void FindPath(BiNode<T>* R,T target,vector<T>& path);
    ~BiTree();
};

template<class T>
BiTree<T>::BiTree(T data[], int size) {
    if (size == 0) {
        root = nullptr;
        return;
    }

    // 创建根节点
    root = new BiNode<T>;
    root->data = data[0];
    root->lchild = root->rchild = nullptr;

    queue<BiNode<T>*> q;
    q.push(root);
    int i = 1; // 数组索引

    while (!q.empty() && i < size) {
        BiNode<T>* node = q.front();
        q.pop();

        // 添加左子节点
        if (data[i] != 0 && i < size) {
            node->lchild = new BiNode<T>;
            node->lchild->data = data[i++];
            node->lchild->lchild = node->lchild->rchild = nullptr;
            q.push(node->lchild);
        }
        else {
            node->lchild = nullptr;
            i++;
        }

        // 添加右子节点
        if (data[i] != 0 && i < size) {
            node->rchild = new BiNode<T>;
            node->rchild->data = data[i++];
            node->rchild->lchild = node->rchild->rchild = nullptr;
            q.push(node->rchild);
        }
        else {
            node->rchild = nullptr;
            i++;
        }
    }
}

template<class T>
void BiTree<T>::Release(BiNode<T>* R)
{
    if(R!= NULL)
    {
        Release(R->lchild);
        Release(R->rchild);
        delete R;
    }
}

template<class T>
BiTree<T>::~BiTree()
{
    Release(root);
}

//遍历栈的结点
template<class T>class SNode
{
public:
    BiNode<T>* R;
    int tag;
};

//前序遍历
template<class T>
void BiTree<T>::PreOrder(BiNode<T>* R)
{
    BiNode<T>* S[100];               //初始化栈
    int top = -1;
    while((top!=-1)||(R!=NULL))
    {
        if(R!=NULL)
        {
            cout<<R->data;
            S[++top]=R;
            R=R->lchild;
        }
        else
        {
            R=S[top--];
            R=R->rchild;
        }
    }
}

//中序遍历
template<class T>
void BiTree<T>::InOrder(BiNode<T>* R)
{
    if(R!=NULL)
    {
        InOrder(R->lchild);
        cout<<R->data;
        InOrder(R->rchild);
    }
}

//后序遍历
template<class T>
void BiTree<T>::PostOrder(BiNode<T>* R)
{
    if(R!=NULL)
    {
        PostOrder(R->lchild);
        PostOrder(R->rchild);
        cout<<R->data;
    }
}

//层序遍历
template<class T>
void BiTree<T>::LevelOrder(BiNode<T>* R)
{
    BiNode<T>* queue[1024];
    int f=0,r=0;
    if(R!=NULL) queue[++r]=R;
    while(f!=r)
    {
        BiNode<T>* p=queue[++f];
        cout<<p->data;
        if(p->lchild!=NULL) queue[++r]=p->lchild;
        if(p->rchild!=NULL) queue[++r]=p->rchild;
    }
}

//树的深度
template<class T>
int BiTree<T>::TreeDepth(BiNode<T>* root) {
    if (root == nullptr)
        return 0;
    int left_depth = TreeDepth(root->lchild);
    int right_depth = TreeDepth(root->rchild);
    return max(left_depth, right_depth) + 1;
}

//查找路径
template<class T>
bool BiTree<T>::Path(BiNode<T>* root,T target,vector<T>& path)
{
    if(root == NULL) return false;
    path.push_back(root->data);
    if(root->data==target) return true;
    if(Path(root->lchild,target,path)||Path(root->rchild,target,path)) return true;
    path.pop_back();
    return false;
}

template<class T>
void BiTree<T>::FindPath(BiNode<T>* R,T target,vector<T>& path) {
    Path(root,target,path);
    for (auto it = path.begin(); it != path.end(); ++it) {
        cout << *it;
        if (it + 1 != path.end())
            cout << " -> ";
    }
    cout << endl;
}

int main()
{
    int arr[10]={1,2,3,4,5,6,0,0,7,0};
    BiTree<int> exaTree(arr,10);
    cout<<"前序遍历:";
    exaTree.PreOrder(exaTree.root);
    cout<<endl<<"中序遍历:";
    exaTree.InOrder(exaTree.root);
    cout<<endl<<"后序遍历:";
    exaTree.PostOrder(exaTree.root);
    cout<<endl<<"层序遍历:";
    exaTree.LevelOrder(exaTree.root);
    cout<<endl<<"该二叉树的深度为:";
    cout<<exaTree.TreeDepth(exaTree.root);
    cout<<endl<<"该二叉树中从根到5的路径为:";
    vector<int> path;
    exaTree.FindPath(exaTree.root,5,path);

    return 0;
}