#include<iostream>
#include<vector>
#include<queue>
#include<map>

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
void diagonalTraversal(Node* root)
{
    queue<Node*> q;

    q.push(root);

    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();


        while(curr != NULL)
        {
            cout<<curr->data<<" ";

            if(curr->left !=NULL)
            {
                q.push(curr->left);
            }

            curr=curr->right;
        }
    }
    cout<<endl;
}
int main()
{
    vector<int> Preorder={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root=builtTree(Preorder);

    cout<<"diagona traversal :";
    diagonalTraversal(root);

    return 0;
}
