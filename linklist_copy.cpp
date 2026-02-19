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


   

Node *copylist(Node* head)
{

    Node* newhead=new Node(head->data);
    Node* p=newhead;
    Node* temp=head->next;

    while(temp !=NULL)
    {
        p->next=new Node(temp->data);
        p=p->next;
        temp=temp->next;
    }
    return newhead;
}


int main()
{  
    Node* head =new Node(10);

    head=insertAtEnd(head,20);
    head=insertAtEnd(head,30);
    head=insertAtEnd(head,40);

    cout<<"linklist simple"<<endl;
    linklistTraversal(head);

    Node* newhead=copylist(head);
    cout<<endl<<"linklist copy"<<endl;
    linklistTraversal(newhead);
    cout<<endl;


    return 0;
}