#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next =NULL;
    }
};

Node* reversell(Node* head)
{
    Node* prev=NULL;
    Node* curr=head;
    Node* nxt=NULL;

    while (curr !=NULL)
    {
        nxt=curr->next;
        curr->next=prev;

        prev=curr;
        curr=nxt;
    }
    return prev;
}

void linklistTraversal(Node* head)
{
    while(head !=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;  

    linklistTraversal(head);

    Node* rev =reversell(head);
    linklistTraversal(rev);

    return 0;
}