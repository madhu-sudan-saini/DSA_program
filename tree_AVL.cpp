#include <iostream>
#include <vector>
using namespace std;

/* NODE */
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void insertNode(Node*& root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }

    if (val < root->data)
        insertNode(root->left, val);
    else
        insertNode(root->right, val);
}

void inorder(Node* root,vector<int>& arr)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
Node* buildAVLTree(vector<int>& arr, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildAVLTree(arr, start, mid - 1);
    root->right = buildAVLTree(arr, mid + 1, end);

    return root;
}
Node* convertBSTtoAVL(Node* root)
{
    vector<int> arr;
    inorder(root,arr);
    
    return buildAVLTree(arr, 0, arr.size() - 1);
}
void printInorder(Node* root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    Node* root = NULL;

    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 25);
    insertNode(root, 40);
    insertNode(root, 50);

    insertNode(root, 5);

    cout << "Inorder Traversal of Original BST: ";
    printInorder(root);
    cout << endl;

    Node* avlRoot = convertBSTtoAVL(root);

    cout << "Inorder Traversal of Converted AVL Tree: ";
    printInorder(avlRoot);
    cout << endl;

    return 0;
}
