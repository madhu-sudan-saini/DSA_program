#include <iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insertNode(Node* root,int val)
{
    if(root==NULL)
    {
        return new Node(val);
        return root;
    }

    if( root->data > val)
    {
        root->left=insertNode(root->left,val);
    }
    else
    {
        root->right=insertNode(root->right,val);
    }
    return root;
}

Node* builtTree(vector<int> arr)
{
    Node* root=NULL;
    for(int val :arr)
    {
        root=insertNode(root,val);
    }
    return root;
}

void inOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

bool serach(Node* root, int key)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }
    else if (root->data > key)
    {
        return serach(root->left, key);
    }
    else
    {
        return serach(root->right, key);
    }
}

Node* findmin(Node* root)
{
    while(root->left !=NULL)
    {
        root=root->left;
    }
    return root;
}
Node* deleteBst(Node* root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data > key)
    {
        root->left=deleteBst(root->left,key);
    }
    else if(root->data < key)
    {
        root->right=deleteBst(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            Node* temp =root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }
    }

    Node* temp=findmin(root->right);
    root->data=temp->data;
    root->right=deleteBst(root->right,temp->data);
    return root;
}

int main() {

    vector<int> arr={3,2,1,5,6,4};

    Node* root=builtTree(arr);

    inOrder(root);

    cout<<endl;

    cout<<"element is found or not :"<<serach(root,14)<<endl;

    root=deleteBst(root,3);
    inOrder(root);
    return 0;
}
