#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node class
class Node
{
public:
    int data;
    vector<Node*> children;

    Node(int val)
    {
        data = val;
    }
};

// Preorder Traversal
void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";

    for(Node* child : root->children)
    {
        preorder(child);
    }
}



int main()
{
    // Creating Nodes
    Node* root = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    // Building Tree
    root->children.push_back(n2);
    root->children.push_back(n3);
    root->children.push_back(n4);

    n2->children.push_back(n5);
    n2->children.push_back(n6);

    n4->children.push_back(n7);
    n4->children.push_back(n8);

    // Display Traversals
    cout << "Preorder Traversal : ";
    preorder(root);



    return 0;
}
