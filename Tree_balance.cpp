#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
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

bool isbalance(Node* root)
{
    if(root==NULL)
    {
        return false;
    }

    bool checkleft=isbalance(root->left);
    bool checkright=isbalance(root->right);
    bool diffrence = abs(hight(root->left) - hight(root->right)) <= 1;

    if(checkleft && checkright && diffrence)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    vector<int> Preorder={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root=builtTree(Preorder);

    cout<<"balance or not :"<<isbalance(root)<<endl;

    return 0;
}
