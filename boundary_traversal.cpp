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
void leftBoundary(Node *root)
{
    Node *curr = root->left;

    while (curr != NULL)
    {
        // Skip leaf nodes
        if (curr->left != NULL || curr->right != NULL)
            cout << curr->data << " ";

        if (curr->left != NULL)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

// Print Leaf Nodes
void leafNodes(Node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    leafNodes(root->left);
    leafNodes(root->right);
}

// Right Boundary
void rightBoundary(Node *root)
{
    vector<int> ans;

    Node *curr = root->right;

    while (curr != NULL)
    {
        // Skip leaf nodes
        if (curr->left != NULL || curr->right != NULL)
            ans.push_back(curr->data);

        if (curr->right != NULL)
            curr = curr->right;
        else
            curr = curr->left;
    }

    // Print in reverse order
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
}

// Boundary Traversal
void boundaryTraversal(Node *root)
{
    if (root == NULL)
        return;

    // Print root
    cout << root->data << " ";

    // If only one node
    if (root->left == NULL && root->right == NULL)
    {
        cout << endl;
        return;
    }

    leftBoundary(root);

    leafNodes(root);

    rightBoundary(root);

    cout<<endl;
}
int main()
{
    vector<int> Preorder={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,7,-1,-1};

    Node* root=builtTree(Preorder);


    cout<<"boundary Traversal:";
    boundaryTraversal(root);
    cout<<endl;

    return 0;
}
