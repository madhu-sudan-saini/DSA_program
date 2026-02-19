// #include <iostream>
// using namespace std;

// /* NODE */
// class Node
// {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val)
//     {
//         data = val;
//         left = right = NULL;
//     }
// };

// /* INSERT NODE (ROOT CREATE INSIDE, NO QUEUE/HEIGHT) */
// void insertNode(Node*& root, int val)
// {
//     if (root == NULL)
//     {
//         root = new Node(val);   // root create ho gaya yahan
//         return;
//     }

//     if (root->left == NULL)
//     {
//         root->left = new Node(val);
//     }
//     else if (root->right == NULL)
//     {
//         root->right = new Node(val);
//     }
//     else
//     {
//         insertNode(root->left, val);   // left subtree try karo
//         insertNode(root->right, val);  // phir right subtree
//     }
// }

// /* INORDER */
// void inOrder(Node* root)
// {
//     if (root == NULL)
//         return;

//     inOrder(root->left);
//     cout << root->data << " ";
//     inOrder(root->right);
// }

// /* PREORDER */
// void preOrder(Node* root)
// {
//     if (root == NULL)
//         return;

//     cout << root->data << " ";
//     preOrder(root->left);
//     preOrder(root->right);
// }

// /* POSTORDER */
// void postOrder(Node* root)
// {
//     if (root == NULL)
//         return;

//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->data << " ";
// }

// /* MAIN */
// int main()
// {
//     Node* root = NULL;  // root ko main me initialize NULL hi karenge

//     insertNode(root, 1);
//     insertNode(root, 2);
//     insertNode(root, 3);
//     insertNode(root, 4);
//     insertNode(root, 5);

//     cout << "Inorder Traversal: ";
//     inOrder(root);
//     cout << endl;

//     cout << "Preorder Traversal: ";
//     preOrder(root);
//     cout << endl;

//     cout << "Postorder Traversal: ";
//     postOrder(root);
//     cout << endl;

//     return 0;
// }



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

void InOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

void PostOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size()>0)
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

        cout<<curr->data<<" ";

        if(curr->left !=NULL)
        {
            q.push(curr->left);
        }

        if(curr->right !=NULL)
        {
            q.push(curr->right);
        }
    }
    cout<<endl;
}
int main()
{
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=builtTree(preorder);
    // cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;

    cout<<"preorder :";
    preOrder(root);
    cout<<endl;

    cout<<"Inorder :";
    InOrder(root);
    cout<<endl;

    cout<<"Postorder :";
    PostOrder(root);
    cout<<endl;

    cout<<"levelOrderTraversal :"<<endl;
    levelOrderTraversal(root);
    return 0;
}