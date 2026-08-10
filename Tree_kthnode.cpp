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


void kthlevelTree(Node* root,int k)
{
    if(root==NULL)
    {
        return;
    }

    if(k==1)
    {
        cout<<"kth level element :"<<root->data<<endl;
        return;
    }

    kthlevelTree(root->left,k-1);
    kthlevelTree(root->right,k-1);

}

int main()
{
    vector<int> Preorder={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root=builtTree(Preorder);

  
      kthlevelTree(root,2);
  
    return 0;
}
