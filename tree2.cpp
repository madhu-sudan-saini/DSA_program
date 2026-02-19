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

// hight of tree
int hight(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=hight(root->left);
    int right=hight(root->right);
    return max(left,right)+1;
    
}
// count node
int count_node(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=count_node(root->left);
    int right=count_node(root->right);
    return (left+right+1);
}

// sum of node value
int sum(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int left=sum(root->left);
    int right=sum(root->right);
    return (left+right)+root->data;
}


// diameter of tree
int diameter(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

     int left_diameter=diameter(root->left);
     int right_diameter=diameter(root->right);
     int curr_diameter=hight(root->left)+hight(root->right);
     return max(curr_diameter,max(left_diameter,right_diameter));

}

//kth level tree
void KthlevelTree(Node* root,int k)
{
    if(root==NULL)
    {
        return;
    }

    if(k==1)
    {
        cout<<"kth level element is :"<<root->data<<endl;
        return ;
    }
    KthlevelTree(root->left,k-1);
    KthlevelTree(root->right,k-1);

}
int main()
{
    vector<int> preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root=builtTree(preorder);
 
    cout<<"preorder :";
    preOrder(root);
    cout<<endl;

    cout<<"hight of tree :"<<hight(root)<<endl;

    cout<<"total node is :"<<count_node(root)<<endl;

    cout<<"sum of all node value is :"<<sum(root)<<endl;

    cout<<"diameter of tree is :"<<diameter(root)<<endl;

    KthlevelTree(root,3);

}