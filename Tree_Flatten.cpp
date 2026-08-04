#include<iostream>
#include<vector>
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
        left=right=NULL;
    }
};

static int idx=-1;
Node* builtTree(vector<int> &preOrde)
{
    idx++;
    if(idx >=  preOrde.size() || preOrde[idx]==-1)
    {
        return NULL;
    }

    Node* root=new Node(preOrde[idx]);
    root->left=builtTree(preOrde);
    root->right=builtTree(preOrde);

    return root;
}

void printFlattenTree(Node* root)
{
    Node* current = root;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->right;
    }

    cout << endl;
}

Node* FlattenTree(Node* root)
{
    if(root==NULL)
    {
        return NULL;
    }

    Node* current=root;

    while(current !=NULL)
    {
        if(current->left !=NULL)
        {
            Node* prev=current->left;

            while(prev->right !=NULL)
            {
                prev=prev->right;
            }

            prev->right=current->right;
            current->right=current->left;
            current->left=NULL;
        }
        else
        {
            current=current->right;
        }
    }

    return root;
}
int main()
{
    vector<int> preOrde={1,2,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};

    Node* root=builtTree(preOrde);


    FlattenTree(root);

    cout<<"flatten tree  :";
    printFlattenTree(root);
    return 0;
}
