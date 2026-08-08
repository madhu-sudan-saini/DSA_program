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
void zigzagTraversal(Node* root)
{
    if(root == NULL)
        return;

    stack<Node*> s1;   // Left to Right
    stack<Node*> s2;   // Right to Left

    s1.push(root);

    while(!s1.empty() || !s2.empty())
    {
        // Left to Right
        while(!s1.empty())
        {
            Node* curr = s1.top();
            s1.pop();

            cout << curr->data << " ";

            if(curr->left != NULL)
                s2.push(curr->left);

            if(curr->right != NULL)
                s2.push(curr->right);
        }

        // Right to Left
        while(!s2.empty())
        {
            Node* curr = s2.top();
            s2.pop();

            cout << curr->data << " ";

            if(curr->right != NULL)
                s1.push(curr->right);

            if(curr->left != NULL)
                s1.push(curr->left);
        }
    }

    cout << endl;
}

int main()
{
    vector<int> Preorder={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root=builtTree(Preorder);


    cout<<"zig zag traversal :";
    zigzagTraversal(root);

    return 0;
}
