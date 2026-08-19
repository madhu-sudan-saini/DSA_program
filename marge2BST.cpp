#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:

    int val;
    Node* left;
    Node* right;

    Node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST
Node* insertNode(Node* root, int key)
{
    if(root == NULL)
        return new Node(key);

    if(key < root->val)
        root->left = insertNode(root->left, key);

    else if(key > root->val)
        root->right = insertNode(root->right, key);

    return root;
}

// Build BST from array
Node* BuiltBST(vector<int> arr)
{
    Node* root = NULL;

    for(int val : arr)
    {
        root = insertNode(root, val);
    }

    return root;
}

// Inorder traversal
void inorde(Node* root, vector<int>& arr)
{
    if(root == NULL)
        return;

    inorde(root->left, arr);

    arr.push_back(root->val);

    inorde(root->right, arr);
}

// Merge two BSTs
Node* marge2BST(Node* root1, Node* root2)
{
    vector<int> arr1, arr2;

    // Get inorder of both BSTs
    inorde(root1, arr1);
    inorde(root2, arr2);

    vector<int> temp;

    int i = 0;
    int j = 0;

    // Merge two sorted arrays
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
        {
            temp.push_back(arr1[i]);
            i++;
        }
        else
        {
            temp.push_back(arr2[j]);
            j++;
        }
    }

    // Remaining elements of arr1
    while(i < arr1.size())
    {
        temp.push_back(arr1[i]);
        i++;
    }

    // Remaining elements of arr2
    while(j < arr2.size())
    {
        temp.push_back(arr2[j]);
        j++;
    }

    // Build BST from merged array
    return BuiltBST(temp);
}

int main()
{
    vector<int> arr1 = {8, 2, 1, 10};
    vector<int> arr2 = {5, 3, 0};

    Node* root1 = BuiltBST(arr1);
    Node* root2 = BuiltBST(arr2);

    Node* root = marge2BST(root1, root2);

    vector<int> seq;

    inorde(root, seq);

    for(int val : seq)
    {
        cout << val << " ";
    }

    cout << endl;

    return 0;
}
