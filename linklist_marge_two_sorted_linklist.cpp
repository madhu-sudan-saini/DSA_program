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
        next=NULL;
    }
};

Node* margeLinklist(Node* head1,Node* head2)
{
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    if(head1->data < head2->data)
    {
        head1->next=margeLinklist(head1->next,head2);
        return head1;
    }
    else
    {
        head2->next=margeLinklist(head1,head2->next);
        return head2;
    }
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
    Node* head1=new Node(10);
    head1->next=new Node(20);
    head1->next->next=new Node(30);

    Node* head2=new Node(15);
    head2->next=new Node(21);
    head2->next->next=new Node(28);

    Node* marged=margeLinklist(head1,head2);

    linklistTraversal(marged);
    return 0;
}