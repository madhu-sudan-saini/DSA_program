#include<iostream>
#include<vector>
#include<queue>


using namespace std;

class Node
{
    public:

    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};


static int idx= -1;
Node* builtTree(vector<int> &Preorder)
{
    idx++;

    if(idx >= Preorder.size() || Preorder[idx]==-1)
    {
        return NULL;
    }

    Node* root=new Node(Preorder[idx]);
    root->left=builtTree(Preorder);
    root->right=builtTree(Preorder);

    return root;
}

int hight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int left=hight(root->left);
    int right=hight(root->right);

    return max(left,right)+1;
}
int main()
{
    vector<int> Preorder={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root=builtTree(Preorder);


     cout<<"hight :"<<hight(root)<<endl;

    return 0;
}
