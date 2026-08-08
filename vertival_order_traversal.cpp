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

void verticalorderTraversal(Node* root)
{
    queue<pair<Node* ,int>> q;
    map<int,vector<int>> m;

    vector<int> ans;

    q.push({root,0});

    while(!q.empty())
    {
        Node* curr=q.front().first;
        int hd=q.front().second;
        q.pop();

        ans.push_back(curr->data);

        if(curr->left !=NULL)
        {
            q.push({curr->left,hd-1});
        }

        if(curr->right !=NULL)
        {
            q.push({curr->right,hd+1});
        }
    }

    cout << "vertical order traversal : ";

    for(auto val : ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
}
int main()
{
    vector<int> Preorder={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root=builtTree(Preorder);

  verticalorderTraversal(root);

    return 0;
}
