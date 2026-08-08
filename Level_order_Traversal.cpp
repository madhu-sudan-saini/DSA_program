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


void levelorderTraversal(Node* root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();

        if(curr==NULL)
        {
            if(!q.empty())
            {
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            cout<<curr->data<<" ";
        }

        if(curr->left !=NULL)
        {
            q.push(curr->left);
        }

        if(curr->right !=NULL)
        {
            q.push(curr->right);
        }
    }
}

int main()
{
    vector<int> Preorder={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root=builtTree(Preorder);

    cout<<"level order traversal :"<<endl;
    levelorderTraversal(root);
    cout<<endl;

    return 0;
}
