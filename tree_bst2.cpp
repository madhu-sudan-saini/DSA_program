#include <iostream>
using namespace std;

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

/* INSERT */
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

/* INORDER TRAVERSAL */
void inOrder(Node* root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

/* SEARCH */
bool search(Node* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

/* FIND MIN (VOID VERSION) */
void findmin(Node* root, Node*& minNode)
{
    while (root->left != NULL)
        root = root->left;

    minNode = root;
}

/* DELETE NODE IN BST (VOID VERSION) */
void deleteBst(Node*& root, int key)
{
    if (root == NULL)
        return;

    if (key < root->data)
    {
        deleteBst(root->left, key);
    }
    else if (key > root->data)
    {
        deleteBst(root->right, key);
    }
    else
    {
        // Case 1: No left child
        if (root->left == NULL)
        {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        // Case 2: No right child
        else if (root->right == NULL)
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        // Case 3: Two children
        else
        {
            Node* temp;
            findmin(root->right, temp);
            root->data = temp->data;
            deleteBst(root->right, temp->data);
        }
    }
}

/* MAIN */
int main()
{
    Node* root = NULL;

    insertNode(root, 45);
    insertNode(root, 34);
    insertNode(root, 24);
    insertNode(root, 90);

    cout << "Inorder Traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Search 45: " << search(root, 45) << endl;

    deleteBst(root, 34);

    cout << "After Deletion: ";
    inOrder(root);
    cout << endl;

    return 0;
}
