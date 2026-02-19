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

void linklistTraversal(Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL";
}

Node* insertAtEnd(Node* head,int data)
{
    Node* ptr=new Node(data);
    Node* p=head;

    while(p->next != NULL)
    {
        p=p->next;
    }

    ptr->next=NULL;
    p->next=ptr;
    return head;
}

Node* margelinklist(Node* head1,Node* head2)
{
    if(head1 == NULL)
    {
        return NULL;
    }
    if(head2 == NULL)
    {
        return NULL;
    }

    Node* p=head1;
    while(p->next !=NULL)
    {
        p=p->next;
    }
     p->next=head2;
     return head1;
}

int main()
{
    Node* head1=new Node(1);
    insertAtEnd(head1,2);
    insertAtEnd(head1,3);
    insertAtEnd(head1,4);
    insertAtEnd(head1,5);

    cout<<"linklist 1"<<endl;
    linklistTraversal(head1);
    cout<<endl;

    Node* head2=new Node(6);
    insertAtEnd(head2,7);
    insertAtEnd(head2,8);
    insertAtEnd(head2,9);
    insertAtEnd(head2,10);

    cout<<"linklist 2"<<endl;
    linklistTraversal(head2);
    cout<<endl;

    cout<<"marged linklist"<<endl;
    Node* newhead=margelinklist(head1,head2);
    linklistTraversal(newhead);
    cout<<endl;
}