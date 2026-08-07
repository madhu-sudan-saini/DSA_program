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

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

static int idx=-1;
Node* builtTree(vector<int>& preorder)
{
    idx++;
    if(preorder[idx]==-1)
    {
        return NULL;
    }
    Node* root=new Node(preorder[idx]);
    root->left = builtTree(preorder);
    root->right = builtTree(preorder);

    return root;
}

void preOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


int main()
{
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=builtTree(preorder);
 
    cout<<"preorder :";
    preOrder(root);
    cout<<endl;


    KthlevelTree(root,3);

}
